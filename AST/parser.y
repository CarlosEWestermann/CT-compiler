/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

%code top { #include "symbol_table.h"
            #include <stdlib.h> }

%code requires { #include "AST_functions.h" }
%{
    int yylex(void);
    void yyerror (char const *mensagem);
    extern void *arvore;
    extern TableStack stack; 
    char *varList[100] = {NULL};
    int lineList[100] = {-1};
%}

%define parse.error verbose

%token UMINUS

%union {
    lexical_value_t lexical_value;
    asd_tree_t *tree;
    SymbolType type;
}

%token <lexical_value> TK_PR_INT TK_PR_FLOAT TK_PR_BOOL TK_PR_IF TK_PR_ELSE TK_PR_WHILE TK_PR_RETURN
%token TK_OC_LE TK_OC_GE TK_OC_EQ TK_OC_NE TK_OC_AND TK_OC_OR
%token <lexical_value> TK_IDENTIFICADOR TK_LIT_INT TK_LIT_FLOAT TK_LIT_FALSE TK_LIT_TRUE 
%token TK_ERRO

%type <tree> program
%type <tree> init
%type <tree> element
%type <tree> global_declaration
%type <type> type
%type <tree> list_vars
%type <tree> function
%type <tree> header
%type <tree> param_list
%type <tree> param
%type <tree> no_scope_body
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

program: push_scope init pop_scope {
    $$ = $2;
}

init: /* empty */ { $$ = NULL; }
    | element init  {
                        if($1 != NULL) {
                            $$ = $1; 
                            asd_add_child($$, $2); 
                        } else {
                            $$ = $2;
                        } 

                        arvore = $$;
                        };

push_scope: { pushScope(&stack); };

pop_scope: { popScope(&stack); };

element: function { $$ = $1; }
    | global_declaration { $$ = $1; };

global_declaration: type list_vars ';' { 
    $$ = $2; 
    int i = 0;
    while(varList[i] != NULL && i < 100){
        insertSymbolWithScope(&stack, varList[i], lineList[i], IDENTIFIER, $1, "");
        i++;
    }
    for(i = 0; i < 100; i++){
        if(varList[i] != NULL){
            free(varList[i]);
            lineList[i] = -1;
            varList[i] = NULL;
        }
    }
};

type: TK_PR_INT { $$ = INT; }
    | TK_PR_FLOAT { $$ = FLOAT; }
    | TK_PR_BOOL { $$ = BOOL; };

list_vars: TK_IDENTIFICADOR {   $$ = NULL; 
                                int i = 0;
                                while(varList[i] != NULL){
                                    i++;
                                    if(i == 100){
                                        printf("too many variables declared!");
                                        exit(-1);
                                    }
                                }
                                varList[i] = malloc(strlen($1.token_value) + 1);
                                strncpy(varList[i], $1.token_value, strlen($1.token_value));
                                varList[i][strlen($1.token_value)] = '\0';
                                lineList[i] = $1.lineno;
                                free($1.token_value);
                                }
        | list_vars ',' TK_IDENTIFICADOR { $$ = $1; 
                                            int i = 0;
                                            while(varList[i] != NULL){
                                                i++;
                                                if(i == 100){
                                                    printf("too many variables declared!");
                                                    exit(-1);
                                                }
                                            }
                                            varList[i] = malloc(strlen($3.token_value) + 1);
                                            strncpy(varList[i], $3.token_value, strlen($3.token_value));
                                            varList[i][strlen($3.token_value)] = '\0';
                                            lineList[i] = $3.lineno;
                                            free($3.token_value); };

function: push_scope header no_scope_body pop_scope { $$ = $2; asd_add_child($$, $3); };

header: '(' param_list ')' TK_OC_GE type '!' TK_IDENTIFICADOR { $$ = asd_new($7.token_value); insertSymbolGlobal(&stack, $7.token_value, $7.lineno, FUNCTION, $5, ""); /* $$->type = $5; */  free($7.token_value);}
        | '(' ')' TK_OC_GE type '!' TK_IDENTIFICADOR { $$ = asd_new($6.token_value); insertSymbolGlobal(&stack, $6.token_value, $6.lineno, FUNCTION, $4, ""); /* $$->type = $4; */ free($6.token_value); };

param_list: param {  }
            | param_list ',' param {  };

param: type TK_IDENTIFICADOR { insertSymbolWithScope(&stack, $2.token_value, $2.lineno, IDENTIFIER, $1, ""); free($2.token_value); }; 

no_scope_body: '{' '}' { $$ = NULL; }
    | '{'  command_list  '}' { $$ = $2; };

command_list: command { $$ = $1; }
            | command command_list {if ($1 == NULL){
                    $$ = $2;
                }
                else {
                    $$ = $1;
                    while ($$->next!=NULL) {
                        $$ = $$->next;
                    }
                    asd_add_child($$, $2);
                    $$->next=$2;
                    $$ = $1;
                };}



command: local_var_dec ';' { $$ = $1; }
        | attrib ';' { $$ = $1; }
        | conditional ';' { $$ = $1; }
        | while ';' { $$ = $1; }
        | return ';' { $$ = $1; }
        | function_call ';' { $$ = $1; }
        | open_block { $$ = $1; };

open_block: '{''}'';' { $$ = NULL; }
            | '{' push_scope command_list pop_scope '}'';' { $$ = $3; };


local_var_dec: type list_vars { 
    $$ = $2; 
    int i = 0;
    while(varList[i] != NULL && i < 100){
        insertSymbolWithScope(&stack, varList[i], lineList[i], IDENTIFIER, $1, "");
        i++;
    }
    for(i = 0; i < 100; i++){
        if(varList[i] != NULL){
            free(varList[i]);
            varList[i] = NULL;
            lineList[i] = -1;
        }
    } };

attrib: TK_IDENTIFICADOR '=' expr { $$ = asd_new("="); asd_add_child($$, asd_new($1.token_value)); asd_add_child($$, $3); 
    SymbolData *var = lookupSymbolWhenUsed(&stack, $1.token_value, $1.lineno, IDENTIFIER, $1.token_type, "");
    if(var->nature == FUNCTION){
            printf("Error: invalid expression! using %s of nature FUNCAO in line %d in left side of expression. Function originally declared in line %d\n", $1.token_value, $1.lineno, var->line);
            exit(ERR_FUNCTION);
        }
    $$->type = var->type;
    free($1.token_value);
};

function_call: TK_IDENTIFICADOR '(' arg_list ')' { 
                    char *buffer = malloc((strlen("call ") + strlen($1.token_value) + 1)* sizeof(char));
                    strcpy(buffer, "call ");
                    strcat(buffer, $1.token_value);
                    $$ = asd_new(buffer);
                    asd_add_child($$, $3);
                    free(buffer);
                    SymbolData *var = lookupSymbolWhenUsed(&stack, $1.token_value, $1.lineno, FUNCTION, $1.token_type, "");
                    if(var->nature == IDENTIFIER){
                        printf("Error: invalid function call %s() in line %d. Identifier was originally declared in line %d\n", $1.token_value, $1.lineno, var->line);
                        exit(ERR_VARIABLE);
                        }
                    $$->type = var->type; 
                    free($1.token_value);
                    }
                | TK_IDENTIFICADOR '(' ')' { 
                        char *buffer = malloc((strlen("call ") + strlen($1.token_value) + 1)* sizeof(char));
                        strcpy(buffer, "call ");
                        strcat(buffer, $1.token_value);
                        $$ = asd_new(buffer);
                        free(buffer);
                        SymbolData *var = lookupSymbolWhenUsed(&stack, $1.token_value, $1.lineno, FUNCTION, $1.token_type, "");
                        if(var->nature == IDENTIFIER){
                        printf("Error: invalid function call %s() in line %d. Identifier was originally declared in line %d\n", $1.token_value, $1.lineno, var->line);
                        exit(ERR_VARIABLE);
                        }
                        $$->type = var->type; 
                        free($1.token_value);
                    };


arg_list: arg { $$ = $1; }
    | arg ',' arg_list { $$ = $1; asd_add_child($$, $3); };

arg: expr { $$ = $1; };

return: TK_PR_RETURN expr { $$ = asd_new("return"); asd_add_child($$, $2); $$->type = $2->type; };

conditional: TK_PR_IF '(' expr ')' no_scope_body { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $5); $$->type = $3->type; 
                                                    /*//outline do codigo
                                                    zeroReg = geraTemp() r1
                                                    compReg = geraTemp() r2 
                                                    labelTrue = geraLabel() l1
                                                    labelFalse = geraLabel() l2
                                                    $$.code = "loadI 0 => %s", zeroReg ||
                                                    $3.code ||
                                                    "cmp_ne %s, %s => %s", zeroReg, $3.temp, compReg ||
                                                    "cbr %s => %s, %s", compReg, labelTrue, labelFalse ||
                                                    labelTrue ||
                                                    $5.code ||
                                                    labelFalse */ 
                                                    
                                                    */int zero_register_id = generate_register();
                                                    int comparison_register_id = generate_register();
                                                    int label_true_id = generate_label();
                                                    int label_false_id = generate_label();
                                                    
                                                    char label_true[10], label_false[10], zero_register[10], comparison_register[10];
                                                    sprintf(label_true, "L%d", label_true_id);
                                                    sprintf(label_false, "L%d", label_false_id);
                                                    sprintf(zero_register, "R%d", zero_register_id);
                                                    sprintf(comparison_register, "R%d", comparison_register_id);
                                                
                                                    sprintf($$.code, "loadI 0 => r%s\n", zero_register);
                                                    strcat($$.code, $3.code);

                                                    char[100] cmp_ne_code;
                                                    sprintf(cmp_code, "cmp_ne %s, R%d => %s", zero_register, $3.temp, comparison_register)
                                                    strcat($$.code, cmp_ne_code);

                                                    char[100] cbr_code;
                                                    sprintf(cbr_code, "cbr %s => %s, %s", comparison_register, label_true, label_false);
                                                    strcat($$.code, cmp_code);

                                                    strcat($$.code, label_true);
                                                    strcat($$.code, $5.code);
                                                    strcat($$.code, label_false);*/
                                                    }
            | TK_PR_IF '(' expr ')' no_scope_body TK_PR_ELSE no_scope_body  { $$ = asd_new("if"); asd_add_child($$, $3); asd_add_child($$, $5); asd_add_child($$, $7); $$->type = $3->type; }

/*
if ( a == b ) { }
loadI 0 => r1
loadi 2 => r0
loadi 2 => r-1
cmp_eq r0 r-1 => r3 ($3.temp)
cmp_ne r1 r3 => r2
cbr r2 => l1, l2
l1:
lalala
l2:
*/

while: TK_PR_WHILE '(' expr ')' no_scope_body { $$ = asd_new("while"); asd_add_child($$, $3); asd_add_child($$, $5); $$->type = $3->type;}

expr: logical_or_expr { $$ = $1; };

logical_or_expr: logical_and_expr { $$ = $1; }
    | logical_or_expr TK_OC_OR logical_and_expr {$$ = asd_new("|"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);};

logical_and_expr: equality_expr { $$ = $1; }
    | logical_and_expr TK_OC_AND equality_expr { $$ = asd_new("&"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);};

equality_expr: relational_expr { $$ = $1; }
    | equality_expr TK_OC_EQ relational_expr { $$ = asd_new("=="); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);}
    | equality_expr TK_OC_NE relational_expr { $$ = asd_new("!="); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);};

