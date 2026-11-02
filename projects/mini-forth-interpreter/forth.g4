grammar forth;


root : instr+ EOF
     ;

instr : funcdef | atom 
      ;

funcdef : ':' ID bloc ';'                              
        ;
     
atom : NUM                                             # nombre
     | (OP | ID)                                       # operador
     ;

bloc : (atom | recurse | condicional)+                                      
     ;

recurse : 'recurse'
        ;

condicional : cond+=atom+ 'if' bloc_if=bloc ('else' bloc_else=bloc)? 'endif'
            ;
     
OP : ('.s' | '.' 
     | '+' | '-' | '*' | '/' | 'mod' 
     | 'swap' | '2swap' | 'dup' | '2dup' | 'over' | '2over' 
     | 'rot' | 'drop' | '2drop'
     | '=' | '<>' | '<' | '<=' | '>' | '>=' 
     | 'and' | 'or' | 'not') ;
NUM : ('-' [0-9]+ | [0-9]+) ;
ID : [a-zA-Z_][a-zA-Z0-9_]* ;

COMMENT : '(' .*? ')' -> skip ;
WS  : [ \t\n\r]+ -> skip ;