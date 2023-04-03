#include "SymbolTable.h"

struct SymbolTable SymbolTable[MAX_STRUCT_ARR_SIZE] = {};

void symbolTableInitializer() {
    // Add predefined symbols to symbol table
    addEntry("R0", 0);
    addEntry("R1", 1);
    addEntry("R2", 2);
    addEntry("R3", 3);
    addEntry("R4", 4);
    addEntry("R5", 5);
    addEntry("R6", 6);
    addEntry("R7", 7);
    addEntry("R8", 8);
    addEntry("R9", 9);
    addEntry("R10", 10);
    addEntry("R11", 11);
    addEntry("R12", 12);
    addEntry("R13", 13);
    addEntry("R14", 14);
    addEntry("R15", 15);
    addEntry("SCREEN", 16384);
    addEntry("KBD", 24576);
    addEntry("SP", 0);
    addEntry("LCL", 1);
    addEntry("ARG", 2);
    addEntry("THIS", 3);
    addEntry("THAT", 4);
    addEntry("LOOP", 4);
    addEntry("STOP", 18);
    addEntry("i", 16);
    addEntry("sum", 17);
}

void addEntry(char* symbol, int address) {

    if (strlen(symbol) >= MAX_STR_LEN) {
        printf("Error: string too long\n");
        return;
    }

    struct SymbolTable new_struct = { symbol, address };
    int i;
    for (i = 0; i < MAX_STRUCT_ARR_SIZE; i++) {
        if (SymbolTable[i].address == 0) {
            SymbolTable[i] = new_struct;
            return;
        }
    }
}

bool contains(char* symbol) {
    int i;
    for (i = 0; i < MAX_STRUCT_ARR_SIZE; i++) {
        if (strcmp(SymbolTable[i].symbol, contains) == 0) {
            return 1;
        }
    }
    return 0;
}

int getAddress(char* symbol) {
    int i;
    for (i = 0; i < MAX_STRUCT_ARR_SIZE; i++) {
        if (SymbolTable[i].symbol == symbol) {
            return SymbolTable[i].address;
        }
    }
    return 0;
}