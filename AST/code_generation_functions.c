/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include "code_generation_functions.h"
#include "AST_functions.h"

char* generate_label() {
    static int temp_label = 0;
    static char label_buf[20]; 

    temp_label++;
    snprintf(label_buf, sizeof(label_buf), "L%i", temp_label);
    return label_buf;
}

char* generate_register() {
    static int temp_register = 0;
    static char register_buf[20]; 

    temp_register++;
    snprintf(register_buf, sizeof(register_buf), "r%i", temp_register);
    return register_buf;
}

instruction_t create_instruction(iloc_operation_t operation, operand_t operands[], int num_operands) {
    instruction_t new_instruction;
    new_instruction.operation = operation;
    new_instruction.num_operands = num_operands;
    new_instruction.operands = (operand_t*)malloc(num_operands * sizeof(operand_t));
    for (int i = 0; i < num_operands; i++) {
        new_instruction.operands[i] = operands[i];
    }
    return new_instruction;
}

void free_instruction(instruction_t* instruction) {
    free(instruction->operands);
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

void add_while(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body) { }

void add_if(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body) {
    char* zero_register = generate_register();
    char* comparison_register = generate_register();
    char* label_true = generate_label();
    char* label_end = generate_label();

    append_program(head->code, expression->code);

    operand_t loadI_operands[] = {
        { .type = REGISTER, .operand.registerName = zero_register },
        { .type = LABEL, .operand.label = "0" } 
    };
    add_instruction_to_program(head->code, create_instruction(loadI, loadI_operands, 2));

    operand_t cmp_ne_operands[] = {
        { .type = REGISTER, .operand.registerName = zero_register },
        { .type = REGISTER, .operand.registerName = malloc(20) }, 
        { .type = REGISTER, .operand.registerName = comparison_register }
    };
    snprintf(cmp_ne_operands[1].operand.registerName, 20, "r%d", expression->temp); 
    add_instruction_to_program(head->code, create_instruction(cmp_ne, cmp_ne_operands, 3));
    free(cmp_ne_operands[1].operand.registerName);

    operand_t cbr_operands[] = {
        { .type = REGISTER, .operand.registerName = comparison_register },
        { .type = LABEL, .operand.label = label_true },
        { .type = LABEL, .operand.label = label_end }
    };
    add_instruction_to_program(head->code, create_instruction(cbr, cbr_operands, 3));

    operand_t label_true_operand = { .type = LABEL, .operand.label = label_true };
    add_instruction_to_program(head->code, create_instruction(label, &label_true_operand, 1));

    append_program(head->code, body->code);

    operand_t label_end_operand = { .type = LABEL, .operand.label = label_end };
    add_instruction_to_program(head->code, create_instruction(label, &label_end_operand, 1));
}

void add_if_else(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *if_body, asd_tree_t *else_body) {
    char* zero_register = generate_register();
    char* comparison_register = generate_register();
    char* label_true = generate_label();
    char* label_false = generate_label();

    append_program(head->code, expression->code);

    operand_t loadI_operands[] = {
        { .type = REGISTER, .operand.registerName = zero_register },
        { .type = LABEL, .operand.label = "0" } 
    };
    add_instruction_to_program(head->code, create_instruction(loadI, loadI_operands, 2));

    operand_t cmp_ne_operands[] = {
        { .type = REGISTER, .operand.registerName = zero_register },
        { .type = REGISTER, .operand.registerName = malloc(20) }, 
        { .type = REGISTER, .operand.registerName = comparison_register }
    };
    snprintf(cmp_ne_operands[1].operand.registerName, 20, "r%d", expression->temp); 
    add_instruction_to_program(head->code, create_instruction(cmp_ne, cmp_ne_operands, 3));
    free(cmp_ne_operands[1].operand.registerName);

    operand_t cbr_operands[] = {
        { .type = REGISTER, .operand.registerName = comparison_register },
        { .type = LABEL, .operand.label = label_true },
        { .type = LABEL, .operand.label = label_false }
    };

    add_instruction_to_program(head->code, create_instruction(cbr, cbr_operands, 3));

    operand_t label_true_operand = { .type = LABEL, .operand.label = label_true };
    add_instruction_to_program(head->code, create_instruction(label, &label_true_operand, 1));

    append_program(head->code, if_body->code);

    operand_t label_end_operand = { .type = LABEL, .operand.label = label_false };
    add_instruction_to_program(head->code, create_instruction(label, &label_end_operand, 1));

    append_program(head->code, else_body->code);
}

void add_binop(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression, iloc_operation_t operation) {
    char* temp_register = generate_register(); 

    append_program(head->code, first_expression->code);
    append_program(head->code, second_expression->code);

    
    char first_reg[20]; 
    char second_reg[20];
    snprintf(first_reg, sizeof(first_reg), "r%d", first_expression->temp); 
    snprintf(second_reg, sizeof(second_reg), "r%d", second_expression->temp); 


    operand_t operation_operands[] = {
        { .type = REGISTER, .operand.registerName = first_reg },
        { .type = REGISTER, .operand.registerName = second_reg },
        { .type = REGISTER, .operand.registerName = temp_register }
    };

    add_instruction_to_program(head->code, create_instruction(operation, operation_operands, 3));

    head->temp = atoi(temp_register + 1);
}

void add_unop(asd_tree_t *head, asd_tree_t *first_expression, iloc_operation_t operation) {
    char* temp_register = generate_register(); 

    append_program(head->code, first_expression->code);

    
    char first_reg[20]; 
    snprintf(first_reg, sizeof(first_reg), "r%d", first_expression->temp); 


    operand_t operation_operands[] = {
        { .type = REGISTER, .operand.registerName = first_reg },
        { .type = REGISTER, .operand.registerName = temp_register }
    };

    add_instruction_to_program(head->code, create_instruction(operation, operation_operands, 3));

    head->temp = atoi(temp_register + 1);
}

void print_program(asd_tree_t *head) {
    for (int i = 0; i < head->code->size; i++) {
        printf("%s", OperationToString(head->code->instructions[i].operation));
        for (int j = 0; j < head->code->instructions[i].num_operands; j++) {
            printf("%s", head->code->instructions[i].operands[j].operand.registerName);
        }
    }
}