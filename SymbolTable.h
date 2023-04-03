#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdbool.h>

//creates new symbol table
void initializer(void);

// add an entry to the symbol table
void addEntry(char* symbol, int address);

// check if an entry exists in the symbol table
bool contains(char* symbol);

// get the address of an entry in the symbol table
int getAddress(char* symbol);

#endif