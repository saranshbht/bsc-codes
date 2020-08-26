%{
    int keys, ints, floats, ids, ops, comments;
%}

%%
#.* ;
\"((\\\")|[^"])*\" ;
"/*"([^*]*[*]+)([^*/][^*]*[*]+)*"/" { comments++; printf("Comment : %s\n", yytext); }
"//".* { comments++; printf("Comment : %s\n", yytext); }
"=="|"++"|"--"|"!="|"<="|">="|"||"|"&&"|"~"|"+="|"-="|"*="|"/="|"%="|"&="|"|="|"^="|"<<="|">>="|"->*"|".*"|"new"|"delete"|"sizeof"|"delete[]"|"::"|","|"?"|"->"|"."|"+"|"-"|"!"|"*"|"/"|"&"|"^"|"%"|"|"|"<<"|">>"|"="|">"|"<"|"," { ops++; printf("Operator : %s\n", yytext); }
and|auto|bool|break|case|catch|char|class|const|continue|default|delete|do|double|else|false|float|for|goto|if|inline|long|int|namespace|new|not|or|private|public { keys++; printf("Keyword : %s\n", yytext); }
protected|register|return|short|signed|sizeof|static|struct|switch|this|throw|true|try|typedef|unsigned|using|virtual|void|xor|while { keys++; printf("Keyword : %s\n", yytext); }
[a-zA-Z_][a-zA-Z_0-9]* { ids++; printf("Identifier : %s\n", yytext); }
[-+]?[0-9]+\.[0-9]+ { floats++; printf("Float : %s\n", yytext); }
[-+]?[0-9]+ { ints++; printf("Integer : %s\n", yytext); }
.|\n ;

%%

int main(){
    yyin = fopen("comments.cpp", "r");
    yylex();
    printf("No of keywords in the file : %d\n", keys);
    printf("No of integers in the file : %d\n", ints);
    printf("No of floats in the file : %d\n", floats);
    printf("No of identifiers in the file : %d\n", ids);
    printf("No of operators in the file : %d\n", ops);
    printf("No of comments in the file : %d\n", comments);
    return 0;
}

int yywrap(){
    return 1;
}
