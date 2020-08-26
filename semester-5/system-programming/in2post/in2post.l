%{
    #include<stdio.h>
    #include<stdlib.h> 
	  #include "y.tab.h"
%}

%%

[0-9]+	{
          yylval = atoi(yytext);
          return NUMBER;
        }
.         return *yytext;
[\n]      return NEWLINE;

%%

int yywrap()
{
	return 1;
}