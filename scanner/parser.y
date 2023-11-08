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

header: '('param_list')' TK_OC_GE type '!' functin_name;
header: '('')' TK_OC_GE type '!' TK_IDENTIFICADOR;

function_name: TK_IDENTIFICADOR;

param_list: param_list',' param;
param_list: param;

param: type TK_IDENTIFICADOR;

body: '{' '}'
body: '{' command_list '}'

command_list: command_list command;
command_list: command;

command: command_list;
command: local_var_dec';';
command: attrib';';
command: conditional';';
command: while';';
command: return';';
command: function_call';';

local_var_dec: type list_vars;

attrib: TK_IDENTIFICADOR '=' expr;

function_call: function_name '('arg_list')';
function_call: function_name '('')';

arg_list: arg_list',' arg;
arg_list: arg;

arg: expr;
arg: TK_IDENTIFICADOR;

return: TK_PR_RETURN expr;

conditional: TK_PR_IF '('expr')' '{'command_list'}';
conditional: TK_PR_IF '('expr')' '{'command_list'}' TK_PR_ELSE '{'command_list'}'

while: TK_PR_WHILE '('expr')' '{'command_list'}';

expr: operator;
expr: boolean;
expr: operand operator;

boolean: TK_LIT_FALSE;
boolean: TK_LIT_TRUE;
numeric: TK_LIT_FLOAT;
numeric: TK_LIT_INT; 
operand: function_call;

operator: unop;
operator: binop;

unop: '-'numeric expr;
//pode? perguntar
unop: '-'TK_IDENTIFICADOR expr;

unop: '!';
binop: '*';
binop: '/';
binop: '%';
binop: '+';
binop: '-';
binop: '<';
binop: '>';
binop: TK_OC_LE;
binop: TK_OC_GE;
binop: TK_OC_EQ;
binop: TK_OC_NE;
binop: TK_OC_AND;
binop: TK_OC_OR;


%%