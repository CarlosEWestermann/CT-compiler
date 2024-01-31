/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"

int generate_global_offset() {
    static int global_offset = 0;

    global_offset += sizeof(int); 
    return global_offset;
}

int generate_local_offset() {
    static int local_offset = 0;

    local_offset += sizeof(int); 
    return local_offset;
}
void insertSymbol(SymbolTable* table, const char* key, int line, SymbolNature nature, SymbolType type, const char* value, bool is_global) {
    int i = strlen(key) % 100;

    TableEntry* newEntry = (TableEntry*)malloc(sizeof(TableEntry));
    if (newEntry == NULL) {
        exit(-1);
    }

    newEntry->key = malloc(strlen(key) + 1);
    if (newEntry->key == NULL) {
        free(newEntry); 
        exit(-1);
    }

    strcpy(newEntry->key, key);
    newEntry->content.line = line;
    newEntry->content.nature = nature;
    newEntry->content.type = type;
    newEntry->content.is_global = is_global;
    newEntry->content.memory_offset = is_global ? generate_global_offset() : generate_local_offset;
    strcpy(newEntry->content.value, value);
    newEntry->next = NULL;

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
            exit(-1);
        }

        stack->top++;
        stack->stack[stack->top] = newTable;
    } else {
        printf("Error: scope stack is full\n");
        exit(-1);
    }
}

void popScope(TableStack* stack) {
    if (stack->top >= 0) {
        stack->top--;
    } else {
        printf("Error: scope stack is full\n");
        exit(-1);
    }
}

void insertSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    SymbolData* symbol = lookupSymbolWithScope(stack, key, line, nature, type, value);
    if (symbol != NULL) {
        printf("Error: '%s' of nature %s used in line %d has already been declared in line %d with nature %s.\n", key, get_nature(nature), line, symbol->line, get_nature(symbol->nature));
        exit(ERR_DECLARED);
    }
    SymbolTable* currentScope = stack->stack[stack->top];
    insertSymbol(currentScope, key, line, nature, type, value, false);
}


void insertSymbolGlobal(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    SymbolData* symbol = lookupSymbolWithScope(stack, key, line, nature, type, value);
    if (symbol != NULL) {
        printf("Error: '%s' of nature %s used in line %d has already been declared in line %d with nature %s.\n", key, get_nature(nature), line, symbol->line, get_nature(symbol->nature));
        exit(ERR_DECLARED);
    }
    SymbolTable* globalScope = stack->stack[0];
    insertSymbol(globalScope, key, line, nature, type, value, true);
}

SymbolData* lookupSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    for (int i = stack->top; i >= 0; i--) {
        SymbolTable* currentScope = stack->stack[i];
        SymbolData* symbol = lookupSymbol(currentScope, key);
        if (symbol != NULL) {
            return symbol;
        }
    }
    return NULL;
}

SymbolData* lookupSymbolWhenUsed(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value) {
    for (int i = stack->top; i >= 0; i--) {
        SymbolTable* currentScope = stack->stack[i];
        SymbolData* symbol = lookupSymbol(currentScope, key);
        if (symbol != NULL) {
            return symbol;
        }
    }
    printf("Error: '%s' of nature %s used in line %d has not been declared.\n", key, get_nature(nature), line);
    exit(ERR_UNDECLARED);
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

char* get_nature(SymbolNature nature){
    switch(nature){
        case LITERAL:
            return "LITERAL";
        case IDENTIFIER:
            return "IDENTIFICADOR";
        case FUNCTION:
            return "FUNCAO";
    }
    return "";
}