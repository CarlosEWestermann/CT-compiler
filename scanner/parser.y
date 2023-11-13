%{
    int yylex(void);
    void yyerror (char const *mensagem);
%}

%define parse.error verbose

%token UMINUS

%token TK_PR_INT TK_PR_FLOAT TK_PR_BOOL TK_PR_IF TK_PR_ELSE TK_PR_WHILE TK_PR_RETURN
%token TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE TK_OC_AND TK_OC_OR
%token TK_IDENTIFICADOR TK_LIT_INT TK_LIT_FLOAT TK_LIT_FALSE TK_LIT_TRUE TK_ERRO

%%

program: /* empty */
    | program element;

element: function
    | global_declaration;

global_declaration: type list_vars ';';

type: TK_PR_INT
    | TK_PR_FLOAT
    | TK_PR_BOOL;

list_vars: TK_IDENTIFICADOR
         | list_vars ',' TK_IDENTIFICADOR;

function: header body;

header: '(' param_list ')' TK_OC_GE type '!' function_name
       | '(' ')' TK_OC_GE type '!' TK_IDENTIFICADOR;

function_name: TK_IDENTIFICADOR;

param_list: param
           | param_list ',' param;

param: type TK_IDENTIFICADOR;

body: '{' '}'
    | '{' command_list '}';

command_list: command
            | command_list command;

command: local_var_dec ';'
       | attrib ';'
       | conditional ';'
       | while ';'
       | return ';'
       | function_call ';';

local_var_dec: type list_vars;

attrib: TK_IDENTIFICADOR '=' expr;

function_call: TK_IDENTIFICADOR '(' arg_list ')'
    | TK_IDENTIFICADOR '(' ')';

arg_list: arg
    | arg_list ',' arg;

arg: expr;

return: TK_PR_RETURN expr;

conditional: TK_PR_IF '(' expr ')' '{' command_list '}'
            | TK_PR_IF '(' expr ')' '{' command_list '}' TK_PR_ELSE '{' command_list '}';

while: TK_PR_WHILE '(' expr ')' '{' command_list '}';

expr: logical_or_expr;

logical_or_expr: logical_and_expr
    | logical_or_expr TK_OC_OR logical_and_expr;

logical_and_expr: equality_expr
    | logical_and_expr TK_OC_AND equality_expr;

equality_expr: relational_expr
    | equality_expr TK_OC_EQ relational_expr
    | equality_expr TK_OC_NE relational_expr;

relational_expr: add_sub_expr
    | relational_expr '<' add_sub_expr
    | relational_expr '>' add_sub_expr
    | relational_expr TK_OC_LE add_sub_expr
    | relational_expr TK_OC_GE add_sub_expr;

add_sub_expr: mult_div_mod_expr
    | add_sub_expr '+' mult_div_mod_expr
    | add_sub_expr '-' mult_div_mod_expr;

mult_div_mod_expr: unary_expr
    | mult_div_mod_expr '*' unary_expr
    | mult_div_mod_expr '/' unary_expr
    | mult_div_mod_expr '%' unary_expr;

unary_expr: primary_expr
    | '-' primary_expr %prec UMINUS
    | '!' primary_expr;

primary_expr: TK_IDENTIFICADOR
    | TK_LIT_INT
    | TK_LIT_FLOAT
    | TK_LIT_TRUE
    | TK_LIT_FALSE
    | function_call
    | '(' expr ')';


%%
