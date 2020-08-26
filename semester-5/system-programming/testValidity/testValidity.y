%{
      #include <stdio.h>
      #include <stdlib.h>
      int yylex();
      int yyerror();
%}


%token NUMBER ID NEWLINE
%left '+' '-'
%left '*' '/'

%%

start: expr NEWLINE  {
                        printf("Expression Valid");
                        exit(0);
                      }
  ;

expr:  expr '+' expr        
  | expr '-' expr     
  | expr '*' expr    
  | expr '/' expr     
  | '(' expr ')'  
  | NUMBER
  | ID        
  ;

%%

int yyerror(char const *s)
{
    printf("Expression not valid");
    return 1;
}

int main()
{
  printf("Enter an arithmetic expression\n");
  yyparse();
  return 0;
}