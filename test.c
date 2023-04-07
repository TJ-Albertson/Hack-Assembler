#include <stdio.h>
#include <string.h>
#include <ctype.h>

void modify_string(char *instruction) {
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

    
}

int main() {
    char str[] = "   D=M;JMP   //comment";
    printf("Before: \"%s\" (length %lu)\n", str, strlen(str));
    modify_string(str);
    printf("After: \"%s\" (length %lu)\n", str, strlen(str));
    return 0;
}