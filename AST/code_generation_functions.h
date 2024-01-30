/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#ifndef CODE_GENERATION_FUNCTIONS_HPP
#define CODE_GENERATION_FUNCTIONS_HPP

#include <stdio.h>
#include "AST_functions.h"

typedef enum {
    rfp,  
    rsp,  
    rbss, 
    rpc, 
} iloc_register_t;

typedef struct {
    int instruction;
    int r1;
    int r2;
    int r3;
} instruction_t;

typedef struct {
    instruction_t *instructions;
    int length;
} program_t;

int generate_label();
int generate_register();

void add_if(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body);
void add_if_else(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *if_body, asd_tree_t *else_body);
void add_or(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_and(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_equals(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_not_equal(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_less_than(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_greater_than(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_less_equal(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_greater_equal(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_sub(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_add(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_mult(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
void add_div(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression);
#endif
