%{
    int words, chars, spaces, lines;
%}

%%

[a-zA-Z]+ { words++; chars += yyleng; }
[ \t] { spaces++; chars++; }
\n { lines++; chars++; }
. { chars++; }

%%

int main(){
    yyin = fopen("comments.cpp", "r");
    yylex();
    printf("No of words in the input file : %d\n", words);
    printf("No of spaces in the input file : %d\n", spaces);
    printf("No of lines in the input file : %d\n", lines + 1);
    printf("No of chars in the input file : %d\n", chars);
    return 0;
}

int yywrap(){
    return 1;
}