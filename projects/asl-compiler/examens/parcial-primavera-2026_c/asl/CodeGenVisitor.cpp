//////////////////////////////////////////////////////////////////////
//
//    CodeGenVisitor - Walk the parser tree to do
//                     the generation of code
//
//    Copyright (C) 2020-2030  Universitat Politecnica de Catalunya
//
//    This library is free software; you can redistribute it and/or
//    modify it under the terms of the GNU General Public License
//    as published by the Free Software Foundation; either version 3
//    of the License, or (at your option) any later version.
//
//    This library is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
//    Affero General Public License for more details.
//
//    You should have received a copy of the GNU Affero General Public
//    License along with this library; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
//
//    contact: José Miguel Rivero (rivero@cs.upc.edu)
//             Computer Science Department
//             Universitat Politecnica de Catalunya
//             despatx Omega.110 - Campus Nord UPC
//             08034 Barcelona.  SPAIN
//
//////////////////////////////////////////////////////////////////////

#include "CodeGenVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/code.h"

#include <string>
#include <cstddef> // std::size_t

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;

// Constructor
CodeGenVisitor::CodeGenVisitor(TypesMgr &Types,
                               SymTable &Symbols,
                               TreeDecoration &Decorations) : Types{Types},
                                                              Symbols{Symbols},
                                                              Decorations{Decorations}
{
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId CodeGenVisitor::getCurrentFunctionTy() const
{
    return currFunctionType;
}

void CodeGenVisitor::setCurrentFunctionTy(TypesMgr::TypeId type)
{
    currFunctionType = type;
}

// Methods to visit each kind of node:
//
std::any CodeGenVisitor::visitProgram(AslParser::ProgramContext *ctx)
{
    DEBUG_ENTER();
    code my_code;
    SymTable::ScopeId sc = getScopeDecor(ctx);
    Symbols.pushThisScope(sc);
    for (auto ctxFunc : ctx->function())
    {
        subroutine subr = std::any_cast<subroutine>(visit(ctxFunc));
        my_code.add_subroutine(subr);
    }
    Symbols.popScope();
    DEBUG_EXIT();
    return my_code;
}

std::any CodeGenVisitor::visitFunction(AslParser::FunctionContext *ctx)
{
    DEBUG_ENTER();

    SymTable::ScopeId sc = getScopeDecor(ctx);
    Symbols.pushThisScope(sc);

    TypesMgr::TypeId t_ret = Types.createVoidTy();
    if (ctx->type()) t_ret = getTypeDecor(ctx->type());
    setCurrentFunctionTy(t_ret);

    subroutine subr(ctx->ID()->getText());
    codeCounters.reset();

    if (ctx->type())
    {
        TypesMgr::TypeId t_ret = getTypeDecor(ctx->type());
        std::string t_ret_str = Types.to_string_basic(t_ret);

        subr.add_param("_result", t_ret_str);
    }

    if (ctx->params())
    {
        std::vector<var> &&lparams = std::any_cast<std::vector<var>>(visit(ctx->params()));
        for (const auto &oneparam : lparams)
        {
            TypesMgr::TypeId t_param = Symbols.getType(oneparam.name);

            if (Types.isArrayTy(t_param)) subr.add_param(oneparam.name, oneparam.type, true);
            else subr.add_param(oneparam.name, oneparam.type);
        }
    }

    std::vector<var> &&lvars = std::any_cast<std::vector<var>>(visit(ctx->declarations()));
    for (auto &onevar : lvars)
    {
        subr.add_var(onevar);
    }

    instructionList &&code = std::any_cast<instructionList>(visit(ctx->statements()));
    if (not ctx->type()) code = code || instruction(instruction::RETURN());
    subr.set_instructions(code);

    Symbols.popScope();

    DEBUG_EXIT();
    return subr;
}

std::any CodeGenVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx)
{
    DEBUG_ENTER();
    std::vector<var> lvars;
    for (auto &varDeclCtx : ctx->variable_decl())
    {
        std::vector<var> &&lvars_aux = std::any_cast<std::vector<var>>(visit(varDeclCtx));
        lvars.insert(lvars.end(), lvars_aux.begin(), lvars_aux.end());
    }
    DEBUG_EXIT();
    return lvars;
}

std::any CodeGenVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId type = getTypeDecor(ctx->type());
    std::size_t size = Types.getSizeOfType(type);

    if (Types.isArrayTy(type))
    {
        type = Types.getArrayElemType(type);
    }

    std::vector<var> lvars;
    for (const auto &id : ctx->ID())
    {
        lvars.push_back(var{id->getText(), Types.to_string(type), size});
    }

    DEBUG_EXIT();
    return lvars;
}

