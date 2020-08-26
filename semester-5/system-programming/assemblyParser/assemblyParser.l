%option case-insensitive

%{
    #include<stdio.h>
    #include<string.h>
    #include "y.tab.h"
%}

%%
a                       { return A; }
b                       { return B; }
c                       { return C; }
i                       { return I; }
dd                      { return DD; }
mvi                     { return MVI; }
loadi                   { return LOADI; }
stori                   { return STORI; }
add                     { return ADD; }
mov                     { return MOV; }
inc                     { return INC; }
cmp                     { return CMP; }
je                      { return JE; }
addi                    { return ADDI; }
jmp                     { return JMP; }
load                    { return LOAD; }
store                   { return STORE; }
stop                    { return STOP; }
[ \t]+                  ;
-?[0-9]+    { 
    yylval.i = atoi(yytext);
    return NUMBER; 
}
[a-zA-Z][a-zA-Z0-9]*    { 
    char *c = malloc(yyleng + 1);
    c[yyleng] = 0;
    strncpy(c, yytext, yyleng);
    yylval.s = c;
    return ID;
}
\n                      { return NEWLINE; }
;.*                     { return COMMENT; }
.                       { return *yytext; }

%%

int yywrap(){
    return 1;
}