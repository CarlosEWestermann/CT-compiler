/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include "code_generation_functions.h"
#include "AST_functions.h"

int temp_register = 0;
int temp_label = 0;

char* generate_label() {
    char* label_buf = malloc(20); 
 
    temp_label++;
    snprintf(label_buf, 20, "L%i", temp_label);
    return label_buf;
}

char* generate_register() {
    char* register_buf = malloc(20); 
    
    temp_register++;
    snprintf(register_buf, 20, "r%i", temp_register);
    return register_buf;
}

instruction_t create_instruction(iloc_operation_t operation, char* operand1, char* operand2, char* operand3, char* label, int num_operands) {
    instruction_t new_instruction;

    new_instruction.operation = operation;
    new_instruction.num_operands = num_operands;
    new_instruction.operand1 = operand1 == NULL ? NULL : strdup(operand1);
    new_instruction.operand2 = operand2 == NULL  ? NULL : strdup(operand2);
    new_instruction.operand3 = operand3 == NULL ? NULL : strdup(operand3);
    new_instruction.label = label == NULL ? NULL : strdup(label);

    return new_instruction;
}

void free_instruction(instruction_t* instruction) {
    free(instruction->operand1);
    free(instruction->operand2);
    free(instruction->operand3);
    free(instruction->label);
}

void add_instruction_to_program(program_t *program, instruction_t instruction) {
    program->instructions = realloc(program->instructions, (program->size + 1) * sizeof(instruction_t));
    program->instructions[program->size] = instruction;
    program->size++;
}

void append_program(program_t *destination, program_t *source) {
    int newSize = destination->size + source->size;

    instruction_t *newInstructions = realloc(destination->instructions, newSize * sizeof(instruction_t));
    destination->instructions = newInstructions;

    memcpy(destination->instructions + destination->size, source->instructions, source->size * sizeof(instruction_t));

    destination->size = newSize;
}

void add_if(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body) {
    char* zero_register = generate_register();
    char* comparison_register = generate_register();
    char* label_true = generate_label();
    char* label_false = generate_label();

    append_program(head->code, expression->code);

    add_instruction_to_program(head->code, create_instruction(loadI, "0", zero_register, NULL, NULL, 2));

    add_instruction_to_program(head->code, create_instruction(cmp_ne, zero_register, expression->temp, comparison_register, NULL, 3));

    add_instruction_to_program(head->code, create_instruction(cbr, comparison_register, label_true, label_false, NULL, 3));

    if(body != NULL && body->code->size != 0) { 
        body->code->instructions[0].label = label_true; 
        append_program(head->code, body->code);
    } else {
        add_instruction_to_program(head->code, create_instruction(nop, NULL, NULL, NULL, label_true, 0));
    }


    add_instruction_to_program(head->code, create_instruction(nop, NULL, NULL, NULL, label_false, 0));
}

void add_if_else(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *if_body, asd_tree_t *else_body) {
    char* zero_register = generate_register();
    char* comparison_register = generate_register();
    char* label_true = generate_label();
    char* label_false = generate_label();

    append_program(head->code, expression->code);

    add_instruction_to_program(head->code, create_instruction(loadI, "0", zero_register, NULL, NULL, 2));

    add_instruction_to_program(head->code, create_instruction(cmp_ne, zero_register, expression->temp, comparison_register, NULL, 3));

    add_instruction_to_program(head->code, create_instruction(cbr, comparison_register, label_true, label_false, NULL, 3));

    if(if_body != NULL && if_body->code->size != 0) { 
        if_body->code->instructions[0].label = label_true; 
        append_program(head->code, if_body->code);
    } else {
        add_instruction_to_program(head->code, create_instruction(nop, NULL, NULL, NULL, label_true, 0));
    }

    if(else_body != NULL && else_body->code->size != 0) { 
        else_body->code->instructions[0].label = label_true; 
        append_program(head->code, else_body->code);
    } else {
        add_instruction_to_program(head->code, create_instruction(nop, NULL, NULL, NULL, label_true, 0));
    }
}

