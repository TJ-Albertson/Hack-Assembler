#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#include <stdbool.h>

// add an entry to the symbol table
void addEntry(char* name, int address);

// check if an entry exists in the symbol table
bool contains(char* name);

// get the address of an entry in the symbol table
int getAddress(char* name);

#endif