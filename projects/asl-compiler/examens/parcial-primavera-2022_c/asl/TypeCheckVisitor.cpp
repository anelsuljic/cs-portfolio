//////////////////////////////////////////////////////////////////////
//
//    TypeCheckVisitor - Walk the parser tree to do the semantic
//                       typecheck for the Asl programming language
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

#include "TypeCheckVisitor.h"
#include "antlr4-runtime.h"

#include "../common/TypesMgr.h"
#include "../common/SymTable.h"
#include "../common/TreeDecoration.h"
#include "../common/SemErrors.h"

#include <iostream>
#include <string>
#include <cmath>

// uncomment the following line to enable debugging messages with DEBUG*
// #define DEBUG_BUILD
#include "../common/debug.h"

// using namespace std;

// Constructor
TypeCheckVisitor::TypeCheckVisitor(TypesMgr &Types,
                                   SymTable &Symbols,
                                   TreeDecoration &Decorations,
                                   SemErrors &Errors) : Types{Types},
                                                        Symbols{Symbols},
                                                        Decorations{Decorations},
                                                        Errors{Errors}
{
}

// Accessor/Mutator to the attribute currFunctionType
TypesMgr::TypeId TypeCheckVisitor::getCurrentFunctionTy() const
{
    return currFunctionType;
}

void TypeCheckVisitor::setCurrentFunctionTy(TypesMgr::TypeId type)
{
    currFunctionType = type;
}

// Methods to visit each kind of node:
//
std::any TypeCheckVisitor::visitProgram(AslParser::ProgramContext *ctx)
{
    DEBUG_ENTER();
    SymTable::ScopeId sc = getScopeDecor(ctx);
    Symbols.pushThisScope(sc);
    for (auto ctxFunc : ctx->function())
    {
        visit(ctxFunc);
    }
    if (Symbols.noMainProperlyDeclared())
        Errors.noMainProperlyDeclared(ctx);
    Symbols.popScope();
    Errors.print();
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitFunction(AslParser::FunctionContext *ctx)
{
    DEBUG_ENTER();

    SymTable::ScopeId sc = getScopeDecor(ctx);
    Symbols.pushThisScope(sc);
    
    TypesMgr::TypeId t_ret = Types.createVoidTy();
    if (ctx->type()) t_ret = getTypeDecor(ctx->type());
    setCurrentFunctionTy(t_ret);

    visit(ctx->statements());
    Symbols.popScope();

    DEBUG_EXIT();
    return 0;
}

// std::any TypeCheckVisitor::visitDeclarations(AslParser::DeclarationsContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// std::any TypeCheckVisitor::visitVariable_decl(AslParser::Variable_declContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

// std::any TypeCheckVisitor::visitType(AslParser::TypeContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

std::any TypeCheckVisitor::visitStatements(AslParser::StatementsContext *ctx)
{
    DEBUG_ENTER();
    visitChildren(ctx);
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitAssignStmt(AslParser::AssignStmtContext *ctx)
{
    DEBUG_ENTER();
    visit(ctx->left_expr());
    visit(ctx->expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr());
    if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
        (not Types.copyableTypes(t1, t2)))
        Errors.incompatibleAssignment(ctx->ASSIGN());
    if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
        Errors.nonReferenceableLeftExpr(ctx->left_expr());
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitIfStmt(AslParser::IfStmtContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    {
        Errors.booleanRequired(ctx);
    }

    for (const auto &stmts : ctx -> statements())
    {
        visit(stmts);
    }
    
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitWhileStmt(AslParser::WhileStmtContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    if ((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1)))
    {
        Errors.booleanRequired(ctx);
    }

    visit(ctx -> statements());

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitProcCallStmt(AslParser::ProcCallStmtContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->proc_call());

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitReadStmt(AslParser::ReadStmtContext *ctx)
{
    DEBUG_ENTER();
    visit(ctx->left_expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->left_expr());
    if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)) and
        (not Types.isFunctionTy(t1)))
        Errors.readWriteRequireBasic(ctx);
    if ((not Types.isErrorTy(t1)) and (not getIsLValueDecor(ctx->left_expr())))
        Errors.nonReferenceableExpression(ctx);
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitWriteExpr(AslParser::WriteExprContext *ctx)
{
    DEBUG_ENTER();
    visit(ctx->expr());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr());
    if ((not Types.isErrorTy(t1)) and (not Types.isPrimitiveTy(t1)))
        Errors.readWriteRequireBasic(ctx);
    DEBUG_EXIT();
    return 0;
}

