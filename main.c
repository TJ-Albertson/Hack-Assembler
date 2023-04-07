#include "parser.h"
#include "code.h"
#include "symbolTable.h"
#include <stdlib.h>
#include <stdio.h>


int is_number(char* str) {
  // Iterate through the string, checking each character
  for (int i = 0; str[i] != '\0'; i++) {
    if (!isdigit(str[i])) {
      return 0;  // Not a number
    }
  }
  return 1;  // All characters are digits, so it's a number
}

int main(int argc, char *argv[]) {

    int i = 0;
    int line = -1;
    //first pass

    FILE *fp1;
    

    symbolTableInitializer();
    
    parserInitializer(fp1, argv[1]);
    printf("parser initialized\n");

    //if c continue, if L add 
    while (hasMoreLines())
    {
        line++;

        if (instructionType() == C_INSTRUCTION) {
            continue;
        }

        char* sym = symbol();

        if (is_number(sym)) {
            continue;
        }

        if (instructionType() == L_INSTRUCTION) {
            addEntry(sym, line);
            continue;
        }

        addEntry(sym, 16 + i);
        i++;

        advance();
    }
    printf("\nFirst Pass Done\n");
    //fclose(fp1);
    
    FILE *output;
    FILE *fp;
    char hack[100] = ".hack";

    if (argc != 2) {
        printf("Usage: %s filename\n", argv[0]);
        return -1;
    }

   
    printf("Opened File, Starting Assembly\n");

    parserInitializer(fp, argv[1]);
    printf("parser initialized\n");

    int len = strlen(argv[1]);
    argv[1][len - 4] = '\0';
    strcat(argv[1], hack);

    output = fopen(argv[1], "w");

    //second pass
    while (hasMoreLines())
    {
        advance();


        if(instructionType() == C_INSTRUCTION) {
            printf("C instruction\n");
            printf("------------------------\n");
            printf("comp: %s, dest: %s, jump: %s\n", comp(), dest(), jump());
            printf( "Binary Output: 111 %s %s %s\n\n", comp_bin(comp()), dest_bin(dest()), jump_bin(jump()));

            fprintf(output, "111%s%s%s\n", comp_bin(comp()), dest_bin(dest()), jump_bin(jump()));
            
            continue;
        }

        printf("A instruction\n");
        printf("------------------------\n");



        


        int decimal = strtol(symbol(), NULL, 10); 
        int i, binary[15];

        if (contains(symbol())) {
            decimal = getAddress(symbol());
        }

        printf("Decimal: %d\n", decimal);
        printf("Pre Decimal to Binary Conversion\n");
        fprintf(output, "0");
        printf("Binary Output: 0");
        // Convert decimal to binary
        for (i = 0; i < 15; i++) {
            binary[14 - i] = decimal % 2;
            decimal /= 2;
        }

        for (i = 0; i < 15; i++) {
            fprintf(output, "%d", binary[i]);
            printf("%d", binary[i]);
        }   

        fprintf(output, "\n");
        
        printf("\n\n");
        printf("------------------------\n");

        
    }

    fclose(output);

    return 0;
}