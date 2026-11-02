//////////////////////////////////////////////////////////////////////
//
//    Asl - Another simple language (grammar)
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

grammar Asl;

//////////////////////////////////////////////////
/// Parser Rules
//////////////////////////////////////////////////

// A program is a list of functions
program : function+ EOF
        ;

// A function has a name, a list of parameters and a list of statements
function
        : FUNC ID '(' params? ')' (':' type)? declarations statements ENDFUNC
        ;

declarations
        : (variable_decl)*
        ;

variable_decl
        : VAR ID (',' ID)* ':' type
        ;

type    : basic_type                                            # basicTypeDecl
        | ARRAY '[' INTVAL ']' OF basic_type                    # arrayTypeDecl
        ;

basic_type 
        : INT
        | BOOL
        | FLOAT
        | CHAR
        ;   

statements
        : (statement)*
        ;

// The different types of instructions
statement
          // Assignment
        : left_expr ASSIGN expr ';'                                                  # assignStmt
          // if-then-else statement (else is optional)
        | IF expr THEN statements (ELSE statements)? ENDIF                           # ifStmt
          // while statement
        | WHILE expr DO statements ENDWHILE                                          # whileStmt
          // for statement
        | FOR ident IN RANGE '(' (expr (',' expr)*)? ')' DO statements ENDFOR        # forStmt
          // A function/procedure call has a list of arguments in parenthesis (possibly empty)
        | proc_call ';'                                                              # procCallStmt
          // Read a variable
        | READ left_expr ';'                                                         # readStmt
          // Write an expression
        | WRITE expr ';'                                                             # writeExpr
          // Write a string
        | WRITE STRING ';'                                                           # writeString
          // Return statement
        | RETURN expr? ';'                                                           # returnStmt
        ;

// Grammar for left expressions (l-values in C++)
left_expr
        : ident                                                 # lexprIdent
        | array_access                                          # lexprArrayAccess
        ;

// Grammar for expressions with boolean, relational and aritmetic operators
expr    : '(' expr ')'                                          # parenthesis
        | array_access                                          # exprArrayAccess
        | op=(NOT | PLUS | MINUS) expr                          # unary
        | expr op=(MUL | DIV | MOD) expr                        # arithmetic
        | expr op=(PLUS | MINUS) expr                           # arithmetic
        | expr op=(EQ | NEQ | GT | GEQ | LEQ | LT) expr         # relational
        | expr op=AND expr                                      # logical
        | expr op=OR expr                                       # logical
        | INTVAL                                                # intValue
        | BOOLVAL                                               # boolValue
        | FLOATVAL                                              # floatValue
        | CHARVAL                                               # charValue
        | ident                                                 # exprIdent
        | MAX '(' (expr (',' expr)*)? ')'                       # maxCall
        | proc_call                                             # procCallExpr
        ;

proc_call
        : ident '(' (expr (',' expr)*)? ')'                     # procCall
        ;

// Identifiers
ident   : ID
        ;

// Function/procedure parameters
params  : param_decl (',' param_decl)*
        ;

param_decl 
        : ID ':' type
        ;

array_access
        : ident '[' expr ']'
        ;

//////////////////////////////////////////////////
/// Lexer Rules
//////////////////////////////////////////////////

FUNC      : 'func' ;
ENDFUNC   : 'endfunc' ;

VAR       : 'var';
INT       : 'int';
FLOAT     : 'float';
BOOL      : 'bool';
CHAR      : 'char';
ARRAY     : 'array';
OF        : 'of';

ASSIGN    : '=' ;
IF        : 'if' ;
THEN      : 'then' ;
ELSE      : 'else' ;
ENDIF     : 'endif' ;
WHILE     : 'while' ;
DO        : 'do' ;
ENDWHILE  : 'endwhile' ;
FOR       : 'for' ;
IN        : 'in' ;
RANGE     : 'range' ;
ENDFOR    : 'endfor' ;
READ      : 'read' ;
WRITE     : 'write' ;
RETURN    : 'return' ;

NOT       : 'not' ;
PLUS      : '+' ;
MINUS     : '-' ;
MUL       : '*' ;
DIV       : '/' ;
MOD       : '%' ;
EQ        : '==' ;
NEQ       : '!=' ;
GT        : '>' ;
GEQ       : '>=' ;
LEQ       : '<=' ;
LT        : '<' ;
AND       : 'and' ;
OR        : 'or' ;

INTVAL    : DIGIT+ ;
BOOLVAL   : 'true' | 'false' ;
FLOATVAL  : DIGIT+ '.' DIGIT+ ;
CHARVAL   : '\'' ( ESC_SEQ | ~('\\'|'\'') ) '\'' ;

fragment
DIGIT     : ('0'..'9') ;

MAX       : 'max' ;

ID        : ('a'..'z'|'A'..'Z') ('a'..'z'|'A'..'Z'|'_'|'0'..'9')* ;

// Strings (in quotes) with escape sequences
STRING    : '"' ( ESC_SEQ | ~('\\'|'"') )* '"' ;

fragment
ESC_SEQ   : '\\' ('b'|'t'|'n'|'f'|'r'|'"'|'\''|'\\') ;

// Comments (inline C++-style and multiline C-style)
COMMENT   : ( '//' ~('\n'|'\r')* '\r'? '\n'
            | '/*' .*? '*/'
            ) -> skip
          ;

// White spaces
WS        : (' '|'\t'|'\r'|'\n')+ -> skip ;
// Alternative description
// WS        : [ \t\r\n]+ -> skip ;
