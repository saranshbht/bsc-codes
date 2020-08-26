%{
    #include<stdio.h>
    #include<stdlib.h>
    int yyerror();
    int yylex();
%}

%token A B NEWLINE


%%

start: s NEWLINE {
        printf("Expression valid");
        exit(1);
    }
    ;

s:  A A A A A A A A A A a B
    ;

a:
    | a A
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