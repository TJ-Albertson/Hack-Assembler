#include <stdio.h>
#include <string.h>

int main() {
    char arr[] = "Hello, World!";
    char *str = arr + 1; // Create a new string pointer that points to the second element of the array
    
    printf("%s\n", str); // Output: "ello, World!"
    return 0;
}