std::any CodeGenVisitor::visitStatements(AslParser::StatementsContext *ctx)
{
    DEBUG_ENTER();
    instructionList code;
    for (auto stCtx : ctx->statement())
    {
        instructionList &&codeS = std::any_cast<instructionList>(visit(stCtx));
        code = code || codeS;
    }
    DEBUG_EXIT();
    return code;
}

std::any CodeGenVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx)
{
    DEBUG_ENTER();

    instructionList code;
    CodeAttribs &&codAtsE1 = std::any_cast<CodeAttribs>(visit(ctx->left_expr()));
    std::string addr1 = codAtsE1.addr;
    std::string offs1 = codAtsE1.offs;
    instructionList &code1 = codAtsE1.code;
    TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

    CodeAttribs &&codAtsE2 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    std::string addr2 = codAtsE2.addr;
    // std::string           offs2 = codAtsE2.offs;
    instructionList &code2 = codAtsE2.code;
    TypesMgr::TypeId tid2 = getTypeDecor(ctx->expr());

    code = code1 || code2;

    if (Types.isFloatTy(tid1) and Types.isIntegerTy(tid2))
    {
        std::string temp = "%" + codeCounters.newTEMP();
        code = code || instruction::FLOAT(temp, addr2);
        addr2 = temp;
    }

    if (Types.isArrayTy(tid1) and Types.isArrayTy(tid2))
    {
        std::string tmp1 = "%" + codeCounters.newTEMP();
        std::string tmp2 = "%" + codeCounters.newTEMP();
        std::string tmp3 = "%" + codeCounters.newTEMP();
        std::string tmp4 = "%" + codeCounters.newTEMP();                 
        std::string size = std::to_string(Types.getArraySize(tid1));

        std::string label1 = codeCounters.newLabelWHILE();
        std::string label2 = codeCounters.newLabelWHILE();
        std::string label_while = "while" + label1;
        std::string label_end_while = "endwhile" + label2;

        instructionList while_ini =  instruction::ILOAD(tmp1, "0")          ||
                                     instruction::ILOAD(tmp2, size); 

        instructionList while_cond = instruction::LT(tmp3, tmp1, tmp2);

        instructionList while_body = instruction::LOADX(tmp4, addr2, tmp1)  ||
                                     instruction::XLOAD(addr1, tmp1, tmp4)  ||
                                     instruction::ADD(tmp1, tmp1, "1");
        
        code = code || while_ini                                            ||
                       instruction::LABEL(label_while)                      ||
                       while_cond                                           ||
                       instruction::FJUMP(tmp3, label_end_while)            ||
                       while_body                                           ||
                       instruction::UJUMP(label_while)                      ||
                       instruction::LABEL(label_end_while);
    }
    else if (not offs1.empty()) code = code || instruction::XLOAD(addr1, offs1, addr2);
    else code = code || instruction::LOAD(addr1, addr2);

    DEBUG_EXIT();
    return code;
}

std::any CodeGenVisitor::visitIfStmt(AslParser::IfStmtContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats_expr = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    std::string addr1 = code_ats_expr.addr;
    instructionList &code1 = code_ats_expr.code;

    instructionList &&code2 = std::any_cast<instructionList>(visit(ctx->statements(0)));
    std::string label1 = codeCounters.newLabelIF();
    std::string label_end_if = "endif" + label1;

    instructionList &&code = code1                                   || 
                             instruction::FJUMP(addr1, label_end_if) ||
                             code2                                   || 
                             instruction::LABEL(label_end_if);

    if (ctx->ELSE())
    {
        instructionList &&code3 = std::any_cast<instructionList>(visit(ctx->statements(1)));
        std::string label2 = codeCounters.newLabelIF();
        std::string label_else = "else" + label2;

        code = code1                                 || 
               instruction::FJUMP(addr1, label_else) ||
               code2                                 ||
               instruction::UJUMP(label_end_if)      ||
               instruction::LABEL(label_else)        ||
               code3                                 ||
               instruction::LABEL(label_end_if);
    }

    DEBUG_EXIT();
    return code;
}

