#include "Parser.h"

static FILE *fp = NULL;
char line[MAX_LINE_LENGTH];

//opens input stream
void parserInitializer(FILE* fp) {
    fp = fopen("input.txt", "r");
};

//Are there more lines in input
bool hasMoreLines(void) {
    if (fp == NULL) {
        return false;
    }

    while (fgets(line, sizeof(line), fp) != NULL) {
        // Ignore comments and blank lines
        if (line[0] == '\n' || line[0] == '/' && line[1] == '/') {
            continue;
        }
        return true;
    }

    // End of file
    return false;

};

//reads next instruction and skips over whitespace and comments
void advance(void) {
    if (!hasMoreCommands()) {
        return;
    }

    // Strip whitespace and comments from the current command
    char *comment_start = strchr(line, '/');
    if (comment_start != NULL) {
        *comment_start = '\0';
    }
    char *end = line + strlen(line) - 1;
    while (isspace(*end) && end >= line) {
        *end = '\0';
        end--;
    }
};

//returns type of current instruction
InstructionType instructionType(void) {
    if (line[0]=="@") {
        return A_INSTRUCTION;
    } 

    if (line[0]=="(") {
        return L_INSTRUCTION;
    }

    return C_INSTRUCTION;
};

//returns symbol on A or L instruction
char* symbol(void) {
    //return line[1] to \n
};

//returns dest part of C instruction
char* dest(void) {
    //return line[
}

//returns comp part of C instruction
char* comp(void);

//returns jump part of C instruction
char* jump(void);