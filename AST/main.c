/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include <stdio.h>
#include "AST_functions.h"
#include "symbol_table.h"
//#include "code_generation_functions.h"
extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;
TableStack stack;

int main (int argc, char **argv)
{
    stack.top = -1;
    int ret = yyparse(); 
    exporta (arvore);
    print_program (arvore);
    yylex_destroy();
    return ret;
}
