/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

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