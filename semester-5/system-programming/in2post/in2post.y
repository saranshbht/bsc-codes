%{
      #include <stdio.h>
      #include <stdlib.h>
%}


%token NUMBER NEWLINE
%left '+' '-'
%left '*' '/' '%'

%%

start: expr NEWLINE  {
                        printf("\nComplete\n");
                        exit(1);
                      }
  ;

expr:  expr '+' expr        { printf("+ ");}
  | expr '-' expr     { printf("- ");}
  | expr '*' expr     { printf("* ");}
  | expr '/' expr     { printf("/ ");}
  | expr '%' expr     { printf("%% ");}
  | '(' expr ')'  
  | NUMBER            { printf("%d ", $1);}         
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