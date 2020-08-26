%{
	#include "y.tab.h"
%}

%%

[0-9]+	            return NUMBER;
.                   return *yytext;
[\n]                return NEWLINE;

%%

int yywrap()
{
	return 1;
}