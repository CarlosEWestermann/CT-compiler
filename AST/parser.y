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
                            if($2 != NULL)
                                append_program($$->code, $2->code); 
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
        insertSymbolGlobal(&stack, varList[i], lineList[i], IDENTIFIER, $1, "");
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

function: push_scope header no_scope_body pop_scope { $$ = $2; 
                                                      asd_add_child($$, $3);
                                                      if(strcmp($2->label, "main") == 0 && $3->code->size != 0){
                                                        $3->code->instructions[0].label = strdup("L1");
                                                        add_instruction_to_program($3->code, create_instruction(halt, NULL, NULL, NULL, NULL, 0));
                                                        set_main();
                                                      }
                                                      append_program($$->code, $3->code); };

header: '(' param_list ')' TK_OC_GE type '!' TK_IDENTIFICADOR { $$ = asd_new($7.token_value); 
                                                                insertSymbolGlobal(&stack, $7.token_value, $7.lineno, FUNCTION, $5, "");
                                                                free($7.token_value);}
        | '(' ')' TK_OC_GE type '!' TK_IDENTIFICADOR { $$ = asd_new($6.token_value); 
                                                       insertSymbolGlobal(&stack, $6.token_value, $6.lineno, FUNCTION, $4, ""); 
                                                       free($6.token_value); };

param_list: param {  }
            | param_list ',' param {  };

param: type TK_IDENTIFICADOR { insertSymbolWithScope(&stack, $2.token_value, $2.lineno, IDENTIFIER, $1, "");
                               free($2.token_value); }; 

no_scope_body: '{' '}' { $$ = NULL; }
    | '{'  command_list  '}' { $$ = $2; };

