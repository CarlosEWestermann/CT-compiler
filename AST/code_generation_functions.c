/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include "AST_functions.h"

int generate_label() {
    static int temp_label = 0;

    temp_label++; 
    return temp_label;
}

int generate_register() {
    static int temp_register = 0;

    temp_register++; 
    return temp_register;
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

    sprintf(head.code, "loadI 0 => r%s\n", zero_register);
    strcat(head.code, expression.code);

    char[100] cmp_ne_code;
    sprintf(cmp_code, "cmp_ne %s, R%d => %s", zero_register, expression.temp, comparison_register)
    strcat(head.code, cmp_ne_code);

    char[100] cbr_code;
    sprintf(cbr_code, "cbr %s => %s, %s", comparison_register, label_true, label_false);
    strcat(head.code, cmp_code);

    strcat(head.code, label_true);
    strcat(head.code, body.code);
    strcat(head.code, label_false);
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

    sprintf(head.code, "loadI 0 => r%s\n", zero_register);
    strcat(head.code, expression.code);

    char[100] cmp_ne_code;
    sprintf(cmp_code, "cmp_ne %s, R%d => %s", zero_register, expression.temp, comparison_register)
    strcat(head.code, cmp_ne_code);

    char[100] cbr_code;
    sprintf(cbr_code, "cbr %s => %s, %s", comparison_register, label_true, label_false);
    strcat(head.code, cmp_code);

    strcat(head.code, label_true);
    strcat(head.code, body.code);
    strcat(head.code, label_false);
    strcat(head.code, else_body.code);
    */
}

void add_or(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_or_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] or_code;
    sprintf(or_code, "or R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_or_register);
    strcat(head.code, or_code);
    head.temp = temp_or_register;
    */
}

void add_and(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_and_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] and_code;
    sprintf(and_code, "and R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_and_register);
    strcat(head.code, and_code);
    head.temp = temp_and_register;
    */
}

void add_equals(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_cmp_EQ_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] cmp_EQ_code;
    sprintf(cmp_EQ_code, "cmp_EQ R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_cmp_EQ_register);
    strcat(head.code, cmp_EQ_code);
    head.temp = temp_cmp_EQ_register;
    */
}

void add_not_equal(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_cmp_NE_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] cmp_NE_code;
    sprintf(cmp_NE_code, "cmp_NE R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_cmp_NE_register);
    strcat(head.code, cmp_NE_code);
    head.temp = temp_cmp_NE_register;
    */
}

void add_less_than(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_cmp_LT_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] cmp_LT_code;
    sprintf(cmp_LT_code, "cmp_LT R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_cmp_LT_register);
    strcat(head.code, cmp_LT_code);
    head.temp = temp_cmp_LT_register;
    */
}

void add_greater_than(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_cmp_GT_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] cmp_GT_code;
    sprintf(cmp_GT_code, "cmp_GT R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_cmp_GT_register);
    strcat(head.code, cmp_GT_code);
    head.temp = temp_cmp_GT_register;
    */
}

void add_less_equal(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_cmp_LE_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] cmp_LE_code;
    sprintf(cmp_LE_code, "cmp_LE R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_cmp_LE_register);
    strcat(head.code, cmp_LE_code);
    head.temp = temp_cmp_LE_register;
    */
}

void add_greater_equal(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_cmp_GE_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] cmp_GE_code;
    sprintf(cmp_GE_code, "cmp_GE R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_cmp_GE_register);
    strcat(head.code, cmp_GE_code);
    head.temp = temp_cmp_GE_register;
    */
}

void add_sub(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_sub_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] sub_code;
    sprintf(sub_code, "sub R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_sub_register);
    strcat(head.code, sub_code);
    head.temp = temp_sub_register;
    */
}

void add_add(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_add_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] add_code;
    sprintf(add_code, "add R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_add_register);
    strcat(head.code, add_code);
    head.temp = temp_add_register;
    */
}

void add_mult(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_mult_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] mult_code;
    sprintf(mult_code, "mult R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_mult_register);
    strcat(head.code, mult_code);
    head.temp = temp_mult_register;
    */
}

void add_div(asd_tree_t *head, asd_tree_t *first_expression, asd_tree_t *second_expression){
    /*
    int temp_div_register = generate_register();
    sprintf(head.code, first_expression.code);
    strcat(head.code, second_expression.code);

    char[100] div_code;
    sprintf(div_code, "div R%D, R%d => R%d" first_expression.temp, second_expression.temp, temp_div_register);
    strcat(head.code, div_code);
    head.temp = temp_div_register;
    */
}