// std::any TypeCheckVisitor::visitWriteString(AslParser::WriteStringContext *ctx) {
//   DEBUG_ENTER();
//   std::any r = visitChildren(ctx);
//   DEBUG_EXIT();
//   return r;
// }

std::any TypeCheckVisitor::visitReturnStmt(AslParser::ReturnStmtContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId t_ret = getCurrentFunctionTy();
    TypesMgr::TypeId t_expr = Types.createVoidTy();
    if (ctx->expr())
    {
        visit(ctx->expr());
        t_expr = getTypeDecor(ctx->expr());
    }

    if (Types.isIntegerTy(t_expr) and Types.isFloatTy(t_ret)) 
    {
        t_expr = Types.createFloatTy();
    }
    if (not Types.equalTypes(t_ret, t_expr))
    {
        Errors.incompatibleReturn(ctx->RETURN());
    }

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitArrayMapStmt(AslParser::ArrayMapStmtContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->a);
    visit(ctx->b);
    TypesMgr::TypeId t_arr_a = getTypeDecor(ctx->a);
    TypesMgr::TypeId t_arr_b = getTypeDecor(ctx->b);

    if (Types.getArraySize(t_arr_a) != Types.getArraySize(t_arr_b))
    {
        Errors.mapWithNonArraysOrDifferentSizes(ctx);
    }

    visit(ctx->x);
    TypesMgr::TypeId t_x = getTypeDecor(ctx->x);
    TypesMgr::TypeId t_elem_arr_b = Types.getArrayElemType(t_arr_b);
    if (not Types.isErrorTy(t_x) and not Types.copyableTypes(t_x, t_elem_arr_b))
    {
        Errors.mapWithIncompatibleControlVar(ctx);
    }

    visit(ctx->cond);
    TypesMgr::TypeId t_cond = getTypeDecor(ctx->cond);
    if (not Types.isErrorTy(t_cond) and not Types.isBooleanTy(t_cond))
    {
        Errors.mapWithNonBooleanCondition(ctx);
    }

    visit(ctx->exp1);
    visit(ctx->exp2);
    TypesMgr::TypeId t_exp1 = getTypeDecor(ctx->exp1);
    TypesMgr::TypeId t_exp2 = getTypeDecor(ctx->exp2);
    TypesMgr::TypeId t_elem_arr_a = Types.getArrayElemType(t_arr_a);
    if ((not Types.isErrorTy(t_exp1) and not Types.copyableTypes(t_elem_arr_a, t_exp1)) or
        (not Types.isErrorTy(t_exp2) and not Types.copyableTypes(t_elem_arr_a, t_exp2)))
    {
        Errors.mapWithIncompatibleValues(ctx);
    }


    DEBUG_EXIT();
    return 0;
}

/*
std::any TypeCheckVisitor::visitLeft_expr(AslParser::Left_exprContext *ctx)
{
    DEBUG_ENTER();
    visit(ctx->ident());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
    putTypeDecor(ctx, t1);
    bool b = getIsLValueDecor(ctx->ident());
    putIsLValueDecor(ctx, b);
    DEBUG_EXIT();
    return 0;
}
*/

