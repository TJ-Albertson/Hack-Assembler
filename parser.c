#include "parser.h"

FILE *fp = NULL;
char instruction[MAX_LINE_LENGTH];

// opens input stream
void parserInitializer(FILE *file, char *fileName)
{
    file = fopen(fileName, "r");
    fp = file;
};

bool isCommentLine(const char *line)
{
    // Skip leading whitespace
    while (isspace(*line))
    {
        line++;
    }
    // Check if the first non-whitespace character is a comment marker
    return *line == '/' && *(line + 1) == '/';
}

bool isBlankLine(const char *line)
{
    // Skip leading whitespace
    while (isspace(*line))
    {
        line++;
    }
    // If we've reached the end of the string, it's a blank line
    return *line == '\0';
}

// Are there more lines in input
bool hasMoreLines(void)
{
    if (fp == NULL)
    {
        printf("fp = NULL\n");
        return false;
    }

    int i = 0;
    while (fgets(instruction, sizeof(instruction), fp) != NULL)
    {
        //printf("Line %d: %s\n", i, instruction);
        i++;
        // Ignore comments and blank lines
        if (isCommentLine(instruction) || isBlankLine(instruction))
        {
            continue;
        }
        return true;
    }

    // End of file
    fclose(fp);
    return false;
};

// reads next instruction and skips over whitespace and comments
void advance(void)
{
    // Remove leading white space
    char *start = instruction;
    while (isspace(*start)) {
        start++;
    }
    memmove(instruction, start, strlen(start) + 1);


    // Remove comment
    char *comment = strstr(instruction, "//");
    if (comment != NULL) {
        *comment = '\0';
    }
    
    // Remove trailing white space
    char *end = instruction + strlen(instruction) - 1;
    while (end > instruction && isspace(*end)) {
        end--;
    }
    *(end+1) = '\0';

    //printf("\nInstruction: %s\n\n", instruction);
};

// returns type of current instruction
InstructionType instructionType(void)
{

    // printf("(Instruction Type) instruction: %s\n", instruction);

    if (strchr(instruction, '@'))
    {
        return A_INSTRUCTION;
    }

    if (strchr(instruction, '('))
    {
        return L_INSTRUCTION;
    }

    return C_INSTRUCTION;
};

// returns symbol on A or L instruction
char *symbol(void)
{
    // return instruction[1] to \n
    if (instructionType() == A_INSTRUCTION)
    {
        int len = strlen(instruction);
        memmove(instruction, instruction + 1, len);
        instruction[len - 1] = '\0';
        return instruction;
    }


    //printf("--instruction: %s\n", instruction);
    // L instruction
    char* result = NULL;
    char* start = strchr(instruction, '(');
    if (start != NULL) {
        start++; // move past the opening parenthesis
        char* end = strchr(start, ')');
        if (end != NULL) {
            size_t length = end - start;
            result = (char*) malloc(length + 1); // allocate memory for result
            if (result != NULL) {
                strncpy(result, start, length);
                result[length] = '\0'; // add null terminator
            }
        }
    }
    return result;
};

// returns dest part of C instruction
char *dest(void)
{
    if (instruction == NULL)
    {
        return "";
    }

    char *ptr = strchr(instruction, '=');

    if (ptr == NULL)
    {
        return "";
    }

    size_t length = ptr - instruction;
    char *result = strndup(instruction, length);

    return result;
}

// returns comp part of C instruction if it exist
char *comp(void)
{
    char *result = NULL;
    char *ptr = NULL;

    // If input is NULL or empty string, return NULL
    if (instruction == NULL || strlen(instruction) == 0)
    {
        return NULL;
    }

    // Find the position of "=" and ";"
    char *eq_ptr = strchr(instruction, '=');
    char *semicolon_ptr = strchr(instruction, ';');

    if (eq_ptr != NULL && semicolon_ptr != NULL)
    {
        // If both "=" and ";" are found, extract the string in between
        ptr = eq_ptr + 1;
        size_t length = semicolon_ptr - ptr;
        result = strndup(ptr, length);
    }
    else if (eq_ptr != NULL)
    {
        // If only "=" is found, extract the string after it
        ptr = eq_ptr + 1;
        result = strdup(ptr);
    }
    else if (semicolon_ptr != NULL)
    {
        // If only ";" is found, extract the string before it
        size_t length = semicolon_ptr - instruction;
        result = strndup(instruction, length);
    }
    else
    {
        // Otherwise, return NULL
        return NULL;
    }

    // Remove trailing whitespace or newline
    char *end = result + strlen(result) - 1;
    while (isspace(*end))
    {
        end--;
    }
    *(end + 1) = '\0';

    return result;
}

// returns jump part of C instruction if it exist
char *jump(void)
{

    // Find the first occurrence of ";" in the string
    char *semicolon_ptr = strchr(instruction, ';');

    if (semicolon_ptr != NULL)
    {
        // Calculate the position of the ";" character
        int semicolon_pos = (int)(semicolon_ptr - instruction);

        // Allocate a new string buffer to hold the result
        char *result = (char *)malloc(strlen(instruction) - semicolon_pos);

        // Copy everything after the ";" character into the result string
        strcpy(result, semicolon_ptr + 1);

        return result;
    }
    else
    {
        // If no ";" character was found, return null
        return "";
    }
}