command_list: command { $$ = $1; }
            | command command_list {if ($1 == NULL){
                                        $$ = $2; }
                                    else {
                                        $$ = $1;
                                        while ($$->next!=NULL) {
                                            $$ = $$->next;
                                        }
                                        asd_add_child($$, $2);
                                        append_program($$->code, $2->code);
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

attrib: TK_IDENTIFICADOR '=' expr { $$ = asd_new("="); 
                                    asd_add_child($$, asd_new($1.token_value));
                                    asd_add_child($$, $3); 
                                    SymbolData *var = lookupSymbolWhenUsed(&stack, $1.token_value, $1.lineno, IDENTIFIER, $1.token_type, "");
                                    if(var->nature == FUNCTION){
                                            printf("Error: invalid expression! using %s of nature function in line %d in left side of expression. Function originally declared in line %d\n", $1.token_value, $1.lineno, var->line);
                                            exit(ERR_FUNCTION);
                                        }
                                    $$->type = var->type; 
                                    $$->offset = var->memory_offset;
                                    $$->is_global = var->is_global;
                                    append_program($$->code, $3->code);
                                    char temp_offset[80];
                                    sprintf(temp_offset, "%i", $$->offset);
                                    add_instruction_to_program($$->code, create_instruction(storeAI, $3->temp, $$->is_global ? "rbss" : "rfp", temp_offset, NULL, 3));
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
    | arg ',' arg_list { $$ = $1; asd_add_child($$, $3); append_program($$->code, $3->code); };

arg: expr { $$ = $1; };

return: TK_PR_RETURN expr { $$ = asd_new("return");
                            asd_add_child($$, $2); 
                            $$->type = $2->type; 
                            //append_program($$->code, $2->code);
                            };

conditional: TK_PR_IF '(' expr ')' no_scope_body { $$ = asd_new("if"); 
                                                   asd_add_child($$, $3); 
                                                   asd_add_child($$, $5); 
                                                   $$->type = $3->type; 
                                                   add_if($$, $3, $5); }

            | TK_PR_IF '(' expr ')' no_scope_body TK_PR_ELSE no_scope_body  { $$ = asd_new("if"); 
                                                                              asd_add_child($$, $3); 
                                                                              asd_add_child($$, $5); 
                                                                              asd_add_child($$, $7); 
                                                                              $$->type = $3->type;
                                                                              add_if_else($$, $3, $5, $7); }



while: TK_PR_WHILE '(' expr ')' no_scope_body { $$ = asd_new("while"); 
                                                asd_add_child($$, $3); 
                                                asd_add_child($$, $5);
                                                add_while($$, $3, $5);
                                                $$->type = $3->type;}

expr: logical_or_expr { $$ = $1; };

logical_or_expr: logical_and_expr { $$ = $1; }
    | logical_or_expr TK_OC_OR logical_and_expr {$$ = asd_new("|"); 
                                                asd_add_child($$, $1); 
                                                asd_add_child($$, $3); 
                                                $$->type = inferType($1->type, $3->type);
                                                add_binop($$, $1, $3, or); 
                                                };

logical_and_expr: equality_expr { $$ = $1; }
    | logical_and_expr TK_OC_AND equality_expr { $$ = asd_new("&"); 
                                                 asd_add_child($$, $1); 
                                                 asd_add_child($$, $3); 
                                                 $$->type = inferType($1->type, $3->type);
                                                 add_binop($$, $1, $3, and); 
                                                 };

equality_expr: relational_expr { $$ = $1; }
    | equality_expr TK_OC_EQ relational_expr { $$ = asd_new("=="); 
                                               asd_add_child($$, $1); 
                                               asd_add_child($$, $3); 
                                               $$->type = inferType($1->type, $3->type);
                                               add_binop($$, $1, $3, cmp_eq); 
                                               }

    | equality_expr TK_OC_NE relational_expr { $$ = asd_new("!="); 
                                               asd_add_child($$, $1); 
                                               asd_add_child($$, $3); 
                                               $$->type = inferType($1->type, $3->type);
                                               add_binop($$, $1, $3, cmp_ne);
                                               };

relational_expr: add_sub_expr { $$ = $1; }
    | relational_expr '<' add_sub_expr { $$ = asd_new("<"); 
                                         asd_add_child($$, $1); 
                                         asd_add_child($$, $3); 
                                         $$->type = inferType($1->type, $3->type);
                                         add_binop($$, $1, $3, lt);
                                          }

    | relational_expr '>' add_sub_expr { $$ = asd_new(">"); 
                                         asd_add_child($$, $1); 
                                         asd_add_child($$, $3); 
                                         $$->type = inferType($1->type, $3->type);
                                         add_binop($$, $1, $3, gt);
                                         }

    | relational_expr TK_OC_LE add_sub_expr { $$ = asd_new("<="); 
                                              asd_add_child($$, $1); 
                                              asd_add_child($$, $3); 
                                              $$->type = inferType($1->type, $3->type);
                                              add_binop($$, $1, $3, le);
                                              }

    | relational_expr TK_OC_GE add_sub_expr { $$ = asd_new(">="); 
                                              asd_add_child($$, $1); 
                                              asd_add_child($$, $3); 
                                              $$->type = inferType($1->type, $3->type);
                                              add_binop($$, $1, $3, ge);
                                              };

add_sub_expr: mult_div_mod_expr { $$ = $1; }
    | add_sub_expr '+' mult_div_mod_expr { $$ = asd_new("+"); 
                                           asd_add_child($$, $1); 
                                           //append_program($$->code, $1->code);
                                           asd_add_child($$, $3); 
                                           //append_program($$->code, $3->code);
                                           $$->type = inferType($1->type, $3->type);
                                           add_binop($$, $1, $3, add);
                                           }

    | add_sub_expr '-' mult_div_mod_expr { $$ = asd_new("-"); 
                                           asd_add_child($$, $1); 
                                           asd_add_child($$, $3); 
                                           $$->type = inferType($1->type, $3->type);
                                           add_binop($$, $1, $3, sub);
                                            };

mult_div_mod_expr: unary_expr { $$ = $1; }
    | mult_div_mod_expr '*' unary_expr { $$ = asd_new("*"); 
                                         asd_add_child($$, $1); 
                                         asd_add_child($$, $3); 
                                         $$->type = inferType($1->type, $3->type);
                                         add_binop($$, $1, $3, mul);
                                         }

    | mult_div_mod_expr '/' unary_expr { $$ = asd_new("/"); 
                                         asd_add_child($$, $1); 
                                         asd_add_child($$, $3); 
                                         $$->type = inferType($1->type, $3->type);
                                         add_binop($$, $1, $3, divi); 
                                         }

    | mult_div_mod_expr '%' unary_expr { $$ = asd_new("%"); 
                                         asd_add_child($$, $1); 
                                         asd_add_child($$, $3); 
                                         $$->type = inferType($1->type, $3->type);};

unary_expr: primary_expr { $$ = $1; }
        | '-' unary_expr %prec UMINUS { $$ = asd_new("-"); 
                                        asd_add_child($$, $2); 
                                        $$->type = $2->type; }

        | '!' unary_expr { $$ = asd_new("!"); 
                           asd_add_child($$, $2); 
                           $$->type = $2->type; };

primary_expr: TK_IDENTIFICADOR { 
        $$ = asd_new($1.token_value);     
        SymbolData *var = lookupSymbolWhenUsed(&stack, $1.token_value, $1.lineno, IDENTIFIER, $1.token_type, "");
        if(var->nature == FUNCTION){
            printf("Error: invalid expression! using %s of nature FUNCAO in line %d in left side of expression.. Function originally declared in line %d\n", $1.token_value, $1.lineno, var->line);
            exit(ERR_FUNCTION);
        }
        $$->type = var->type; 
        $$->offset = var->memory_offset;
        $$->is_global = var->is_global;
        char* temp_register = generate_register();
        char temp_offset[80];
        sprintf(temp_offset, "%i", $$->offset);
        add_instruction_to_program($$->code, create_instruction(loadAI, $$->is_global ? "rbss" : "rfp", temp_offset, temp_register, NULL, 3));
        $$->temp = temp_register;
        free($1.token_value); 
        }
    | TK_LIT_INT { $$ = asd_new($1.token_value);  $$->type = INT; 
                    char* temp_register = generate_register();
  
    add_instruction_to_program($$->code, create_instruction(loadI, $1.token_value, temp_register, NULL, NULL, 2));
    $$->temp = temp_register;
    free($1.token_value);
    //free(temp_register);
    }
    | TK_LIT_FLOAT { $$ = asd_new($1.token_value); free($1.token_value); $$->type = FLOAT; }
    | TK_LIT_TRUE { $$ = asd_new($1.token_value); free($1.token_value); $$->type = BOOL; }
    | TK_LIT_FALSE { $$ = asd_new($1.token_value); free($1.token_value); $$->type = BOOL; }
    | function_call { $$ = $1; }
    | '(' expr ')' { $$ = $2; };

%%