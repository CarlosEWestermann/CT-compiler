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

typedef enum {
    add,
    sub,
    mul,
    div,
    loadI,
} iloc_operation_t;

typedef struct {
    iloc_operation_t operation;
    char* r1;
    char* r2;
    char* r3;
} instruction_t;

typedef struct {
    int length;
    instruction_t *instructions;
} program_t;

char* generate_label;
char* generate_register;

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
