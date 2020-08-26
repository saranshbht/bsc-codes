%{
    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    int yylex();
    int yyerror();
    extern FILE *yyin;
    extern FILE *yyout;
    int lc;
    char *arr;
    struct identifier {
        char* id;
        int loc;
    };
    struct identifier symtab[10];
    int ids;
    int temp, temp2, location;
    char* decimalToHex(int location){
        char c[2];
        if(location / 16 > 9)
            c[0] = (char)(location / 16 + 55);
        else
            c[0] = (char)(location / 16 + 48);
        if(location % 16 > 9)
            c[1] = (char)(location % 16 + 55);
        else
            c[1] = (char)(location % 16 + 48);
        return c;
    }

    char* findAddress(char* c){
        int k = -1;
        for(int i = 0; i < ids; i++){
            if(!strcmp(symtab[i].id, c)){
                k = i;
                break;
            }
        }
        if(k == -1)
            location = 255;             //invalid or forward reference
        else
            location = symtab[k].loc;
        return decimalToHex(location);
    }
%}

%token DD
%token MVI
%token LOADI
%token ADD
%token MOV
%token INC
%token CMP
%token JE
%token ADDI
%token JMP
%token STORE
%token STOP
%token SPACE
%token NUMBER
%token ID
%token NEWLINE
%token COMMENT
%token A
%token B
%token C
%token I
%token STORI
%token LOAD

%union{
    char* s;
    int i;
}

%type <i> NUMBER
%type <s> ID

%%

start: statement_list NEWLINE STOP {
            printf("Program syntactically correct\n");
            return 0;
        }
    ;

statement_list:  statement                 
    | statement_list NEWLINE statement 
    ;

statement: 
    | ID ':' instr optionComment  {
        symtab[ids].id = $1; 
        symtab[ids].loc = lc;
        ids++;
        lc += temp2;
        temp2 = 0;
    }
    
    | instr optionComment   {
        lc += temp2;
        temp2 = 0;
    }
    ;

optionComment:
    | COMMENT 
    ;

instr: ID DD number_list    { 
        symtab[ids].id = $1; 
        symtab[ids].loc = lc;
        ids++;
        temp2 += temp;
        temp = 0;
    }
    
    | MVI A ',' NUMBER    { 
        fprintf(yyout, "00");
        char *c = decimalToHex($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | MVI A ',' ID    { 
        fprintf(yyout, "00");
        char *c = findAddress($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | MVI B ',' NUMBER    { 
        fprintf(yyout, "01");
        char *c = decimalToHex($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | MVI B ',' ID    { 
        fprintf(yyout, "01");
        char *c = findAddress($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | MVI C ',' NUMBER    { 
        fprintf(yyout, "02");
        char *c = decimalToHex($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | MVI C ',' ID    { 
        fprintf(yyout, "02");
        char *c = findAddress($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | MVI I ',' NUMBER    { 
        fprintf(yyout, "03");
        char *c = decimalToHex($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | MVI I ',' ID    { 
        fprintf(yyout, "03");
        char *c = findAddress($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | LOAD NUMBER     { 
        fprintf(yyout, "04");
        char *c = decimalToHex($2);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | LOAD ID     { 
        fprintf(yyout, "04");
        char *c = findAddress($2);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | STORE ID    { 
        fprintf(yyout, "05");
        char *c = findAddress($2);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | LOADI     { 
        fprintf(yyout, "06\n");
        temp2 += 1; 
    }
    
    | STORI     { 
        fprintf(yyout, "07\n");
        temp2 += 1; 
    }
    
    | ADD B   { 
        fprintf(yyout, "08\n");
        temp2 += 1; 
    }
    
    | ADD C   { 
        fprintf(yyout, "09\n");
        temp2 += 1; 
    }
    
    | MOV A ',' B     { 
        fprintf(yyout, "0A\n");
        temp2 += 1; 
    }
    
    | MOV A ',' C     { 
        fprintf(yyout, "0B\n");
        temp2 += 1; 
    }
    
    | MOV B ',' C     { 
        fprintf(yyout, "0C\n");
        temp2 += 1; 
    }
    
    | MOV B ',' A     { 
        fprintf(yyout, "0D\n");
        temp2 += 1; 
    }
    
    | MOV C ',' A     { 
        fprintf(yyout, "0E\n");
        temp2 += 1; 
    }
    
    | MOV C ',' B     { 
        fprintf(yyout, "0F\n");
        temp2 += 1; 
    }
    
    | INC A   { 
        fprintf(yyout, "10\n");
        temp2 += 1; 
    }
    
    | INC B   { 
        fprintf(yyout, "11\n");
        temp2 += 1; 
    }
    
    | INC C   { 
        fprintf(yyout, "12\n");
        temp2 += 1; 
    }
    
    | CMP A ',' NUMBER    { 
        fprintf(yyout, "13");
        char *c = decimalToHex($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | CMP A ',' ID    { 
        fprintf(yyout, "13");
        char *c = findAddress($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | CMP B ',' NUMBER    { 
        fprintf(yyout, "14");
        char *c = decimalToHex($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | CMP B ',' ID    { 
        fprintf(yyout, "14");
        char *c = findAddress($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | CMP C ',' NUMBER    { 
        fprintf(yyout, "15");
        char *c = decimalToHex($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | CMP C ',' ID    { 
        fprintf(yyout, "15");
        char *c = findAddress($4);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | ADDI ID     { 
        fprintf(yyout, "16");
        char *c = findAddress($2);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | ADDI NUMBER     { 
        fprintf(yyout, "16");
        char *c = decimalToHex($2);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | JE ID   { 
        fprintf(yyout, "17");
        char *c = findAddress($2);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    
    | JMP ID  { 
        fprintf(yyout, "18");
        char *c = findAddress($2);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp2 += 5; 
    }
    ;

number_list: NUMBER     { 
        char a, b;
        char *c = decimalToHex($1);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp += 4; 
    }
    | number_list ',' NUMBER    { 
        char *c = decimalToHex($3);
        fprintf(yyout, "%c%c000000\n", c[0], c[1]);
        temp += 4; 
    }
    ;

%%

int yyerror(const char *s){
    fclose(yyin);
    fclose(yyout);
    yyout = fopen("machineCode.txt", "w");
    fprintf(yyout, "Error while parsing");
    fclose(yyout);
    printf("Syntax Error!!!!");
    exit(1);
}


int main(){
    // FILE *yyin;
    yyin = fopen("assemblyProgram.txt", "r");
    yyout = fopen("machineCode.txt", "w");
    if(yyin == NULL || yyout == NULL){
        printf("Error while opening files\n");
        return 0;
    }
    yyparse();
    // for(int i = 0; i < ids; i++)
    //     printf("%s %d\n", symtab[i].id, symtab[i].loc);
    fprintf(yyout, "19\n");
    fclose(yyout);
    fclose(yyin);
    return 0;
}