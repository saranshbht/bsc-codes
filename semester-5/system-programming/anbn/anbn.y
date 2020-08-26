%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror();
%}

%token A B NEWLINE


%%

start: s NEWLINE {
        printf("Expression valid");
        exit(1);
    }
    ;

s:  A B
    | A s B
    ;

%%

int yyerror(char const *s){
    printf("Expression not valid");
}

int main(){
    printf("Enter a string\n");
    yyparse();
    return 1;
}