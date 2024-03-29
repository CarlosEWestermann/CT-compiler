/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#ifndef CODE_GENERATION_FUNCTIONS_HPP
#define CODE_GENERATION_FUNCTIONS_HPP

#include <stdio.h>
#include <stdbool.h>

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
    divi,
    ge,
    gt,
    le,
    lt,
    and,
    or,
    cmp_ne,
    cmp_eq,
    cbr,
    loadAI,
    loadI,
    label,
    jumpI,
    halt,
    storeAI,
    nop,
} iloc_operation_t;

const char* operation_to_string(iloc_operation_t op);

typedef enum {
    REGISTER, LABEL
} operand_type_t;

typedef struct {
    iloc_operation_t operation;
    char* label;
    char* operand1;
    char* operand2; 
    char* operand3; 
    int num_operands; 
} instruction_t;

typedef struct {
    int size;
    instruction_t *instructions;
} program_t;

typedef struct asd_tree {
    char *label;
    int type;
    char *value;
    int number_of_children;
    struct asd_tree **children;
    struct asd_tree *next;
    char* temp;
    int offset;
    bool is_global;
    program_t *code;
} asd_tree_t;

char* generate_label();
char* generate_register();
void append_program(program_t *destination, program_t *source);
instruction_t create_instruction(iloc_operation_t operation, char* operand1, char* operand2, char* operand3, char* label, int num_operands);
void free_instruction(instruction_t* instruction);
void add_instruction_to_program(program_t *program, instruction_t instruction);
void add_binop(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression, iloc_operation_t operation);
void add_unop(asd_tree_t *head, asd_tree_t *first_expression, iloc_operation_t operation);
void add_if(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body);
void add_if_else(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *if_body, asd_tree_t *else_body); 
void add_while(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body);
void print_instruction(instruction_t* instr);
void print_program(asd_tree_t *head);
const char* operation_to_string(iloc_operation_t op);
void set_main();

#endif
