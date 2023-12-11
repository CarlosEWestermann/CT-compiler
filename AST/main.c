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
TableStack *stack;
SymbolTable *currentScope; 

int main (int argc, char **argv)
{
    stack->top = -1;
    // emiplhando scope 
    currentScope = pushScope(stack);
    insertSymbolWithScope(stack, "SEXO", 1, IDENTIFIER, IDENTIFICADOR, "sexo");
    currentScope = pushScope(stack);
    insertSymbolWithScope(stack, "SEXO", 2, IDENTIFIER, BOOL, "true");

    int ret = yyparse(); 
    exporta (arvore);
    yylex_destroy();
    // Liberar a memória associada a cada tabela na stack
    for (int i = 0; i <= stack->top; ++i) {
        freeTable(stack->stack[i]);
    }
    return ret;
}
