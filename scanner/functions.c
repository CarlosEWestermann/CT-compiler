/*UFRGS 2023*/
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

extern int yylineno;
#include <stdio.h>

int get_line_number( ) {
    return yylineno;
}

void yyerror (char const *mensagem) {
  printf("%d: %s",  yylineno, mensagem);
}
