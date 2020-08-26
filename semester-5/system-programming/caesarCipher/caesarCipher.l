%{
	char* c;
%}

%%

[A-Za-z] { 
	c = yytext;
	if(*yytext <= 90)
		*c = (*c - 65 + 3) % 26 + 65;
	else
		*c = (*c - 97 + 3) % 26 + 97;
	printf(c);
}
\n return ;
%%

int main(){
	printf("Enter some text to get its Caesar Cipher\n");
	yylex();
	return 0;
}

int yywrap(){
	return 1;
}
