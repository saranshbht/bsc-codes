%{
	#include "y.tab.h"
%}

%%

[0-9]+	            return NUMBER;
[a-z_][a-z_0-9]*    return ID;
.                   return *yytext;
[\n]                return NEWLINE;

%%

int yywrap()
{
	return 1;
}