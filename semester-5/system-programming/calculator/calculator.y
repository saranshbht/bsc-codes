%{
      #include <stdio.h>
      #include <stdlib.h>
      int yylex();
      int yyerror();
%}

%union{
    float f;
}
%token FLOAT NEWLINE
%type <f> start expr FLOAT
%left '+' '-'
%left '*' '/'

%%

start: expr NEWLINE  {
                        printf("Expression valid\nRes = %f\n", $$);
                        exit(1);
                      }
  ;

expr:  expr '+' expr        { $$ = $1 + $3;}
  | expr '-' expr     { $$ = $1 - $3;}
  | expr '*' expr     { $$ = $1 * $3;}
  | expr '/' expr     { if($3 == 0){
                          printf("Res = Not defined\n");
                          exit(1);
                        }  
                        $$ = $1 / $3;}
  | '(' expr ')'      { $$ = $2;}
  | FLOAT
  | '-' expr          { $$ = -$2;}
  | '+' expr          { $$ = $2;}          
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
  return 1;
}