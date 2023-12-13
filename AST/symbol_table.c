#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"

void insertSymbol(SymbolTable* table, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    int i = strlen(key) % 100;

    TableEntry* newEntry = (TableEntry*)malloc(sizeof(TableEntry));
    if (newEntry == NULL) {
        printf("Error: Memory allocation failed for newEntry\n");
        exit(-1);
    }

    // Allocate memory for key
    newEntry->key = malloc(strlen(key) + 1);
    if (newEntry->key == NULL) {
        printf("Error: Memory allocation failed for newEntry->key\n");
        free(newEntry); 
        exit(-1);
    }
    strcpy(newEntry->key, key);
    newEntry->content.line = line;
    newEntry->content.nature = nature;
    newEntry->content.type= type;
    strcpy(newEntry->content.value, value);
    newEntry->next = NULL;

    // Temos handling pra conflitos de chave igual
    // Precisa? Ou queremos barrar SEMPRE?
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

void print_all(TableStack* stack) {
    if (stack->top == -1) {
        printf("Stack is empty.\n");
        return;
    }

    printf("top: %d\n", stack->top);

    for (int i = stack->top; i >= 0; i--) {
        SymbolTable* currentScope = stack->stack[i];
        if (currentScope == NULL) {
            continue; // Skip if current scope is NULL
        }

        for (int j = 0; j < 100; j++) {
            TableEntry* table = currentScope->table[j];
            while (table != NULL) { 
                printf("Key: %s, Line: %d, Nature: %d, Type: %d, Value: %s\n",
                    table->key,
                    table->content.line,
                    table->content.nature,
                    table->content.type,
                    table->content.value);
                table = table->next;
            }
        }
    }
}


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

void pushScope(TableStack* stack) {
    if (stack->top < MAX_SCOPES - 1) {
        SymbolTable* newTable = malloc(sizeof(SymbolTable));
        if (newTable == NULL) {
            printf("Error: Memory allocation failed\n");
            exit(-1);
        }

        stack->top++;
        stack->stack[stack->top] = newTable;
    } else {
        printf("Erro: Pilha de escopos cheia\n");
        exit(-1);
    }
}

// Função para desempilhar uma tabela de símbolos da pilha de escopos
void popScope(TableStack* stack) {
    if (stack->top >= 0) {
        stack->top--;
    } else {
        printf("Erro: Pilha de escopos vazia\n");
        exit(-1);
    }
}

void insertSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    if (lookupSymbolWithScope(stack, key) != NULL) {
        printf("Error: Identifier '%s' already declared\n", key);
        exit(ERR_DECLARED);
    }
    SymbolTable* currentScope = stack->stack[stack->top];
    insertSymbol(currentScope, key, line, nature, type, value);
}


void insertSymbolGlobal(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
        if (lookupSymbolWithScope(stack, key) != NULL) {
        printf("Erro: Identificador '%s' já declarado \n", key);
        exit(ERR_DECLARED);
    }
    SymbolTable* globalScope = stack->stack[0];
    insertSymbol(globalScope, key, line, nature, type, value);
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


SymbolData* lookupSymbolWhenUsed(TableStack* stack, const char* key) {
        for (int i = stack->top; i >= 0; i--) {
        SymbolTable* currentScope = stack->stack[i];
        SymbolData* symbol = lookupSymbol(currentScope, key);
        if (symbol != NULL) {
            return symbol;
        }
    }
    exit(ERR_UNDECLARED);
}

void updateSymbol(TableStack* stack, const char* key, const char* value) {
    SymbolData* var = lookupSymbolWithScope(stack, key);
    if (var == NULL) {
        printf("Variable %s has not been declared.", key);
        exit(ERR_UNDECLARED);
    }
    strcpy(var->value, value);
    
}

int inferType(int type1, int type2) {
    if(type1 == FLOAT || type2 == FLOAT) {
        return FLOAT;
    }
    if(type1 == INT || type2 == INT) {
        return INT;
    }
    return BOOL;

}