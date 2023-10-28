/*
Função principal para realização da análise sintática.

Este arquivo será posterioremente substituído, não acrescente nada.
*/
#include <stdio.h>
#include "parser.tab.h"
extern int yylex_destroy(void);

int main (int argc, char **argv)
{
  int ret = yyparse();
  yylex_destroy();
  return ret;
}