#include "symbolTable.h"

Symbol* SymbolTable;
int size = 0;

void symbolTableInitializer() {
    // Add predefined symbols to symbol table
    
    SymbolTable = malloc(MAX_STRUCT_ARR_SIZE * sizeof(Symbol));

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

    for (int i = 0; i < 50; i++) {
        //printf("Symbol %d: %s\n", i+1, SymbolTable[i].symbol);
        //printf("Address %d: %d\n", i+1, SymbolTable[i].address);
    }
}

void addEntry(char* symbol, int address) {

    if (address >= MAX_STRUCT_ARR_SIZE) {
        return; // error: array full
    }

    if (strlen(symbol) >= MAX_STR_LEN) {
        printf("Error: string too long\n");
        return;
    }
    
    
    strcpy(SymbolTable[size].symbol, symbol);
    //SymbolTable[size].symbol = *symbol;
    SymbolTable[size].address = address;

    printf("Symbol Added: %s %d\n", SymbolTable[size].symbol, SymbolTable[size].address);

    size++;
}

bool contains(char* symbol) {
    int i;
    for (i = 0; i < MAX_STRUCT_ARR_SIZE; i++) {
        if (strcmp(SymbolTable[i].symbol, symbol) == 0) {
            return 1;
        }
    }
    return 0;
}

int getAddress(char* symbol) {
    int i;
    printf("get Addr Symbol: %s\n", symbol);
    for (i = 0; i < MAX_STRUCT_ARR_SIZE; i++) {
        if (strcmp(SymbolTable[i].symbol, symbol) == 0) {
            
            return SymbolTable[i].address;
        }
    }
    return 0;
}