/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "AST_functions.h"
#define ARQUIVO_SAIDA "saida.dot"

asd_tree_t *asd_new(const char *label)
{
    asd_tree_t *ret = NULL;
    ret = (asd_tree_t *)calloc(1, sizeof(asd_tree_t));
    if (ret != NULL)
    {
        ret->label = strdup(label);
        ret->number_of_children = 0;
        ret->children = NULL;
        ret->type = -1;
    }
    return ret;
}

void asd_free(asd_tree_t *tree)
{
    if (tree != NULL)
    {
        int i;
        for (i = 0; i < tree->number_of_children; i++)
        {
            asd_free(tree->children[i]);
        }
        free(tree->label);
        free(tree->children);
        free(tree);
    }
}

void asd_add_child(asd_tree_t *tree, asd_tree_t *child)
{
    if (tree != NULL && child != NULL)
    {
        tree->number_of_children++;
        tree->children = (asd_tree_t **)realloc(tree->children, tree->number_of_children * sizeof(asd_tree_t *));
        tree->children[tree->number_of_children - 1] = child;
        tree->type=-1;
    }

}

void _exporta(asd_tree_t* node){
    if(node == NULL ){
        return;
    }
    printf("%p [label=\"%s\"];\n", (void*)node, node->label);

    for(int i = 0; i < node->number_of_children; i++){
        if(node->children[i] != NULL ){
            printf("%p, %p\n", (void*)node, (void*)node->children[i]);
            _exporta(node->children[i]);
        }
    }
}

void exporta(void *arvore){
    asd_tree_t *root = (asd_tree_t*) arvore;
    if(root != NULL){
        _exporta(root);
        asd_free(root);
    } 
}
