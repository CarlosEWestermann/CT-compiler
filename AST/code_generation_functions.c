/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include "AST_functions.h"
#include "code_generation_functions.h"

char* generate_label() {
    static int temp_label = 0;

    temp_label++; 
    return ("L%i",temp_label);
}

char* generate_register() {
    static int temp_register = 0;

    temp_register++; 
    return ("r%i",temp_register);
}

void add_if(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body){
    /*
    int zero_register_id = generate_register();
    int comparison_register_id = generate_register();
    int label_true_id = generate_label();
    int label_false_id = generate_label();
    
    char label_true[10], label_false[10], zero_register[10], comparison_register[10];
    sprintf(label_true, "L%d", label_true_id);
    sprintf(label_false, "L%d", label_false_id);
    sprintf(zero_register, "R%d", zero_register_id);
    sprintf(comparison_register, "R%d", comparison_register_id);

    sprintf(head->code, "loadI 0 => r%s\n", zero_register);
    strcat(head->code, expression.code);

    char[100] cmp_ne_code;
    sprintf(cmp_code, "cmp_ne %s, R%d => %s", zero_register, expression.temp, comparison_register)
    strcat(head->code, cmp_ne_code);

    char[100] cbr_code;
    sprintf(cbr_code, "cbr %s => %s, %s", comparison_register, label_true, label_false);
    strcat(head->code, cmp_code);

    strcat(head->code, label_true);
    strcat(head->code, body.code);
    strcat(head->code, label_false);
    */
}

void add_if_else(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *if_body, asd_tree_t *else_body){
    /*
    int zero_register_id = generate_register();
    int comparison_register_id = generate_register();
    int label_true_id = generate_label();
    int label_false_id = generate_label();
    
    char label_true[10], label_false[10], zero_register[10], comparison_register[10];
    sprintf(label_true, "L%d", label_true_id);
    sprintf(label_false, "L%d", label_false_id);
    sprintf(zero_register, "R%d", zero_register_id);
    sprintf(comparison_register, "R%d", comparison_register_id);

    sprintf(head->code, "loadI 0 => r%s\n", zero_register);
    strcat(head->code, expression.code);

    char[100] cmp_ne_code;
    sprintf(cmp_code, "cmp_ne %s, R%d => %s", zero_register, expression.temp, comparison_register)
    strcat(head->code, cmp_ne_code);

    char[100] cbr_code;
    sprintf(cbr_code, "cbr %s => %s, %s", comparison_register, label_true, label_false);
    strcat(head->code, cmp_code);

    strcat(head->code, label_true);
    strcat(head->code, body.code);
    strcat(head->code, label_false);
    strcat(head->code, else_body.code);
    */
}

instruction_t instruction_new(iloc_operation_t operation, int r1, int r2, int r3)
{
    instruction_t *instruction = NULL;
    instruction = (instruction_t *)calloc(1, sizeof(instruction_t));
    if (instruction != NULL)
    {
        instruction->operation = operation;
        instruction->r1 = r1;
        instruction->r2 = r2;
        instruction->r3 = r3 != NULL ? r3 : NULL;
    }
    instruction_t instruction_value = *instruction;
    return instruction_value;
}

void add_binop(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t * second_expression, iloc_operation_t operation) {
    int temp_register = generate_register();
    head->code = first_expression->code;
    head->code->instructions += second_expression->code->instructions;
    head->code->length += second_expression->code->length;

    instruction_t new_binop =  instruction_new(operation, first_expression->temp, second_expression->temp, temp_register);
    head->code->instructions[head->code->length + 1] = new_binop;
    head->code->length++;
    head->temp = temp_register;
}

void add_unop(asd_tree_t *head, asd_tree_t *first_expression, iloc_operation_t operation) {
    int temp_register = generate_register();
    head->code = first_expression->code;

    instruction_t new_unop =  instruction_new(operation, first_expression->temp, temp_register, NULL);
    head->code->instructions[head->code->length + 1] = new_unop;
    head->code->length++;
    head->temp = temp_register;
}


a = b

cod b 
load r1, a.desloc
storeAI b.temp => rbss r1 
{
    a = 1;
}
r1 = gera_register;
loadI = geradesloc, r1;
storeAI 1 => rfp r1 

a = 1

b = a + 2

loadI r1, a.desloc
storeAI b.temp => rbss r1 


load r2, r1 rbss
