/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include <stdio.h>
#include "AST_functions.h"
extern int yyparse(void);
extern int yylex_destroy(void);

void *arvore = NULL;

int main (int argc, char **argv)
{
    int ret = yyparse(); 
    exporta (arvore);
    yylex_destroy();
    return ret;
}
