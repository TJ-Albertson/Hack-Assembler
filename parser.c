#include "parser.h"

FILE *fp = NULL;
char instruction[MAX_LINE_LENGTH];

//opens input stream
void parserInitializer(FILE* file) {
    file = fopen("Add.asm", "r");
    fp = file;
};

bool isCommentLine(const char* line) {
    // Skip leading whitespace
    while (isspace(*line)) {
        line++;
    }
    // Check if the first non-whitespace character is a comment marker
    return *line == '/' && *(line + 1) == '/';
}

bool isBlankLine(const char* line) {
    // Skip leading whitespace
    while (isspace(*line)) {
        line++;
    }
    // If we've reached the end of the string, it's a blank line
    return *line == '\0';
}

//Are there more lines in input
bool hasMoreLines(void) {
    if (fp == NULL) {
        printf("fp = NULL\n");
        return false;
    }

    int i = 0;
    while (fgets(instruction, sizeof(instruction), fp) != NULL) {
        printf("Line %d: %s\n", i, instruction);
        i++;
        // Ignore comments and blank lines
        if (isCommentLine(instruction) || isBlankLine(instruction)) {
            continue;
        }
        return true;
    }

    // End of file
    return false;
};

//reads next instruction and skips over whitespace and comments
void advance(void) {
    if (!hasMoreLines()) {
        printf("Not more lines");
        return;
    }

    // Strip whitespace and comments from the current command
    char *comment_start = strchr(instruction, '/');
    if (comment_start != NULL) {
        *comment_start = '\0';
    }
    char *end = instruction + strlen(instruction) - 1;
    while (isspace(*end) && end >= instruction) {
        *end = '\0';
        end--;
    }
};

//returns type of current instruction
InstructionType instructionType(void) {
    
    printf("(Instruction Type) instruction: %s\n", instruction);

    if (strchr(instruction, '@')) {
        return A_INSTRUCTION;
    } 

    if (strchr(instruction, '(')) {
        return L_INSTRUCTION;
    }

    return C_INSTRUCTION;
};

//returns symbol on A or L instruction
char* symbol(void) {
    //return instruction[1] to \n
    if(instructionType()==A_INSTRUCTION) {
        return matchRegex(instruction, "^@(.+)$");
    }

    return matchRegex(instruction, "\\w+");
};

//returns dest part of C instruction
char* dest(void) {
    return matchRegex(instruction, "^([A-Z]+)=.*$");
}

//returns comp part of C instruction
char* comp(void) {
    return matchRegex(instruction, "^[A-Z]+=(.+);$");
}

//returns jump part of C instruction
char* jump(void) {
    return matchRegex(instruction, "^[A-Z]+=.*;([A-Z]+)$");
}