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

void add_if(asd_tree_t *expression, asd_tree_t *body){
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
    strcat($$.code, label_false);
    */
}

void add_if_else(asd_tree_t *expression, asd_tree_t *if_body, asd_tree_t *else_body){
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
    strcat($$.code, label_false);
    strcat($$.code, $7.code);
    */
}


