%{
	#include<string.h>
	int max = -1;
	char *c;
%}

%%

\n	{ 
	printf("The longest word in the above line : %s\n", c);
	max = -1;
	return 1;
}

[a-zA-Z]+ {
	if(yyleng > max){
		max = yyleng;
		c = (char *)malloc(yyleng + 1);
		strncpy(c, yytext, yyleng);
		c[yyleng] = 0;
	}
}

. ;

%%

int main(){
	printf("Enter some text\n");
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
