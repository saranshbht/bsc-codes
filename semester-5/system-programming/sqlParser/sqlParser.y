%{
    #include<stdio.h>
    #include<stdlib.h>
    int yylex();
    int yyerror();
%}

%token NEWLINE
%token ID
%token ALTER
%token TABLE
%token ADD
%token COLUMN
%token FIRST
%token AFTER
%token KEY
%token CONSTRAINT
%token PRIMARY
%token UNIQUE
%token FOREIGN
%token DROP
%token CHECK
%token NOT
%token ENFORCED
%token SET
%token DEFAULT
%token CHANGE
%token MODIFY
%token ORDER
%token BY
%token RENAME
%token TO
%token AS
%token ASC
%token DESC
%token REFERENCES
%token MATCH
%token FULL
%token PARTIAL
%token SIMPLE
%token ON
%token DELETE
%token UPDATE
%token RESTRICT
%token CASCADE
%token NULLX
%token NO
%token ACTION
%token AUTO_INCREMENT
%token KEYWORD
%token INTLIT
%token FLOATLIT
%token BOOLLIT
%token STRINGLIT
%token BIT 
%token TINYINT
%token UNSIGNED
%token ZEROFILL
%token BOOL
%token BOOLEAN
%token SMALLINT
%token MEDIUMINT
%token INT
%token INTEGER
%token BIGINT
%token DECIMAL
%token DEC
%token NUMERIC
%token FIXED
%token FLOAT
%token DOUBLE
%token PRECISION
%token REAL
%token DATE 
%token DATETIME
%token TIMESTAMP
%token TIME
%token CHAR 
%token VARCHAR 
%token BINARY
%token VARBINARY
%token TINYBLOB
%token TINYTEXT
%token BLOB
%token TEXT
%token MEDIUMBLOB
%token MEDIUMTEXT
%token LONGBLOB
%token LONGTEXT
%token YEAR

%%
start: ALTER TABLE ID alter_specification_list optionorder ';' NEWLINE {
            printf("Correct syntax");
            exit(1);
        }
    ;

optionorder:
    | ',' ORDER BY key_part_list
    | ORDER BY key_part_list
    ;


alter_specification_list:
    | alter_specification
    | alter_specification_list ',' alter_specification
    ;

alter_specification:
     ADD optioncol ID column_definition optionpart
    
    | ADD optionconst PRIMARY KEY '(' key_part_list ')' 
    
    | ADD optionconst UNIQUE '(' key_part_list ')' 

    | ADD optionconst FOREIGN KEY '(' key_part_list ')' reference_definition 
    
    | DROP CHECK ID 
    
    | ALTER CHECK ID ENFORCED 
    | ALTER CHECK ID NOT ENFORCED 
    
    | ALTER optioncol ID SET DEFAULT literal 
    | ALTER optioncol ID DROP DEFAULT 

    | CHANGE optioncol ID ID column_definition optionpart

    | DROP optioncol ID 

    | DROP PRIMARY KEY 

    | DROP FOREIGN KEY ID 

    | MODIFY optioncol ID column_definition optionpart
    
    | RENAME COLUMN ID TO ID 

    | RENAME ID 
    | RENAME TO ID 
    | RENAME AS ID 
    ;

optioncol:
    | COLUMN 
    ;
    
optionpart:
    | FIRST 
    | AFTER ID 
    ;

optionconst:
    | CONSTRAINT 
    | CONSTRAINT ID 
    ;

key_part_list:
    key_part
    | key_part_list ',' key_part
    ;

key_part: 
    ID keypartA
    ;

keypartA:
    | ASC 
    | DESC 
    ;


reference_definition:
    REFERENCES ID '(' key_part_list ')' refdefA refdefB
    ;

refdefA:
    | MATCH FULL 
    | MATCH PARTIAL 
    | MATCH SIMPLE 
    ;

refdefB:
    | ON deleteupdate reference_option
    ;

deleteupdate:
    DELETE 
    | UPDATE 
    ;

reference_option:
    RESTRICT 
    | CASCADE 
    | SET NULLX 
    | NO ACTION 
    | SET DEFAULT 
    ;

column_definition:
    data_type coldefA coldefB coldefC coldefD coldefE coldefF
    ;

coldefA:
    | NOT NULLX 
    | NULLX 
    ;

coldefB:
    | DEFAULT literal 
    ;

coldefC:
    | AUTO_INCREMENT 
    ;

coldefD:
    | UNIQUE 
    ;


coldefE:
    | KEY 
    | PRIMARY KEY 
    ;

coldefF: 
    | reference_definition
    ;

data_type:
    LONGBLOB 
    | LONGTEXT 
    | MEDIUMTEXT 
    | MEDIUMBLOB 
    | TEXT optionsize
    | BLOB optionsize
    | TINYTEXT 
    | TINYBLOB 
    | VARBINARY '(' INTLIT ')' 
    | BINARY optionsize
    | VARCHAR '(' INTLIT ')' 
    | CHAR optionsize
    | TIME optionsize
    | TIMESTAMP optionsize
    | DATETIME optionsize
    | DATE 
    | YEAR 
    | DOUBLE PRECISION optionfloatsize optionunsign optionzero
    | DOUBLE optionfloatsize optionunsign optionzero
    | FLOAT '(' INTLIT ')' optionunsign optionzero
    | FLOAT optionfloatsize optionunsign optionzero
    | BIGINT optionsize optionunsign optionzero
    | INTEGER optionsize optionunsign optionzero
    | INT optionsize optionunsign optionzero
    | MEDIUMINT optionsize optionunsign optionzero
    | SMALLINT optionsize optionunsign optionzero
    | BOOL  
    | BOOLEAN  
    | TINYINT optionsize optionunsign optionzero
    | BIT optionsize
    | DECIMAL optiondecsize optionunsign optionzero
    | DEC optiondecsize optionunsign optionzero
    | NUMERIC optiondecsize optionunsign optionzero
    | FIXED optiondecsize optionunsign optionzero
    ;

optionsize:
    | '(' INTLIT ')' 
    ;

optionfloatsize:
    | '(' INTLIT ',' INTLIT ')' 
    ;

optiondecsize:
    | '(' INTLIT ')' 
    | '(' INTLIT ',' INTLIT ')' 
    ;

optionunsign: 
    | UNSIGNED
    ;

optionzero:
    | ZEROFILL
    ;

literal:
    INTLIT
    | BOOLLIT
    | FLOATLIT
    | STRINGLIT
    ;
%%

int yyerror(const char *s){
    printf(s);
    return 1;
}


int main(){
    printf("ENTER AN SQL STATEMENT\n");
    yyparse();
    return 0;
}