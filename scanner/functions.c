extern int yylineno;
#include <stdio.h>

int get_line_number( ) {
    return yylineno;
}

void yyerror (char const *mensagem) {
  printf("%d: %s",  yylineno, mensagem);
}
