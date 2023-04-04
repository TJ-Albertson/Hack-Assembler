#include <stdio.h>
#include <string.h>

void extract_substrings(char* input, char* dest, char* comp, char* jump) {
    char* ptr;
    int count = 0;
    
    // check for format 1: dest=comp;jump
    ptr = strchr(input, '=');
    if (ptr != NULL) {
        count++;
        strncpy(dest, input, ptr - input);
        dest[ptr - input] = '\0';
        
        input = ptr + 1;
        ptr = strchr(input, ';');
        if (ptr != NULL) {
            count++;
            strncpy(comp, input, ptr - input);
            comp[ptr - input] = '\0';
            
            input = ptr + 1;
            count++;
            strcpy(jump, input);
        }
    }
    else {
        // check for format 2: dest=comp
        ptr = strchr(input, ';');
        if (ptr == NULL) {
            count++;
            strcpy(dest, input);
            
            ptr = strchr(input, '=');
            if (ptr != NULL) {
                count++;
                strncpy(comp, ptr + 1, strlen(input) - strlen(dest) - 1);
                comp[strlen(input) - strlen(dest) - 1] = '\0';
            }
        }
        else {
            // check for format 3: dest;jump
            ptr = strchr(input, ';');
            if (ptr != NULL) {
                count++;
                strncpy(dest, input, ptr - input);
                dest[ptr - input] = '\0';
                
                input = ptr + 1;
                count++;
                strcpy(jump, input);
            }
        }
    }
    
    // check if exactly 3 substrings were extracted
    if (count != 3) {
        strcpy(dest, "");
        strcpy(comp, "");
        strcpy(jump, "");
    }
}

int main() {
    char input1[] = "D=M;JNE";
    char dest1[4], comp1[4], jump1[4];
    extract_substrings(input1, dest1, comp1, jump1);
    printf("input: %s\n", input1);
    printf("dest: %s\n", dest1);
    printf("comp: %s\n", comp1);
    printf("jump: %s\n", jump1);
    printf("\n");
    
    char input2[] = "D=A";
    char dest2[4], comp2[4], jump2[4];
    extract_substrings(input2, dest2, comp2, jump2);
    printf("input: %s\n", input2);
    printf("dest: %s\n", dest2);
    printf("comp: %s\n", comp2);
    printf("jump: %s\n", jump2);
    printf("\n");
    
    char input3[] = "D;JGT";
    char dest3[4], comp3[4], jump3[4];
    extract_substrings(input3, dest3, comp3, jump3);
    printf("input: %s\n", input3);
    printf("dest: %s\n", dest3);
    printf("comp: %s\n", comp3);
    printf("jump: %s\n", jump3);
    printf("\n");

}