relational_expr: add_sub_expr { $$ = $1; }
    | relational_expr '<' add_sub_expr { $$ = asd_new("<"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);}
    | relational_expr '>' add_sub_expr { $$ = asd_new(">"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);}
    | relational_expr TK_OC_LE add_sub_expr { $$ = asd_new("<="); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);}
    | relational_expr TK_OC_GE add_sub_expr { $$ = asd_new(">="); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);};

add_sub_expr: mult_div_mod_expr { $$ = $1; }
    | add_sub_expr '+' mult_div_mod_expr { $$ = asd_new("+"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);}
    | add_sub_expr '-' mult_div_mod_expr { $$ = asd_new("-"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);};

mult_div_mod_expr: unary_expr { $$ = $1; }
    | mult_div_mod_expr '*' unary_expr { $$ = asd_new("*"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);}
    | mult_div_mod_expr '/' unary_expr { $$ = asd_new("/"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);}
    | mult_div_mod_expr '%' unary_expr { $$ = asd_new("%"); asd_add_child($$, $1); asd_add_child($$, $3); $$->type = inferType($1->type, $3->type);};

unary_expr: primary_expr { $$ = $1; }
        | '-' unary_expr %prec UMINUS { $$ = asd_new("-"); asd_add_child($$, $2); $$->type = $2->type; }
        | '!' unary_expr { $$ = asd_new("!"); asd_add_child($$, $2); $$->type = $2->type; };

primary_expr: TK_IDENTIFICADOR { $$ = asd_new($1.token_value);     
        SymbolData *var = lookupSymbolWhenUsed(&stack, $1.token_value, $1.lineno, IDENTIFIER, $1.token_type, "");
        if(var->nature == FUNCTION){
            printf("Error: invalid expression! using %s of nature FUNCAO in line %d in left side of expression.. Function originally declared in line %d\n", $1.token_value, $1.lineno, var->line);
            exit(ERR_FUNCTION);
        }
        $$->type = var->type; 
        free($1.token_value); 
        }
    | TK_LIT_INT { $$ = asd_new($1.token_value); free($1.token_value); $$->type = INT; }
    | TK_LIT_FLOAT { $$ = asd_new($1.token_value); free($1.token_value); $$->type = FLOAT; }
    | TK_LIT_TRUE { $$ = asd_new($1.token_value); free($1.token_value); $$->type = BOOL; }
    | TK_LIT_FALSE { $$ = asd_new($1.token_value); free($1.token_value); $$->type = BOOL; }
    | function_call { $$ = $1; }
    | '(' expr ')' { $$ = $2; };

%%