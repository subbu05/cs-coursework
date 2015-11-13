#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#include "symbol.h"
#include "token.h"

void parse(const char* symbolTablePath, const char* mcodePath, token* tokens, symbol* symbolTable);
FILE* openFileParser(const char* path, const char* op);
void writeSymbolTable(symbol* symbolTable, FILE* symTblPtr);
void addToSymbolTable(symbol** symbolTable, char* name, int kind, int value, int level, int address);
int hashToken(char* name, int kind);
void linearProbe(int* index, symbol** symbolTable);
void program(token* tokens, symbol* symbolTable, int level);
void block(token** tokens, symbol* symbolTable, int level);
void constant(token** tokens, symbol* symbolTable, int level);
void variable(token** tokens, symbol* symbolTable, int level);
void procedure(token** tokens, symbol* symbolTable, int level);
void statement(token** tokens, symbol* symbolTable, int level);
void condition(token** tokens, symbol* symbolTable, int level);
void expression(token** tokens, symbol* symbolTable, int level);
void term(token** tokens, symbol* symbolTable, int level);
void factor(token** tokens, symbol* symbolTable, int level);
int lookupIdentifier(char* name, symbol** symbolTable, int level);
