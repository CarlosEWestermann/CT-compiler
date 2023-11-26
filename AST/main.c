#include <stdio.h>
#include "AST_functions.hpp"
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