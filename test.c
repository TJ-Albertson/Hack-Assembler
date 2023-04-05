#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *original = "world!"; // Initialize the original string
    char *newstr = malloc(strlen(original) + 2); // Allocate memory for the new string, including space for the added character and the null terminator
    newstr[0] = 'h'; // Add the desired character to the beginning of the new string
    strcpy(newstr + 1, original); // Copy the rest of the original string into the new string

    printf("%s\n", newstr); // Output the new string
    free(newstr); // Free the allocated memory
    return 0;
}