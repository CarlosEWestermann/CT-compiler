/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

%code requires { #include "AST_functions.h" }

%{
    int yylex(void);
    void yyerror (char const *mensagem);
    extern void *arvore;
%}

%define parse.error verbose

%token UMINUS

%union {
    lexical_value_t lexical_value;
    asd_tree_t *tree;
}

%token TK_PR_INT TK_PR_FLOAT TK_PR_BOOL TK_PR_IF TK_PR_ELSE TK_PR_WHILE TK_PR_RETURN
%token TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE TK_OC_AND TK_OC_OR
%token <lexical_value> TK_IDENTIFICADOR TK_LIT_INT TK_LIT_FLOAT TK_LIT_FALSE TK_LIT_TRUE 
%token TK_ERRO

%type <tree> program
%type <tree> element
%type <tree> global_declaration
%type <tree> type
%type <tree> list_vars
%type <tree> function
%type <tree> header
%type <tree> function_name
%type <tree> param_list
%type <tree> param
%type <tree> body
%type <tree> command_list
%type <tree> command
%type <tree> local_var_dec
%type <tree> attrib
%type <tree> function_call
%type <tree> arg_list
%type <tree> arg
%type <tree> return
%type <tree> conditional
%type <tree> while
%type <tree> expr
%type <tree> logical_or_expr
%type <tree> logical_and_expr
%type <tree> equality_expr
%type <tree> relational_expr
%type <tree> add_sub_expr
%type <tree> mult_div_mod_expr
%type <tree> unary_expr
%type <tree> primary_expr
%type <tree> open_block


%%

program: /* empty */ { $$ = NULL;  }
    | program element { if($1 != NULL) {
                            $$ = $1; 
                            asd_add_child($$, $2); 
                        } else {
                            $$ = $2;
                        } 
                        arvore = $$; };

element: function { $$ = $1; }
    | global_declaration { $$ = $1; };

global_declaration: type list_vars ';' { $$ = $2; };

type: TK_PR_INT {  }
    | TK_PR_FLOAT {  }
    | TK_PR_BOOL {  };

list_vars: TK_IDENTIFICADOR { $$ = asd_new($1.token_value); free($1.token_value);}
         | list_vars ',' TK_IDENTIFICADOR { $$ = $1; asd_add_child($$, asd_new($3.token_value)); free($3.token_value);};

function: header body { $$ = $1; asd_add_child($$, $2); };

header: '(' param_list ')' TK_OC_GE type '!' function_name { $$ = $7; asd_add_child($$, $2); }
       | '(' ')' TK_OC_GE type '!' TK_IDENTIFICADOR { $$ = asd_new($6.token_value); free($6.token_value);};

function_name: TK_IDENTIFICADOR { $$ = asd_new($1.token_value); free($1.token_value);};

param_list: param { $$ = $1; }
           | param_list ',' param { $$ = asd_new(","); asd_add_child($$, $1); asd_add_child($$, $3); };

param: type TK_IDENTIFICADOR { $$ = asd_new($2.token_value); free($2.token_value);}; 

body: '{' '}' { $$ = asd_new("@empty_body"); }
    | '{' command_list '}' { $$ = $2; };

command_list: command { $$ = $1; }
            | command_list command { $$ = $1; asd_add_child($$, $2); }

command: local_var_dec ';' { $$ = $1; }
       | attrib ';' { $$ = $1; }
       | conditional ';' { $$ = $1; }
       | while ';' { $$ = $1; }
       | return ';' { $$ = $1; }
       | function_call ';' { $$ = $1; }
       | open_block { $$ = $1; };

open_block: '{''}'';' { $$ = asd_new("@empty_body"); }
          | '{' command_list '}'';' { $$ = $2; };



local_var_dec: type list_vars { $$ = $2; };

attrib: TK_IDENTIFICADOR '=' expr { $$ = asd_new("="); asd_add_child($$, asd_new($1.token_value)); asd_add_child($$, $3); free($1.token_value);};

function_call: TK_IDENTIFICADOR '(' arg_list ')' { $$ = asd_new($1.token_value); asd_add_child($$, $3); free($1.token_value);}
    | TK_IDENTIFICADOR '(' ')' { $$ = asd_new($1.token_value); free($1.token_value);};

arg_list: arg { $$ = $1; }
    | arg_list ',' arg { $$ = $1; asd_add_child($$, $3); };

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
    | mult_div_mod_expr '/' unary_expr { $$ = asd_new("/"); asd_add_child($$, $1); asd_add_child($$, $3); }
    | mult_div_mod_expr '%' unary_expr { $$ = asd_new("%"); asd_add_child($$, $1); asd_add_child($$, $3); };

unary_expr: primary_expr { $$ = $1; }
          | '-' unary_expr %prec UMINUS { $$ = asd_new("-"); asd_add_child($$, $2); }
          | '!' unary_expr { $$ = asd_new("!"); asd_add_child($$, $2); };

primary_expr: TK_IDENTIFICADOR { $$ = asd_new($1.token_value); free($1.token_value); }
    | TK_LIT_INT { $$ = asd_new($1.token_value); free($1.token_value);}
    | TK_LIT_FLOAT { $$ = asd_new($1.token_value); free($1.token_value);}
    | TK_LIT_TRUE { $$ = asd_new($1.token_value); free($1.token_value);}
    | TK_LIT_FALSE { $$ = asd_new($1.token_value); free($1.token_value);}
    | function_call { $$ = $1; }
    | '(' expr ')' { $$ = $2; };

%%
