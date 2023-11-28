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
    else
    {
        printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
    }
}

void asd_add_child(asd_tree_t *tree, asd_tree_t *child)
{
    if (tree != NULL && child != NULL)
    {
        tree->number_of_children++;
        tree->children = (asd_tree_t **)realloc(tree->children, tree->number_of_children * sizeof(asd_tree_t *));
        tree->children[tree->number_of_children - 1] = child;
    }
/*    else
    {
        printf("Erro: %s recebeu parâmetro tree = %p / %p.\n", __FUNCTION__, tree, child);
    }*/
}

// static void _asd_print(FILE *foutput, asd_tree_t *tree, int profundidade)
// {
//     int i;
//     if (tree != NULL)
//     {
//         fprintf(foutput, "%d%*s: Nó '%s' tem %d filhos:\n", profundidade, profundidade * 2, "", tree->label, tree->number_of_children);
//         for (i = 0; i < tree->number_of_children; i++)
//         {
//             _asd_print(foutput, tree->children[i], profundidade + 1);
//         }
//     }
//     else
//     {
//         printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
//     }
// }

// void asd_print(asd_tree_t *tree)
// {
//     FILE *foutput = stderr;
//     if (tree != NULL)
//     {
//         _asd_print(foutput, tree, 0);
//     }
//     else
//     {
//         printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
//     }
// }

// static void _asd_print_graphviz(FILE *foutput, asd_tree_t *tree)
// {
//     int i;
//     if (tree != NULL)
//     {
//         fprintf(foutput, "  %ld [ label=\"%s\" ];\n", (long)tree, tree->label);
//         for (i = 0; i < tree->number_of_children; i++)
//         {
//             fprintf(foutput, "  %ld -> %ld;\n", (long)tree, (long)tree->children[i]);
//             _asd_print_graphviz(foutput, tree->children[i]);
//         }
//     }
//     else
//     {
//         printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
//     }
// }

// void asd_print_graphviz(asd_tree_t *tree)
// {
//     FILE *foutput = fopen(ARQUIVO_SAIDA, "w+");
//     if (foutput == NULL)
//     {
//         printf("Erro: %s não pude abrir o arquivo [%s] para escrita.\n", __FUNCTION__, ARQUIVO_SAIDA);
//     }
//     if (tree != NULL)
//     {
//         fprintf(foutput, "digraph grafo {\n");
//         _asd_print_graphviz(foutput, tree);
//         fprintf(foutput, "}\n");
//         fclose(foutput);
//     }
//     else
//     {
//         printf("Erro: %s recebeu parâmetro tree = %p.\n", __FUNCTION__, tree);
//     }
// }

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

    if(root == NULL){
        printf("ERRO: arvore vazia");
    } else {
        printf("\n");
        _exporta(root);
        asd_free(root);
    }
    
}
