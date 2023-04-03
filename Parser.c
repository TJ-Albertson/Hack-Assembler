#include "Parser.h"

char line[MAX_LINE_LENGTH];

//opens input stream
void parserInitializer(FILE* fp) {

    fp = fopen("input.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
    }

    if (fgets(line, MAX_LINE_LENGTH, fp) != NULL) {
        printf("First line: %s", line);
    } else {
        printf("Error: File is empty\n");
    }

};

//Are there more lines in input
bool hasMoreLines(void) {

};

//reads next instruction and skips over whitespace and comments
void advance(void) {

};

//returns type of current instruction
InstructionType instructionType(void) {

};

//returns symbol on A or L instruction
char* symbol(void) {

};

//returns dest part of C instruction
char* dest(void);

//returns comp part of C instruction
char* comp(void);

//returns jump part of C instruction
char* jump(void);