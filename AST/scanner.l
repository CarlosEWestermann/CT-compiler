/*UFRGS 2023*/
/* Grupo K*/
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

%{
#include "parser.tab.h"
%}

%option noyywrap
%option yylineno

%%

"//".* { }
"/*"([^*]|\*+[^*/])*\*+"/" { } 

[ \t] {}
\n {}

int {return TK_PR_INT;}
float return TK_PR_FLOAT;
bool return TK_PR_BOOL;
if return TK_PR_IF;
else return TK_PR_ELSE;
while return TK_PR_WHILE;
return return TK_PR_RETURN;

"<=" return TK_OC_LE;
">=" return TK_OC_GE;
"==" return TK_OC_EQ;
"!=" return TK_OC_NE;
"&" return TK_OC_AND;
"|" return TK_OC_OR;
"-" return '-';
"!" return '!';
"*" return '*';
"/" return '/';
"%" return '%';
"+" return '+';
"<" return '<';
">" return '>';
"{" return '{';
"}" return '}';
"(" return '(';
")" return ')';
"=" return '=';
"," return ',';
";" return ';';

[0-9]+ {
    yylval.valor_lexico.lineno = yylineno;
    yylval.valor_lexico.token_type = TK_LIT_INT;
    yylval.valor_lexico.token_value = strdup(yytext);
    return TK_LIT_INT;
}
([0-9]*\.[0-9]+|[0-9]+\.)?([0-9]+)? return TK_LIT_FLOAT;
"false" return TK_LIT_FALSE;
"true" return TK_LIT_TRUE;

[a-zA-Z_][a-zA-Z_0-9]* {
    yylval.valor_lexico.lineno = yylineno;
    yylval.valor_lexico.token_type = TK_IDENTIFICADOR;
    yylval.valor_lexico.token_value = strdup(yytext);
    return TK_IDENTIFICADOR;
}

. return TK_ERRO;

%%