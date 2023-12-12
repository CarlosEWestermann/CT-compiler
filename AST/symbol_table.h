#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#define MAX_SCOPES 100 // Defina o número máximo de escopos

#define ERR_UNDECLARED 10 //2.2
#define ERR_DECLARED 11 //2.2
#define ERR_VARIABLE 20 //2.3
#define ERR_FUNCTION 21 //2.3

// Definições de enums e estruturas

typedef enum {
    LITERAL ,
    IDENTIFIER,
    FUNCTION
} SymbolNature;

typedef enum {
    INT = 259,
    FLOAT = 260,
    BOOL = 261
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

void print_all(TableStack* stack);

// Assinaturas das funções
void insertSymbol(SymbolTable* table, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
SymbolData* lookupSymbol(SymbolTable* table, const char* key);
void freeTable(SymbolTable* table);
void pushScope(TableStack* stack);
void popScope(TableStack* stack);
void insertSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
void insertSymbolGlobal(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
SymbolData* lookupSymbolWithScope(TableStack* stack, const char* key);

#endif /* SYMBOL_TABLE_H */