std::any CodeGenVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats_expr = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    std::string addr1 = code_ats_expr.addr;
    instructionList &code1 = code_ats_expr.code;

    instructionList &&code2 = std::any_cast<instructionList>(visit(ctx->statements()));
    
    std::string label1 = codeCounters.newLabelWHILE();
    std::string label2 = codeCounters.newLabelWHILE();
    std::string label_while = "while" + label1;
    std::string label_end_while = "endwhile" + label2;

    instructionList &&code = instruction::LABEL(label_while)            ||
                             code1                                      ||
                             instruction::FJUMP(addr1, label_end_while) ||
                             code2                                      ||
                             instruction::UJUMP(label_while)            ||
                             instruction::LABEL(label_end_while);

    DEBUG_EXIT();
    return code;
}

std::any CodeGenVisitor::visitProcCallStmt(AslParser::ProcCallStmtContext *ctx)
{
    DEBUG_ENTER();
    
    CodeAttribs code_ats = std::any_cast<CodeAttribs>(visit(ctx->proc_call()));
    instructionList &code = code_ats.code;
    
    DEBUG_EXIT();
    return code;
}

std::any CodeGenVisitor::visitProcCall(AslParser::ProcCallContext *ctx)
{
    DEBUG_ENTER();

    std::string name = ctx->ident()->getText();
    TypesMgr::TypeId t_proc = Symbols.getGlobalFunctionType(name);

    instructionList code;

    if (not Types.isVoidFunction(t_proc))
    {
        code = code || instruction::PUSH();
    }

    for (unsigned int i = 0; i < ctx->expr().size(); ++i)
    {
        CodeAttribs &&codats_expr = std::any_cast<CodeAttribs>(visit(ctx->expr(i)));
        std::string addr_expr = codats_expr.addr;
        code = code || codats_expr.code;                     
               
        TypesMgr::TypeId t_param = Types.getParameterType(t_proc, i);
        TypesMgr::TypeId t_expr = getTypeDecor(ctx->expr(i));

        if (Types.isIntegerTy(t_expr) and Types.isFloatTy(t_param))
        {
            std::string temp = "%" + codeCounters.newTEMP();
            code = code || instruction::FLOAT(temp, codats_expr.addr);
            addr_expr = temp;
        }

        if (Types.isArrayTy(t_param) and Symbols.findInCurrentScope(addr_expr))
        {
            std::string temp = "%" + codeCounters.newTEMP();
            code = code || instruction::ALOAD(temp, codats_expr.addr);
            addr_expr = temp;
        }

        code = code || instruction::PUSH(addr_expr);
    }

    code = code || instruction::CALL(name);

    for (unsigned int i = 0; i < ctx->expr().size(); ++i)
    {
        code = code || instruction::POP();
    }

    std::string res;
    if (not Types.isVoidFunction(t_proc))
    {
        res = "%" + codeCounters.newTEMP();
        code = code || instruction::POP(res);
    }

    CodeAttribs code_ats(res, "", code);

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats_expr = std::any_cast<CodeAttribs>(visit(ctx->left_expr()));
    std::string addr1 = code_ats_expr.addr;
    std::string offs1 = code_ats_expr.offs;
    instructionList &code1 = code_ats_expr.code;
    instructionList &code = code1;
    
    TypesMgr::TypeId tid1 = getTypeDecor(ctx->left_expr());

    std::string temp = addr1;

    if (not offs1.empty())
    {
        temp = "%" + codeCounters.newTEMP();
    }

    if (Types.isFloatTy(tid1)) code = code || instruction::READF(temp);
    else if (Types.isCharacterTy(tid1)) code = code || instruction::READC(temp);
    else code = code || instruction::READI(temp);

    if (not offs1.empty())
    {
        code = code || instruction::XLOAD(addr1, offs1, temp);
    }

    DEBUG_EXIT();
    return code;
}

std::any CodeGenVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats1 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    std::string addr1 = code_ats1.addr;
    // std::string         offs1 = code_ats1.offs;
    instructionList &code1 = code_ats1.code;
    instructionList &code = code1;
    
    TypesMgr::TypeId t_expr = getTypeDecor(ctx->expr());
    
    if (Types.isFloatTy(t_expr)) code = code1 || instruction::WRITEF(addr1);
    else if (Types.isCharacterTy(t_expr)) code = code1 || instruction::WRITEC(addr1);
    else code = code1 || instruction::WRITEI(addr1);

    DEBUG_EXIT();
    return code;
}

/*
std::any CodeGenVisitor::visitWriteString(AslParser::WriteStringContext *ctx)
{
    DEBUG_ENTER();
    instructionList code;
    std::string s = ctx->STRING()->getText();
    code = code || instruction::WRITES(s);
    DEBUG_EXIT();
    return code;
}
*/

