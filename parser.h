#ifndef PARSER_H
#define PARSER_H

#define MAX_LINE_LENGTH 100

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "regexUtils.h"

typedef enum {
  A_INSTRUCTION,
  C_INSTRUCTION,
  L_INSTRUCTION
} InstructionType;

//opens input stream
void parserInitializer(FILE* fp);

//Are there more lines in input
bool hasMoreLines(void);

//reads next instruction and skips over whitespace and comments
void advance(void);

//returns type of current instruction
InstructionType instructionType(void);

//returns symbol on A or L instruction
char* symbol(void);

//returns dest part of C instruction
char* dest(void);

//returns comp part of C instruction
char* comp(void);

//returns jump part of C instruction
char* jump(void);

#endif