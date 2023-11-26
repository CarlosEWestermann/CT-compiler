#ifndef AST_FUNCTIONS_HPP
#define AST_FUNCTIONS_HPP

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#define ARQUIVO_SAIDA "saida.dot"


typedef struct {
        int lineno;
        int token_type;
        char* token_value;
} lexical_value_t;

typedef struct asd_tree {
    char *label;
    int number_of_children;
    struct asd_tree **children;
} asd_tree_t;

asd_tree_t *asd_new(const char *label);

void asd_free(asd_tree_t *tree);

void asd_add_child(asd_tree_t *tree, asd_tree_t *child);

static void _asd_print(FILE *foutput, asd_tree_t *tree, int profundidade);

void asd_print(asd_tree_t *tree);

static void _asd_print_graphviz(FILE *foutput, asd_tree_t *tree);

void asd_print_graphviz(asd_tree_t *tree);

void _exporta(asd_tree_t* node);

void exporta(void *arvore);

#endif
