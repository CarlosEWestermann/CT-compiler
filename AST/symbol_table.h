#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SCOPES 100 // Defina o número máximo de escopos


// Definições de enums e estruturas

typedef enum {
    LITERAL,
    IDENTIFIER,
    FUNCTION
} SymbolNature;

typedef enum {
    INT,
    FLOAT,
    IDENTIFICADOR,
    BOOL
} SymbolType;

typedef struct {
    int line;
    SymbolNature nature;
    SymbolType type;
    char value[50];
} SymbolData;

typedef struct TableEntry {
    char key[50];
    SymbolData content;
    struct TableEntry* next;
} TableEntry;

typedef struct {
    TableEntry* table[100];
} SymbolTable;

typedef struct {
    SymbolTable* stack[MAX_SCOPES];
    int top;
} TableStack;

// Assinaturas das funções
void insertSymbol(SymbolTable* table, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
SymbolData* lookupSymbol(SymbolTable* table, const char* key);
void freeTable(SymbolTable* table);
void pushScope(TableStack* stack, SymbolTable* table);
void popScope(TableStack* stack);
void insertSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
SymbolData* lookupSymbolWithScope(TableStack* stack, const char* key);

#endif /* SYMBOL_TABLE_H */
