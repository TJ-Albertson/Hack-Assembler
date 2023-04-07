#ifndef SYMBOLTABLE_H
#define SYMBOLTABLE_H

#define MAX_STRUCT_ARR_SIZE 30000
#define MAX_STR_LEN 100

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Symbol {
    char symbol[50];
    int address;
} Symbol;

//creates new symbol table
void symbolTableInitializer(void);

// add an entry to the symbol table
void addEntry(char* symbol, int address);

// check if an entry exists in the symbol table
bool contains(char* symbol);

// get the address of an entry in the symbol table
int getAddress(char* symbol);

#endif