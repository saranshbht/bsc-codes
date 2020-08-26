%{
    int ids;
%}

%%
\"((\\\")|[^"])*\" ;
"/*"([^*]*[*]+)([^*/][^*]*[*]+)*"/" ;
"//".* ;
#.* ;
and|auto|bool|break|case|catch|char|class|const|continue|default|delete|do|double|else|false|float|for|goto|if|inline|long|int|namespace|new|not|or|private|public ;
protected|register|return|short|signed|sizeof|static|struct|switch|this|throw|true|try|typedef|unsigned|using|virtual|void|xor|while ;
[a-zA-Z_][a-zA-Z_0-9]* { ids++; printf("%s\n", yytext); }
.|\n ;
%%

int main(){
    yyin = fopen("comments.cpp", "r");
    yylex();
    printf("There are %d identifiers in the file", ids);
    return 0;
}

int yywrap(){
    return 1;
}