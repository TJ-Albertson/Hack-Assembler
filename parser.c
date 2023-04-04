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
    fclose(fp);
    return false;
};

//reads next instruction and skips over whitespace and comments
void advance(void) {
    /*
    if (!hasMoreLines()) {
        printf("Not more lines");
        return;
    }*/

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
    
    //printf("(Instruction Type) instruction: %s\n", instruction);

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
        int len = strlen(instruction);
        memmove(instruction, instruction + 1, len);
        instruction[len - 1] = '\0';
        return instruction;
    }
    
    //L instruction
    return matchRegex(instruction, "\\w+");
};

//returns dest part of C instruction
char* dest(void) {

    char* equal_ptr = strchr(instruction, '=');

    // Find the first occurrence of ";" in the string
    char* semicolon_ptr = strchr(instruction, ';');

    if (equal_ptr != NULL) {
        // Allocate a new string buffer to hold the result
        char* result = (char*)malloc(equal_ptr - instruction + 1);

        // Copy the string before "=" into the result string
        strncpy(result, instruction, equal_ptr - instruction);
        result[equal_ptr - instruction] = '\0';

        return result;
    } else if (semicolon_ptr != NULL) {
        // Allocate a new string buffer to hold the result
        char* result = (char*)malloc(semicolon_ptr - instruction + 1);

        // Copy the string before ";" into the result string
        strncpy(result, instruction, semicolon_ptr - instruction);
        result[semicolon_ptr - instruction] = '\0';

        return result;
    }

    // If neither "=" nor ";" character was found, return NULL
    return NULL;
}

//returns comp part of C instruction if it exist
char* comp(void) {
    char* equal_ptr = strchr(instruction, '=');

    // Find the first occurrence of ";" in the string
    char* semicolon_ptr = strchr(instruction, ';');

    if (equal_ptr != NULL && semicolon_ptr != NULL) {
        // Calculate the position of the "=" and ";" characters
        int equal_pos = (int)(equal_ptr - instruction);
        int semicolon_pos = (int)(semicolon_ptr - instruction);

        if (equal_pos < semicolon_pos) {
            // Allocate a new string buffer to hold the result
            char* result = (char*)malloc(semicolon_pos - equal_pos);
        
            // Copy the string between "=" and ";" into the result string
            strncpy(result, equal_ptr + 1, semicolon_pos - equal_pos - 1);
            result[semicolon_pos - equal_pos - 1] = '\0';

            int len = strlen(result);
                while (len > 0 && isspace(result[len - 1])) {
                    result[len - 1] = '\0';
                    len--;
                }
            
            return result;
        }
    } else if (equal_ptr != NULL) {
        // Allocate a new string buffer to hold the result
        char* result = (char*)malloc(strlen(equal_ptr + 1));
        
        // Copy the string after "=" into the result string
        strcpy(result, equal_ptr + 1);

        int len = strlen(result);
                while (len > 0 && isspace(result[len - 1])) {
                    result[len - 1] = '\0';
                    len--;
                }
            
        
        return result;
    }

    // If no "=" character was found or if the ";" character comes before "=", return NULL
    return NULL;
}

//returns jump part of C instruction if it exist
char* jump(void) {

    // Find the first occurrence of ";" in the string
    char* semicolon_ptr = strchr(instruction, ';');

    if (semicolon_ptr != NULL) {
        // Calculate the position of the ";" character
        int semicolon_pos = (int)(semicolon_ptr - instruction);

        // Allocate a new string buffer to hold the result
        char* result = (char*)malloc(strlen(instruction) - semicolon_pos);

        // Copy everything after the ";" character into the result string
        strcpy(result, semicolon_ptr + 1);
        
        return result;
    } else {
        // If no ";" character was found, return null
        return "";
    }
}