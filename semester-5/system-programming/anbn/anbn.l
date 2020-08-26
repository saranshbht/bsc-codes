%{
    #include "y.tab.h"
%}

%%

a      { return A; }
b      { return B; }
\n     { return NEWLINE; }
.      { return *yytext; }

%%

int yywrap(){
    return 1;
}