std::any CodeGenVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx)
{
    DEBUG_ENTER();

    instructionList code;

    if (ctx->expr())
    {
        CodeAttribs code_ats = std::any_cast<CodeAttribs>(visit(ctx->expr()));
        std::string result = code_ats.addr;
        code = code_ats.code;

        TypesMgr::TypeId t_ret = getCurrentFunctionTy();
        TypesMgr::TypeId t_expr = getTypeDecor(ctx->expr());

        if (Types.isFloatTy(t_ret) and Types.isIntegerTy(t_expr))
        {
            std::string temp = "%" + codeCounters.newTEMP();
            code = code || instruction::FLOAT(temp, result);
            result = temp;
        }

        code = code || instruction::LOAD("_result", result);
    }

    code = code || instruction::RETURN();

    DEBUG_EXIT();
    return code;
}

std::any CodeGenVisitor::visitLexprIdent(AslParser::LexprIdentContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats = std::any_cast<CodeAttribs>(visit(ctx->ident()));

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitLexprArrayAccess(AslParser::LexprArrayAccessContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats = std::any_cast<CodeAttribs>(visit(ctx->array_access()));

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs code_ats = std::any_cast<CodeAttribs>(visit(ctx->expr()));

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitExprArrayAccess(AslParser::ExprArrayAccessContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs cats_array = std::any_cast<CodeAttribs>(visit(ctx->array_access()));
    
    std::string temp = "%" + codeCounters.newTEMP();
    instructionList code = cats_array.code || instruction::LOADX(temp, cats_array.addr, cats_array.offs);

    CodeAttribs code_ats(temp, "", code);

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitUnary(AslParser::UnaryContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats1 = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    std::string addr1 = code_ats1.addr;
    instructionList &code1 = code_ats1.code;

    TypesMgr::TypeId t_res = getTypeDecor(ctx);
    
    std::string temp = "%" + codeCounters.newTEMP();
    instructionList &code = code1;
    if (ctx->MINUS())
    {
        std::string temp = "%" + codeCounters.newTEMP();
        if (Types.isFloatTy(t_res)) code = code || instruction::FNEG(temp, addr1);
        else code = code || instruction::NEG(temp, addr1);
        addr1 = temp;
    }
    else if (ctx->NOT())
    {
        std::string temp = "%" + codeCounters.newTEMP();
        code = code || instruction::NOT(temp, addr1);
        addr1 = temp;
    }

    CodeAttribs code_ats(addr1, "", code);

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats1 = std::any_cast<CodeAttribs>(visit(ctx->expr(0)));
    std::string addr1 = code_ats1.addr;
    instructionList &code1 = code_ats1.code;

    CodeAttribs &&code_ats2 = std::any_cast<CodeAttribs>(visit(ctx->expr(1)));
    std::string addr2 = code_ats2.addr;
    instructionList &code2 = code_ats2.code;

    instructionList &&code = code1 || code2;

    TypesMgr::TypeId t_exp1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t_exp2 = getTypeDecor(ctx->expr(1));
    TypesMgr::TypeId t_res = getTypeDecor(ctx);

    if (Types.isFloatTy(t_res))
    {
        if (Types.isIntegerTy(t_exp1))
        {
            std::string aux = "%" + codeCounters.newTEMP();
            code = code || instruction::FLOAT(aux, addr1);
            addr1 = aux;
        }
        else if (Types.isIntegerTy(t_exp2))
        {
            std::string aux = "%" + codeCounters.newTEMP();
            code = code || instruction::FLOAT(aux, addr2);
            addr2 = aux;
        }
    }

    std::string temp = "%" + codeCounters.newTEMP();
    if (ctx->MUL())
    {
        if (Types.isFloatTy(t_res)) code = code || instruction::FMUL(temp, addr1, addr2);
        else code = code || instruction::MUL(temp, addr1, addr2);
    }
    else if (ctx->DIV())
    {
        if (Types.isFloatTy(t_res)) code = code || instruction::FDIV(temp, addr1, addr2);
        else code = code || instruction::DIV(temp, addr1, addr2);
    }
    else if (ctx->MOD())
    {
        std::string aux1 = "%" + codeCounters.newTEMP();
        std::string aux2 = "%" + codeCounters.newTEMP();

        code = code || instruction::DIV(aux1, addr1, addr2) ||
                       instruction::MUL(aux2, aux1, addr2)  ||
                       instruction::SUB(temp, addr1, aux2);
    }
    else if (ctx->PLUS())
    {
        if (Types.isFloatTy(t_res)) code = code || instruction::FADD(temp, addr1, addr2);
        else code = code || instruction::ADD(temp, addr1, addr2);
    }
    else // ctx->MINUS()
    {
        if (Types.isFloatTy(t_res)) code = code || instruction::FSUB(temp, addr1, addr2);
        else code = code || instruction::SUB(temp, addr1, addr2);
    }

    CodeAttribs code_ats(temp, "", code);

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitRelational(AslParser::RelationalContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats1 = std::any_cast<CodeAttribs>(visit(ctx->expr(0)));
    std::string addr1 = code_ats1.addr;
    instructionList &code1 = code_ats1.code;

    CodeAttribs &&code_ats2 = std::any_cast<CodeAttribs>(visit(ctx->expr(1)));
    std::string addr2 = code_ats2.addr;
    instructionList &code2 = code_ats2.code;

    instructionList &&code = code1 || code2;

    TypesMgr::TypeId t_exp1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t_exp2 = getTypeDecor(ctx->expr(1));

    bool is_float = Types.isFloatTy(t_exp1) or Types.isFloatTy(t_exp2);
    if (is_float)
    {
        if (Types.isIntegerTy(t_exp1))
        {
            std::string aux = "%" + codeCounters.newTEMP();
            code = code || instruction::FLOAT(aux, addr1);
            addr1 = aux;
        }
        else if (Types.isIntegerTy(t_exp2))
        {
            std::string aux = "%" + codeCounters.newTEMP();
            code = code || instruction::FLOAT(aux, addr2);
            addr2 = aux;
        }
    }

    std::string temp = "%" + codeCounters.newTEMP();
    if (ctx->EQ())
    {
        if (is_float) code = code || instruction::FEQ(temp, addr1, addr2);
        else code = code || instruction::EQ(temp, addr1, addr2);
    }
    else if (ctx->NEQ())
    {
        if (is_float) code = code || instruction::FEQ(temp, addr1, addr2);
        else code = code || instruction::EQ(temp, addr1, addr2);
        
        std::string aux = "%" + codeCounters.newTEMP();
        code = code || instruction::NOT(aux, temp);
        temp = aux;
    }
    else if (ctx->GT())
    {
        if (is_float) code = code || instruction::FLE(temp, addr1, addr2);
        else code = code || instruction::LE(temp, addr1, addr2);
        
        std::string aux = "%" + codeCounters.newTEMP();
        code = code || instruction::NOT(aux, temp);
        temp = aux;
    }
    else if (ctx->GEQ())
    {
        if (is_float) code = code || instruction::FLT(temp, addr1, addr2);
        else code = code || instruction::LT(temp, addr1, addr2);
        
        std::string aux = "%" + codeCounters.newTEMP();
        code = code || instruction::NOT(aux, temp);
        temp = aux;
    }
    else if (ctx->LEQ())
    {
        if (is_float) code = code || instruction::FLE(temp, addr1, addr2);
        else code = code || instruction::LE(temp, addr1, addr2);
    }
    else // ctx->LT()
    {
        if (is_float) code = code || instruction::FLT(temp, addr1, addr2);
        else code = code || instruction::LT(temp, addr1, addr2);
    }
    
    
    CodeAttribs code_ats(temp, "", code);

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitLogical(AslParser::LogicalContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats1 = std::any_cast<CodeAttribs>(visit(ctx->expr(0)));
    std::string addr1 = code_ats1.addr;
    instructionList &code1 = code_ats1.code;

    CodeAttribs &&code_ats2 = std::any_cast<CodeAttribs>(visit(ctx->expr(1)));
    std::string addr2 = code_ats2.addr;
    instructionList &code2 = code_ats2.code;

    instructionList &&code = code1 || code2;

    std::string temp = "%" + codeCounters.newTEMP();
    if (ctx->AND())
    {
        code = code || instruction::AND(temp, addr1, addr2);
    }
    else // ctx->OR()
    {
        code = code || instruction::OR(temp, addr1, addr2);
    }

    CodeAttribs code_ats(temp, "", code);

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitIntValue(AslParser::IntValueContext *ctx)
{
    DEBUG_ENTER();

    std::string temp = "%" + codeCounters.newTEMP();
    instructionList code = instruction::ILOAD(temp, ctx->INTVAL()->getText());
    CodeAttribs code_atts(temp, "", code);

    DEBUG_EXIT();
    return code_atts;
}

std::any CodeGenVisitor::visitBoolValue(AslParser::BoolValueContext *ctx)
{
    DEBUG_ENTER();

    std::string temp = "%" + codeCounters.newTEMP();
    instructionList code = instruction::ILOAD(temp, "0");
    if (ctx->BOOLVAL()->getText() == "true") code = instruction::ILOAD(temp, "1");
    CodeAttribs code_atts(temp, "", code);

    DEBUG_EXIT();
    return code_atts;
}

std::any CodeGenVisitor::visitFloatValue(AslParser::FloatValueContext *ctx)
{
    DEBUG_ENTER();

    std::string temp = "%" + codeCounters.newTEMP();
    instructionList code = instruction::FLOAD(temp, ctx->FLOATVAL()->getText());
    CodeAttribs code_atts(temp, "", code);

    DEBUG_EXIT();
    return code_atts;
}

std::any CodeGenVisitor::visitCharValue(AslParser::CharValueContext *ctx)
{
    DEBUG_ENTER();

    std::string temp = "%" + codeCounters.newTEMP();
    std::string char_val = ctx->CHARVAL()->getText();
    instructionList code = instruction::CHLOAD(temp, char_val.substr(1, char_val.length() - 2));
    CodeAttribs code_atts(temp, "", code);

    DEBUG_EXIT();
    return code_atts;
}

std::any CodeGenVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx)
{
    DEBUG_ENTER();
    CodeAttribs &&codAts = std::any_cast<CodeAttribs>(visit(ctx->ident()));
    DEBUG_EXIT();
    return codAts;
}

std::any CodeGenVisitor::visitProcCallExpr(AslParser::ProcCallExprContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs &&code_ats = std::any_cast<CodeAttribs>(visit(ctx->proc_call()));

    DEBUG_EXIT();
    return code_ats;
}



std::any CodeGenVisitor::visitIdent(AslParser::IdentContext *ctx)
{
    DEBUG_ENTER();

    std::string addr = ctx->ID()->getText();
    TypesMgr::TypeId t_addr = Symbols.getType(addr);
    instructionList code;

    if (Types.isArrayTy(t_addr) and Symbols.isParameterClass(addr))
    {
        std::string temp = "%" + codeCounters.newTEMP();
        code = code || instruction::LOAD(temp, addr);
        addr = temp;
    }

    CodeAttribs code_ats(addr, "", code);

    DEBUG_EXIT();
    return code_ats;
}

std::any CodeGenVisitor::visitParams(AslParser::ParamsContext *ctx)
{
    DEBUG_ENTER();

    std::vector<var> lparams;
    for (const auto &param_decl : ctx->param_decl())
    {
        var param = std::any_cast<var>(visit(param_decl));
        lparams.push_back(param);
    }

    DEBUG_EXIT();
    return lparams;
}

std::any CodeGenVisitor::visitParam_decl(AslParser::Param_declContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId t_param = getTypeDecor(ctx->type());

    std::string name = ctx->ID()->getText();
    std::string type = Types.to_string_basic(t_param);

    var param(name, type);

    DEBUG_EXIT();
    return param;
}

std::any CodeGenVisitor::visitArray_access(AslParser::Array_accessContext *ctx)
{
    DEBUG_ENTER();

    CodeAttribs cats_ident = std::any_cast<CodeAttribs>(visit(ctx->ident()));
    CodeAttribs cats_expr = std::any_cast<CodeAttribs>(visit(ctx->expr()));
    std::string addr = cats_ident.addr;
    instructionList code = cats_ident.code || cats_expr.code;
    
    CodeAttribs code_ats(addr, cats_expr.addr, code);

    DEBUG_EXIT();
    return code_ats;
}





// Getters for the necessary tree node atributes:
//   Scope and Type
SymTable::ScopeId CodeGenVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx) const
{
    return Decorations.getScope(ctx);
}
TypesMgr::TypeId CodeGenVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx) const
{
    return Decorations.getType(ctx);
}

// Constructors of the class CodeAttribs:
//
CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string &addr,
                                         const std::string &offs,
                                         instructionList &code) : addr{addr}, offs{offs}, code{code}
{
}

CodeGenVisitor::CodeAttribs::CodeAttribs(const std::string &addr,
                                         const std::string &offs,
                                         instructionList &&code) : addr{addr}, offs{offs}, code{code}
{
}
