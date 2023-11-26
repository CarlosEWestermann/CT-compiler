/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

%code requires { #include "asd.h" }

%{
    int yylex(void);
    void yyerror (char const *mensagem);
%}

%define parse.error verbose

%token UMINUS

%union {
    struct {
        int lineno;
        int token_type;
        char* token_value;
    } valor_lexico;
}

%token TK_PR_INT TK_PR_FLOAT TK_PR_BOOL TK_PR_IF TK_PR_ELSE TK_PR_WHILE TK_PR_RETURN
%token TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE TK_OC_AND TK_OC_OR
%token TK_IDENTIFICADOR TK_LIT_INT TK_LIT_FLOAT TK_LIT_FALSE TK_LIT_TRUE TK_ERRO

%%

program: /* empty */
    | program element { $$ = asd_new($$, $1); asd_add_child($$, $2); };

element: function { $$ = $1; }
    | global_declaration { $$ = $1; };

global_declaration: type list_vars ';' { $$ = $2; };

type: TK_PR_INT
    | TK_PR_FLOAT
    | TK_PR_BOOL;

list_vars: TK_IDENTIFICADOR { $$ = $1; }
         | list_vars ',' TK_IDENTIFICADOR { $$ = asd_new(","); asd_add_child($$, $1); asd_add_child($$, $3); };

function: header body { $$ = asd_new($$, $1); asd_add_child($$, $2); };

header: '(' param_list ')' TK_OC_GE type '!' function_name { $$ = asd_new($$, $7); asd_add_child($$, $2); }
       | '(' ')' TK_OC_GE type '!' TK_IDENTIFICADOR { $$ = $6; };

function_name: TK_IDENTIFICADOR { $$ = $1; };

param_list: param { $$ = $1; }
           | param_list ',' param { $$ = asd_new(","); asd_add_child($$, $1); asd_add_child($$, $3); };

param: type TK_IDENTIFICADOR { $$ = $2; }; 

body: '{' '}'
    | '{' command_list '}' { $$ = $2; };

command_list: command { $$ = $1; }
            | '{' command '}'';' { $$ = $2; }
            | '{' command_list command '}'';' { $$ = asd_new($$, $2); asd_add_child($$, $3); }
            | command_list command { $$ = asd_new($$, $1); asd_add_child($$, $2); }
            | command_list '{' command '}'';' { $$ = asd_new($$, $1); asd_add_child($$, $3); }
            | command_list '{''}'';' { $$ = $1; }
            | '{''}'';';

command: local_var_dec ';' { $$ = $1; }
       | attrib ';' { $$ = $1; }
       | conditional ';' { $$ = $1; }
       | while ';' { $$ = $1; }
       | return ';' { $$ = $1; }
       | function_call ';' { $$ = $1; } ;

local_var_dec: type list_vars { $$ = $2; };

attrib: TK_IDENTIFICADOR '=' expr { $$ = asd_new("="); asd_add_child($$, $1); asd_add_child($$, $3); };

function_call: TK_IDENTIFICADOR '(' arg_list ')' { $$ = asd_new($1); asd_add_child($$, $3); }
    | TK_IDENTIFICADOR '(' ')' { $$ = $1; };

arg_list: arg { $$ = $1; }
    | arg_list ',' arg { $$ = asd_new(","); asd_add_child($$, $1); asd_add_child($$, $3); };

arg: expr { $$ = $1; };

return: TK_PR_RETURN expr { $$ = asd_new("return"); asd_add_child($$, $2); };

conditional: TK_PR_IF '(' expr ')' body { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $5); }
            | TK_PR_IF '(' expr ')' body TK_PR_ELSE body  { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $5); asd_add_child($$, $7); };

while: TK_PR_WHILE '(' expr ')' body { $$ = asd_new("while"); asd_add_child($$, $3); asd_add_child($$, $5); };

expr: logical_or_expr { $$ = $1; };

logical_or_expr: logical_and_expr { $$ = $1; }
    | logical_or_expr TK_OC_OR logical_and_expr {$$ = asd_new("||"); asd_add_child($$, $1); asd_add_child($$, $3); };

logical_and_expr: equality_expr { $$ = $1; }
    | logical_and_expr TK_OC_AND equality_expr { $$ = asd_new("&&"); asd_add_child($$, $1); asd_add_child($$, $3); };

equality_expr: relational_expr { $$ = $1; }
    | equality_expr TK_OC_EQ relational_expr { $$ = asd_new("=="); asd_add_child($$, $1); asd_add_child($$, $3); }
    | equality_expr TK_OC_NE relational_expr { $$ = asd_new("!="); asd_add_child($$, $1); asd_add_child($$, $3); };

relational_expr: add_sub_expr { $$ = $1; }
    | relational_expr '<' add_sub_expr { $$ = asd_new("<"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | relational_expr '>' add_sub_expr { $$ = asd_new(">"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | relational_expr TK_OC_LE add_sub_expr { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); }
    | relational_expr TK_OC_GE add_sub_expr { $$ = asd_new(">="); asd_add_child($$, $1); asd_add_child($$, $3); };

add_sub_expr: mult_div_mod_expr { $$ = $1; }
    | add_sub_expr '+' mult_div_mod_expr { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | add_sub_expr '-' mult_div_mod_expr { $$ = asd_new("-"); asd_add_child($$, $1); asd_add_child($$, $3); };

mult_div_mod_expr: unary_expr { $$ = $1; }
    | mult_div_mod_expr '*' unary_expr { $$ = asd_new("*"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | mult_div_mod_expr '/' unary_expr { $$ = asd_new("\/"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | mult_div_mod_expr '%' unary_expr { $$ = asd_new("\%"); asd_add_child($$, $1); asd_add_child($$, $3); };

unary_expr: primary_expr { $$ = $1; }
          | '-' unary_expr %prec UMINUS { $$ = asd_new("-"); asd_add_child($$, $2); }
          | '!' unary_expr { $$ = asd_new("!"); asd_add_child($$, $2); };

primary_expr: TK_IDENTIFICADOR { $$ = $1; }
    | TK_LIT_INT { $$ = $1; }
    | TK_LIT_FLOAT { $$ = $1; }
    | TK_LIT_TRUE { $$ = $1; }
    | TK_LIT_FALSE { $$ = $1; }
    | function_call { $$ = $1; }
    | '(' expr ')' { $$ = $2; };

%%
