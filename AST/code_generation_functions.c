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
    snprintf(register_buf, sizeof(register_buf), "R%i", temp_register);
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
    snprintf(cmp_ne_operands[1].operand.registerName, 20, "R%d", expression->temp); 
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
    snprintf(cmp_ne_operands[1].operand.registerName, 20, "R%d", expression->temp); 
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

    append_program(head->code, if_body->code);

    operand_t label_end_operand = { .type = LABEL, .operand.label = label_end };
    add_instruction_to_program(head->code, create_instruction(label, &label_end_operand, 1));

    append_program(head->code, else_body->code);
}

/* void add_binop(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression, iloc_operation_t operation) {
    int total_size = first_expression->code->size + second_expression->code->size;
    instruction_t *combined_instructions = (instruction_t *)malloc(total_size * sizeof(instruction_t));
    
    for (int i = 0; i < first_expression->code->size; i++) {
        combined_instructions[i] = first_expression->code->instructions[i];
    }

    for (int i = 0; i < second_expression->code->size; i++) {
        combined_instructions[first_expression->code->size + i] = second_expression->code->instructions[i];
    }

    if (head->code->instructions != NULL) {
        free(head->code->instructions);
    }

    head->code->instructions = combined_instructions;
    head->code->size = total_size;

    char *temp_register = generate_register(); 

    operand_t operands[3];
    operands[0].type = REGISTER;
    operands[0].operand.registerName = malloc(20); 
    snprintf(operands[0].operand.registerName, 20, "R%d", first_expression->temp);

    operands[1].type = REGISTER;
    operands[1].operand.registerName = malloc(20);
    snprintf(operands[1].operand.registerName, 20, "R%d", second_expression->temp);

    operands[2].type = REGISTER;
    operands[2].operand.registerName = temp_register; 

    instruction_t new_binop = create_instruction(operation, operands, 3);
    add_instruction_to_program(head->code, new_binop);

    head->temp = atoi(temp_register + 1);

    free(operands[0].operand.registerName);
    free(operands[1].operand.registerName);
}

void add_unop(asd_tree_t *head, asd_tree_t *expression, iloc_operation_t operation) {
    int total_size = expression->code->size;
    instruction_t *copied_instructions = (instruction_t *)malloc(total_size * sizeof(instruction_t));
    
    for (int i = 0; i < expression->code->size; i++) {
        copied_instructions[i] = expression->code->instructions[i];
    }

    
    if (head->code->instructions != NULL) {
        free(head->code->instructions);
    }

    head->code->instructions = copied_instructions;
    head->code->size = total_size;

    char *temp_register = generate_register(); 
    operand_t operand;
    operand.type = REGISTER;
    operand.operand.registerName = malloc(20); 
    snprintf(operand.operand.registerName, 20, "R%d", expression->temp);

    operand_t operands[2];
    operands[0] = operand;
    operands[1].type = REGISTER;
    operands[1].operand.registerName = temp_register; 

    instruction_t new_unop = create_instruction(operation, operands, 2);
    add_instruction_to_program(head->code, new_unop);

    head->temp = atoi(temp_register + 1); 

    free(operand.operand.registerName);
}


//void add_if(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *body){
    
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
//}

//void add_if_else(asd_tree_t *head, asd_tree_t *expression, asd_tree_t *if_body, asd_tree_t *else_body){
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
//}

/*void add_binop(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t * second_expression, iloc_operation_t operation) {
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
} */