std::any TypeCheckVisitor::visitLexprIdent(AslParser::LexprIdentContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->ident());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
    putTypeDecor(ctx, t1);

    std::string ident = ctx->ident()->getText();
    if (Symbols.isFunctionClass(ident)) putIsLValueDecor(ctx, false);
    else putIsLValueDecor(ctx, true);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitLexprArrayAccess(AslParser::LexprArrayAccessContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->array_access());
    TypesMgr::TypeId t_arr = getTypeDecor(ctx->array_access());
    putTypeDecor(ctx, t_arr);
    putIsLValueDecor(ctx, true);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitLexprStructAccess(AslParser::LexprStructAccessContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->struct_access());
    TypesMgr::TypeId t_struct = getTypeDecor(ctx->struct_access());
    putTypeDecor(ctx, t_struct);
    putIsLValueDecor(ctx, true);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitParenthesis(AslParser::ParenthesisContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->expr());

    TypesMgr::TypeId t = getTypeDecor(ctx->expr());
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitExprArrayAccess(AslParser::ExprArrayAccessContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->array_access());
    TypesMgr::TypeId t_arr = getTypeDecor(ctx->array_access());
    putTypeDecor(ctx, t_arr);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitExprStructAccess(AslParser::ExprStructAccessContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->struct_access());
    TypesMgr::TypeId t_struct = getTypeDecor(ctx->struct_access());
    putTypeDecor(ctx, t_struct);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitUnary(AslParser::UnaryContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->expr());
    
    std::string op = ctx->op->getText();
    TypesMgr::TypeId t = getTypeDecor(ctx->expr());
    if (not Types.isErrorTy(t) and op == "not" and Types.isNumericTy(t))
    {
        Errors.incompatibleOperator(ctx->op);
        t = Types.createBooleanTy();
    }
    else if (not Types.isErrorTy(t) and op != "not" and not Types.isNumericTy(t))
    {
        Errors.incompatibleOperator(ctx->op);
        t = Types.createErrorTy();
    }

    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitArithmetic(AslParser::ArithmeticContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->expr(0));
    visit(ctx->expr(1));

    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    
    if (ctx->MOD())
    {
        if (((not Types.isErrorTy(t1)) and (not Types.isIntegerTy(t1))) or
            ((not Types.isErrorTy(t2)) and (not Types.isIntegerTy(t2))))
        {  
            Errors.incompatibleOperator(ctx->op);
        }
    }
    else if (((not Types.isErrorTy(t1)) and (not Types.isNumericTy(t1))) or
             ((not Types.isErrorTy(t2)) and (not Types.isNumericTy(t2))))
    {  
        Errors.incompatibleOperator(ctx->op);
    }
    
    TypesMgr::TypeId t;
    if (ctx->MOD()) t = Types.createIntegerTy();
    else if (Types.isErrorTy(t1) and Types.isErrorTy(t2)) t = Types.createErrorTy();
    else if (Types.isFloatTy(t1) or Types.isFloatTy(t2)) t = Types.createFloatTy();
    else t = Types.createIntegerTy();

    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitRelational(AslParser::RelationalContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->expr(0));
    visit(ctx->expr(1));

    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    std::string oper = ctx->op->getText();
    if ((not Types.isErrorTy(t1)) and (not Types.isErrorTy(t2)) and
        (not Types.comparableTypes(t1, t2, oper)))
    {
        Errors.incompatibleOperator(ctx->op);
    }

    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitLogical(AslParser::LogicalContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->expr(0));
    visit(ctx->expr(1));

    TypesMgr::TypeId t1 = getTypeDecor(ctx->expr(0));
    TypesMgr::TypeId t2 = getTypeDecor(ctx->expr(1));
    if (((not Types.isErrorTy(t1)) and (not Types.isBooleanTy(t1))) or
        ((not Types.isErrorTy(t2)) and (not Types.isBooleanTy(t2))))
    {
        Errors.incompatibleOperator(ctx->op);
    }

    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitIntValue(AslParser::IntValueContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId t = Types.createIntegerTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitBoolValue(AslParser::BoolValueContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId t = Types.createBooleanTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitFloatValue(AslParser::FloatValueContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId t = Types.createFloatTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitCharValue(AslParser::CharValueContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId t = Types.createCharacterTy();
    putTypeDecor(ctx, t);
    putIsLValueDecor(ctx, false);
    
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitExprIdent(AslParser::ExprIdentContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->ident());
    TypesMgr::TypeId t1 = getTypeDecor(ctx->ident());
    putTypeDecor(ctx, t1);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitProcCallExpr(AslParser::ProcCallExprContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->proc_call());
    TypesMgr::TypeId t_ret = getTypeDecor(ctx->proc_call());

    if (not Types.isErrorTy(t_ret) and Types.isVoidTy(t_ret))
    {
        Errors.isNotFunction(ctx->proc_call());
        t_ret = Types.createErrorTy();
    }

    putTypeDecor(ctx, t_ret);
    putIsLValueDecor(ctx, false);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitProcCall(AslParser::ProcCallContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->ident());
    TypesMgr::TypeId t_ident = getTypeDecor(ctx->ident());
    TypesMgr::TypeId t_ret = Types.createErrorTy();

    if (not Types.isErrorTy(t_ident))
    {
        if (Types.isFunctionTy(t_ident))
        {
            if (Types.isVoidFunction(t_ident)) t_ret = Types.createVoidTy();
            else t_ret = Types.getFuncReturnType(t_ident);
        }
        else Errors.isNotCallable(ctx->ident());
    }

    checkParams(ctx);

    putTypeDecor(ctx, t_ret);

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitIdent(AslParser::IdentContext *ctx)
{
    DEBUG_ENTER();

    std::string ident = ctx->getText();
    TypesMgr::TypeId t_ident;

    if (Symbols.findInStack(ident) == -1)
    {
        Errors.undeclaredIdent(ctx->ID());
        t_ident = Types.createErrorTy();
    }
    else t_ident = Symbols.getType(ident);

    putTypeDecor(ctx, t_ident);
    
    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitArray_access(AslParser::Array_accessContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->ident());
    TypesMgr::TypeId t_ident = getTypeDecor(ctx->ident());
    TypesMgr::TypeId t_elem_arr = Types.createErrorTy();

    if (not Types.isErrorTy(t_ident))
    {
        if (not Types.isArrayTy(t_ident)) Errors.nonArrayInArrayAccess(ctx);
        else t_elem_arr = Types.getArrayElemType(t_ident);
    }
    
    putTypeDecor(ctx, t_elem_arr);

    visit(ctx->expr());
    TypesMgr::TypeId t_expr = getTypeDecor(ctx->expr());

    if (not Types.isErrorTy(t_expr) and not Types.isIntegerTy(t_expr))
    {
        Errors.nonIntegerIndexInArrayAccess(ctx->expr());
    }

    DEBUG_EXIT();
    return 0;
}

std::any TypeCheckVisitor::visitStruct_access(AslParser::Struct_accessContext *ctx)
{
    DEBUG_ENTER();

    visit(ctx->id_struct);
    TypesMgr::TypeId t_struct = getTypeDecor(ctx->id_struct);
    std::string field = ctx->field->getText();
    TypesMgr::TypeId t_field = Types.createErrorTy();

    if (Types.isErrorTy(t_struct))
    {
        putTypeDecor(ctx, t_field);

        DEBUG_EXIT();
        return 0;
    }

    if (not Types.isStructTy(t_struct))
    {
        Errors.structAccessWithNonStruct(ctx);

    }
    else if (not Types.existStructField(t_struct, field))
    {
        Errors.structAccessWithNonExistentField(ctx);
    }
    else
    {
        t_field = Types.getStructFieldTy(t_struct, field);
    }

    putTypeDecor(ctx, t_field);

    DEBUG_EXIT();
    return 0;
}

// Getters for the necessary tree node atributes:
//   Scope, Type ans IsLValue
SymTable::ScopeId TypeCheckVisitor::getScopeDecor(antlr4::ParserRuleContext *ctx)
{
    return Decorations.getScope(ctx);
}
TypesMgr::TypeId TypeCheckVisitor::getTypeDecor(antlr4::ParserRuleContext *ctx)
{
    return Decorations.getType(ctx);
}
bool TypeCheckVisitor::getIsLValueDecor(antlr4::ParserRuleContext *ctx)
{
    return Decorations.getIsLValue(ctx);
}

// Setters for the necessary tree node attributes:
//   Scope, Type ans IsLValue
void TypeCheckVisitor::putScopeDecor(antlr4::ParserRuleContext *ctx, SymTable::ScopeId s)
{
    Decorations.putScope(ctx, s);
}
void TypeCheckVisitor::putTypeDecor(antlr4::ParserRuleContext *ctx, TypesMgr::TypeId t)
{
    Decorations.putType(ctx, t);
}
void TypeCheckVisitor::putIsLValueDecor(antlr4::ParserRuleContext *ctx, bool b)
{
    Decorations.putIsLValue(ctx, b);
}

void TypeCheckVisitor::checkParams(AslParser::ProcCallContext *ctx)
{
    DEBUG_ENTER();

    TypesMgr::TypeId t_ident = getTypeDecor(ctx->ident());
    std::size_t np_decl = Types.isFunctionTy(t_ident) ? Types.getNumOfParameters(t_ident) : 0;
    std::size_t np_call = ctx->expr().size();

    if (Types.isFunctionTy(t_ident) and np_decl != np_call) Errors.numberOfParameters(ctx->ident());

    for (std::size_t i = 0; i < np_call; ++i)
    {
        visit(ctx->expr(i));

        if (i < np_decl)
        {
            TypesMgr::TypeId tp_call = getTypeDecor(ctx->expr(i));
            TypesMgr::TypeId tp_decl = Types.getParameterType(t_ident, i);
    
            if (not Types.isErrorTy(tp_call) and not Types.copyableTypes(tp_decl, tp_call)) 
            {
                Errors.incompatibleParameter(ctx->expr(i), i + 1, ctx);
            }
        }
    }

    DEBUG_EXIT();
}
