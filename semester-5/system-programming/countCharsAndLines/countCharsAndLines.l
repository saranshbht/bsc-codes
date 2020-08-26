%{
int numChars;
int numLines;
%}

%%

\n { numLines++; }
. { numChars++; }

%%

int main(){
	yyin = fopen("testing.txt", "r");
	yylex();
	printf("There are %d lines and %d characters in the file\n", numLines + 1, numLines + numChars);
	return 0;
}

int yywrap(){
	return 1;
}
