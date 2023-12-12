/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include <stdio.h>
#include "AST_functions.h"
#include "symbol_table.h"
extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;
TableStack stack;

int main (int argc, char **argv)
{
    stack.top = -1;
/*     pushScope(&stack);
    insertSymbolWithScope(&stack, "TESTE", 1, IDENTIFIER, FLOAT, "TESTE");
    insertSymbolWithScope(&stack, "TESTE_COMPLETO_2", 1, IDENTIFIER, BOOL, "TESTE");
    popScope(&stack);

    pushScope(&stack);
    insertSymbolWithScope(&stack, "TESTE_COMPLETO_3", 1, IDENTIFIER, INT, "TESTE");
    print_all(&stack);
    print_all(&stack);
    insertSymbolWithScope(&stack, "TESTE", 1, IDENTIFIER, FLOAT, "TESTE");
 */
    int ret = yyparse(); 
//    print_all(&stack);
    exporta (arvore);
    yylex_destroy();
    // Liberar a memória associada a cada tabela na stack
    // for (int i = 0; i <= stack.top; ++i) {
    //     freeTable(stack.stack[i]);
    // }
    return ret;
}
