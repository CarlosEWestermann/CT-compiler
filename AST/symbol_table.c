#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main() {
    SymbolTable table;
    memset(&table, 0, sizeof(SymbolTable)); // Inicializa a table com NULL

    // Exemplo de uso: inserir símbolos na table
    insertSymbol(&table, "x", 10, IDENTIFIER, "int", "5");
    insertSymbol(&table, "y", 15, IDENTIFIER, "float", "3.14");
    insertSymbol(&table, "pi", 20, LITERAL, "float", "3.14159");

    // Exemplo de uso: buscar informações sobre um símbolo
    const char* searchKey = "x";
    SymbolData* data = lookupSymbol(&table, searchKey);
    if (data != NULL) {
        printf("datarmacoes sobre o simbolo '%s':\n", searchKey);
        printf("Localizacao (linha): %d\n", data->line);
        printf("Natureza: %d\n", data->nature);
        printf("Tipo do dado: %s\n", data->type);
        printf("Valor do token: %s\n", data->value);
    } else {
        printf("Simbolo '%s' nao encontrado na table.\n", searchKey);
    }

    // Liberar a memória alocada para a table de símbolos
    freeTable(&table);

    return 0;
}