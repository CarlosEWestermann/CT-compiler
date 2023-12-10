#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SCOPES 100 // Defina o número máximo de escopos


// Definição dos tipos de natureza do símbolo
typedef enum {
    LITERAL,
    IDENTIFIER,
    FUNCTION
} SymbolNature;

typedef enum {
    INT,
    FLOAT,
    IDENTIFIER,
    BOOL
} SymbolType;

// Estrutura para armazenar informações sobre um símbolo
typedef struct {
    int line;
    SymbolNature nature;
    SymbolType type; // Tipo do dado do símbolo (pode ser uma string)
    char value[50]; // Dados do valor do token (pode ser uma string)
} SymbolData;

// Estrutura da entrada na table de símbolos
typedef struct TableEntry {
    char key[50]; // key única identificando o símbolo
    SymbolData content; // Conteúdo com as informações do símbolo
    struct TableEntry* next; // Ponteiro para o próximo símbolo na table (para tratamento de colisões, se usar table hash)
} TableEntry;

// Estrutura da table de Símbolos
typedef struct {
    TableEntry* table[100]; // Array de ponteiros para as entradas na table (tamanho da table pode variar)
} SymbolTable;

typedef struct {
    SymbolTable* stack[MAX_SCOPES]; // Array de ponteiros para as tabelas de símbolos
    int top; // Índice do topo da pilha
} TableStack;

// Função para inserir um símbolo na table de símbolos
void insertSymbol(SymbolTable* table, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    // Calcular índice na table hash (pode usar uma função de hash mais sofisticada)
    int i = strlen(key) % 100;

    // Criar uma nova entrada para o símbolo
    TableEntry* newEntry = (TableEntry*)malloc(sizeof(TableEntry));
    strcpy(newEntry->key, key);
    newEntry->content.line = line;
    newEntry->content.nature = nature;
    strcpy(newEntry->content.type, type);
    strcpy(newEntry->content.value, value);
    newEntry->next = NULL;

    // Inserir a entrada na table (tratando colisões por encadeamento)
    if (table->table[i] == NULL) {
        table->table[i] = newEntry;
    } else {
        TableEntry* curr = table->table[i];
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newEntry;
    }
}

// Função para buscar um símbolo na table de símbolos
SymbolData* lookupSymbol(SymbolTable* table, const char* key) {
    int i = strlen(key) % 100;

    TableEntry* curr = table->table[i];
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            return &(curr->content);
        }
        curr = curr->next;
    }

    return NULL;
}

// Função para liberar a memória alocada para a table de símbolos
void freeTable(SymbolTable* table) {
    for (int i = 0; i < 100; ++i) {
        TableEntry* curr = table->table[i];
        while (curr != NULL) {
            TableEntry* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
}

// Função para empilhar uma tabela de símbolos na pilha de escopos
void pushScope(TableStack* stack, SymbolTable* table) {
    if (stack->top < MAX_SCOPES - 1) {
        stack->top++;
        stack->stack[stack->top] = table;
    } else {
        printf("Erro: Pilha de escopos cheia\n");
    }
}

// Função para desempilhar uma tabela de símbolos da pilha de escopos
void popScope(TableStack* stack) {
    if (stack->top >= 0) {
        stack->top--;
    } else {
        printf("Erro: Pilha de escopos vazia\n");
    }
}

void insertSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    if (lookupSymbolWithScope(stack, key) != NULL) {
        printf("Erro: Identificador '%s' já declarado neste escopo\n", key);
        return;
    }

    SymbolTable* currentScope = stack->stack[stack->top];
    insertSymbol(currentScope, key, line, nature, type, value);
}

SymbolData* lookupSymbolWithScope(TableStack* stack, const char* key) {
    for (int i = stack->top; i >= 0; i--) {
        SymbolTable* currentScope = stack->stack[i];
        SymbolData* symbol = lookupSymbol(currentScope, key);
        if (symbol != NULL) {
            return symbol;
        }
    }
    return NULL;
}


int main() {
    TableStack tableStack;
    tableStack.top = -1; // Inicializa o topo da pilha como -1 (pilha vazia)

    // Criando e empilhando um novo escopo
    SymbolTable table1;
    memset(&table1, 0, sizeof(SymbolTable));
    pushScope(&tableStack, &table1);

    // Inserindo símbolos no primeiro escopo
    insertSymbolWithScope(&tableStack, "x", 10, IDENTIFIER, INT, "5");
    insertSymbolWithScope(&tableStack, "y", 15, IDENTIFIER, FLOAT, "3.14");

    // Criando e empilhando um segundo escopo
    SymbolTable table2;
    memset(&table2, 0, sizeof(SymbolTable));
    pushScope(&tableStack, &table2);

    // Inserindo símbolos no segundo escopo
    insertSymbolWithScope(&tableStack, "z", 20, IDENTIFIER, BOOL, "true");
    insertSymbolWithScope(&tableStack, "x", 25, IDENTIFIER, FLOAT, "2.718");

    // Buscando símbolos em diferentes escopos
    const char* searchKey1 = "x";
    SymbolData* data1 = lookupSymbolWithScope(&tableStack, searchKey1);
    if (data1 != NULL) {
        printf("Informacoes sobre o simbolo '%s':\n", searchKey1);
        printf("Escopo: 2\n");
        printf("Localizacao (linha): %d\n", data1->line);
        printf("Natureza: %d\n", data1->nature);
        printf("Tipo do dado: %d\n", data1->type);
        printf("Valor do token: %s\n", data1->value);
    } else {
        printf("Simbolo '%s' nao encontrado.\n", searchKey1);
    }

    const char* searchKey2 = "z";
    SymbolData* data2 = lookupSymbolWithScope(&tableStack, searchKey2);
    if (data2 != NULL) {
        printf("\nInformacoes sobre o simbolo '%s':\n", searchKey2);
        printf("Escopo: 1\n");
        printf("Localizacao (linha): %d\n", data2->line);
        printf("Natureza: %d\n", data2->nature);
        printf("Tipo do dado: %d\n", data2->type);
        printf("Valor do token: %s\n", data2->value);
    } else {
        printf("Simbolo '%s' nao encontrado.\n", searchKey2);
    }

    // Desempilhando escopos (liberando memória poderia ser feito no final do compilador)
    popScope(&tableStack); // Desempilha o segundo escopo
    popScope(&tableStack); // Desempilha o primeiro escopo

    return 0;
}