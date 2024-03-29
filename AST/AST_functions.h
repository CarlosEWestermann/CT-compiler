/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#ifndef AST_FUNCTIONS_HPP
#define AST_FUNCTIONS_HPP

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "code_generation_functions.h"
#define ARQUIVO_SAIDA "saida.dot"

typedef struct {
        int lineno;
        int token_type;
        char* token_value;
} lexical_value_t;

asd_tree_t *asd_new(const char *label);
void asd_free(asd_tree_t *tree);
void asd_add_child(asd_tree_t *tree, asd_tree_t *child);
void _exporta(asd_tree_t* node);
void exporta(void *arvore);

#endif
