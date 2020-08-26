%option case-insensitive
%{
    #include "y.tab.h"
    #include<stdio.h>
%}

%%

alter                   { return ALTER; }
table                   { return TABLE; }
add                     { return ADD; }
column                  { return COLUMN; }
first                   { return FIRST; }
after                   { return AFTER; }
key                     { return KEY; }
constraint              { return CONSTRAINT; }
primary                 { return PRIMARY; }
unique                  { return UNIQUE; }
foreign                 { return FOREIGN; }
drop                    { return DROP; }
check                   { return CHECK; }
not                     { return NOT; }
enforced                { return ENFORCED; }
set                     { return SET; }
default                 { return DEFAULT; }
change                  { return CHANGE; }
modify                  { return MODIFY; }
order                   { return ORDER; }
by                      { return BY; }
rename                  { return RENAME; }
to                      { return TO; }
as                      { return AS; }
asc                     { return ASC; }
desc                    { return DESC; }
references              { return REFERENCES; }
match                   { return MATCH; }
full                    { return FULL; }
partial                 { return PARTIAL; }
simple                  { return SIMPLE; }
on                      { return ON; }
delete                  { return DELETE; }
update                  { return UPDATE; }
restrict                { return RESTRICT; }
cascade                 { return CASCADE; }
null                    { return NULLX; }
action                  { return ACTION; }
auto_increment          { return AUTO_INCREMENT; }
bit                     { return BIT; }
tinyint                 { return TINYINT; }
unsigned                { return UNSIGNED; }
zerofill                { return ZEROFILL; }
bool                    { return BOOL; }
boolean                 { return BOOLEAN; }
smallint                { return SMALLINT; }
mediumint               { return MEDIUMINT; }
int                     { return INT;}
integer                 { return INTEGER; }
bigint                  { return BIGINT; }
decimal                 { return DECIMAL; }
dec                     { return DEC; }
numeric                 { return NUMERIC; }
fixed                   { return FIXED; }
float                   { return FLOAT; }
double                  { return DOUBLE; }
precision               { return PRECISION; }
date                    { return DATE; }
datetime                { return DATETIME; }
timestamp               { return TIMESTAMP; }
time                    { return TIME; }
char                    { return CHAR; }
varchar                 { return VARCHAR; }
binary                  { return BINARY; }
varbinary               { return BINARY; }
tinyblob                { return TINYBLOB; }
tinytext                { return TINYTEXT; }
blob                    { return BLOB; }
text                    { return TEXT; }
mediumblob              { return MEDIUMBLOB; }
mediumtext              { return MEDIUMTEXT; }
longblob                { return LONGBLOB; }
longtext                { return LONGTEXT; }
year                    { return YEAR; }
accessible|all|analyze|and|asensitive|array                                                                                                                                                                                     |
before|between|both                                                                                                                                                                                                             |
call|case|collate|condition|continue|convert|create|cross|cube|cume_dist|current_date|current_time|current_timestamp|current_user|cursor                                                                                        |
database|databases|day_hour|day_microsecond|day_minute|day_second|delayed|describe|deterministic|distinct|distinctrow|div|dual|dense_rank                                                                                       |
each|else|elseif|empty|enclosed|escaped|except|exists|exit|explain                                                                                                                                                              |
fetch|first_value|float4|float8|for|force|fulltext|function                                                                                                                                                                     |
generated|get|grant|group|grouping|groups                                                                                                                                                                                       |
having|high_priority|hour_microsecond|hour_minute|hour_second                                                                                                                                                                   |
if|ignore|in|index|infile|inner|inout|insensitive|insert|int1|int2|int3|int4|int8|interval|into|io_after_gtids|io_before_gtids|is|iterate                                                                                       |
join|json_table                                                                                                                                                                                                                 |
keys|kill                                                                                                                                                                                                                       |
lag|last_value|lateral|lead|leading|leave|left|like|limit|linear|lines|load|localtime|localtimestamp|lock|loop|low_prior                                                                                                        |   
master_bind|master_ssl_verify_server_cert|maxvalue|middleint|minute_microsecond|minute_second|mod|modifies|member                                                                                                               |
natural|no_write_to_binlog|nth_value|ntile                                                                                                                                                                                      |
of|optimize|optimizer_costs|option|optionally|or|out|outer|outfile|over                                                                                                                                                         |
partition|percent_rank|procedure|purge                                                                                                                                                                                          |
range|rank|read|reads|read_write|real|recursive|regexp|release|repeat|replace|require|resignal|return|revoke|right|rlike|row|rows|row_number                                                                                    |
schema|schemas|second_microsecond|select|sensitive|separator|show|signal|spatial|specific|sql|sqlexception|sqlstate|sqlwarning|sql_big_result|sql_calc_found_rows|sql_small_result|ssl|starting|stored|straight_join|system     |
terminated|then|trailing|trigger|true                                                                                                                                                                                           |
undo|union|unlock|update|usage|use|using|utc_date|utc_time|utc_timestamp                                                                                                                                                        |
values|varying|virtual                                                                                                                                                                                                          |
when|where|while|window|with|write                                                                                                                                                                                              |
xor                                                                                                                                                                                                                             |
year_month                                                                                                                                                                                                                      |
[ \t]+ ;
-?[0-9]+                { return INTLIT; }
-?[0-9]+"."[0-9]*               |               
-?"."[0-9]+                     |                     
-?[0-9]+E[-+]?[0-9]+            |            
-?[0-9]+"."[0-9]*E[-+]?[0-9]+   |   
-?"."[0-9]+E[-+]?[0-9]+ { return FLOATLIT; }

true|false|unknown      { return BOOLLIT; }
'(\\.|''|[^'\n])*'      |     
\"(\\.|\"\"|[^"\n])*\"  |  
X'[0-9A-F]+'            |              
0X[0-9A-F]+             |             
0B[01]+                 |                 
B'[01]+'                { return STRINGLIT; }
[0-9a-zA-Z$_]+          { return ID; }
\n                      { return NEWLINE; }
.                       { return *yytext; } 

%%

int yywrap(){
    return 1;
}