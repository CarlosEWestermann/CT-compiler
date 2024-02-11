/*UFRGS 2023*/
/* Grupo K */
/*Carlos Eduardo Westermann - 00327212*/
/*Théo Santiago Müller 00301593*/

#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H

#include <stdbool.h>

#define MAX_SCOPES 100 
#define ERR_UNDECLARED 10 
#define ERR_DECLARED 11 
#define ERR_VARIABLE 20 
#define ERR_FUNCTION 21 

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
    bool is_global;
    int memory_offset;
} SymbolData;

typedef struct TableEntry {
    char* key;
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
void insertSymbol(SymbolTable* table, const char* key, int line, SymbolNature nature, SymbolType type, const char* value, bool is_global);
SymbolData* lookupSymbol(SymbolTable* table, const char* key);
void freeTable(SymbolTable* table);
void pushScope(TableStack* stack);
void popScope(TableStack* stack);
void insertSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
void insertSymbolGlobal(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
SymbolData* lookupSymbolWithScope(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
void updateSymbol(TableStack* stack, const char* key, const char* value);
SymbolData* lookupSymbolWhenUsed(TableStack* stack, const char* key, int line, SymbolNature nature, SymbolType type, const char* value);
int inferType(int type1, int type2);
char* get_nature(SymbolNature nature);

#endif /* SYMBOL_TABLE_H */
