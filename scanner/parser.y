%{
int yylex(void);
void yyerror (char const *mensagem);
%}

%define parse.error verbose

%token TK_PR_INT
%token TK_PR_FLOAT
%token TK_PR_BOOL
%token TK_PR_IF
%token TK_PR_ELSE
%token TK_PR_WHILE
%token TK_PR_RETURN
%token TK_OC_LE
%token TK_OC_GE
%token TK_OC_EQ
%token TK_OC_NE
%token TK_OC_AND
%token TK_OC_OR
%token TK_IDENTIFICADOR
%token TK_LIT_INT
%token TK_LIT_FLOAT
%token TK_LIT_FALSE
%token TK_LIT_TRUE
%token TK_ERRO

%%

program: list;
program: /* programa vazio */;

list: list element;
list: element;

element: function;
element: global_declaration;

global_declaration: type list_vars';' ;

type: TK_PR_INT;
type: TK_PR_FLOAT;
type: TK_PR_BOOL;

list_vars: list_vars',' TK_IDENTIFICADOR;
list_vars: TK_IDENTIFICADOR;

function: header body;

header: '('param_list')' TK_OC_GE type '!' TK_IDENTIFICADOR;
header: '('')' TK_OC_GE type '!' TK_IDENTIFICADOR;

param_list: param_list',' param;
param_list: param;

param: type TK_IDENTIFICADOR;

body: '{' '}'
body: '{' command_list '}'

command_list: command_list command;
command_list: command;

command: command_list;
command: TK_LIT_FALSE;

%%