void add_binop(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression, iloc_operation_t operation) {
    char* temp_register = generate_register(); 

    append_program(head->code, first_expression->code);
    append_program(head->code, second_expression->code);

    add_instruction_to_program(head->code, create_instruction(operation, first_expression->temp, second_expression->temp, temp_register, NULL, 3));

    head->temp = temp_register;
}

void add_unop(asd_tree_t *head, asd_tree_t *first_expression, iloc_operation_t operation) {
    char* temp_register = generate_register(); 

    append_program(head->code, first_expression->code);

    add_instruction_to_program(head->code, create_instruction(operation, first_expression->temp, temp_register, NULL, NULL, 2));

    head->temp = temp_register;
}

void add_while(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body) {
    char* zero_register = generate_register();
    char* comparison_register = generate_register();
    char* label_while = generate_label();
    char* label_true = generate_label();
    char* label_false = generate_label();

    if(expression != NULL && expression->code->size != 0) { 
        expression->code->instructions[0].label = label_while; 
        append_program(head->code, expression->code);
    } else {
        add_instruction_to_program(head->code, create_instruction(nop, NULL, NULL, NULL, label_true, 0));
    }

    add_instruction_to_program(head->code, create_instruction(loadI, "0", zero_register, NULL, NULL, 2));

    add_instruction_to_program(head->code, create_instruction(cmp_ne, zero_register, expression->temp, comparison_register, NULL, 3));

    add_instruction_to_program(head->code, create_instruction(cbr, comparison_register, label_true, label_false, NULL, 3));

    if(body != NULL && body->code->size != 0) { 
        body->code->instructions[0].label = label_true; 
        append_program(head->code, body->code);
    } else {
        add_instruction_to_program(head->code, create_instruction(nop, NULL, NULL, NULL, label_true, 0));
    }
    add_instruction_to_program(head->code, create_instruction(jumpI, label_while, NULL, NULL, NULL, 1));


    add_instruction_to_program(head->code, create_instruction(nop, NULL, NULL, NULL, label_false, 0));
}

void print_instruction(instruction_t* instr) {
    if (!instr) return;
    if (instr->label) printf("%s: ", instr->label);
    printf("%s ", OperationToString(instr->operation));
    switch (instr->operation) {
        case add:
        case sub:
        case mul:
        case divi:
        case and:
        case or:
        case cmp_ne:
        case cmp_eq:
        case ge:
        case gt:
        case loadAI:
        case le:
        case lt:
            if (instr->operand1) printf("%s, ", instr->operand1);
            if (instr->operand2) printf("%s, ", instr->operand2);
            if (instr->operand3) printf("=> %s", instr->operand3);
            break;
        case cbr:
            if (instr->operand1) printf("%s, ", instr->operand1);
            if (instr->operand2) printf("-> %s, ", instr->operand2);
            if (instr->operand3) printf("%s", instr->operand3);
            break;
        case loadI:
            if (instr->operand1) printf("%s => ", instr->operand1);
            if (instr->operand1) printf("%s ", instr->operand2);
            break;
        case jumpI:
            if (instr->operand1) printf("-> %s ", instr->operand1);
        default:
            break;
    }

    printf("\n");
}

void print_program(asd_tree_t *head) {
    if (!head->code || !head->code->instructions) return;

    for (int i = 0; i < head->code->size; i++) {
        print_instruction(&head->code->instructions[i]);
    }
}


const char* OperationToString(iloc_operation_t op) {
    switch (op) {
        case add:     return "add";
        case sub:     return "sub";
        case mul:     return "mul";
        case divi:    return "div";
        case ge:      return "ge";
        case gt:      return "gt";
        case le:      return "le";
        case lt:      return "lt";
        case and:     return "and";
        case or:      return "or";
        case cmp_ne:  return "cmp_ne";
        case cmp_eq:  return "cmp_eq";
        case cbr:     return "cbr";
        case loadAI:  return "loadAI";
        case loadI:   return "loadI";
        case label:   return "label";
        case nop:     return "nop";
        case jumpI:   return "jumpI";
        default:      return "";
    }
}