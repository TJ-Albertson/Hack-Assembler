#include "parser.h"
#include "code.h"
//#include "symbolTable.h"
#include <stdlib.h>

int main() {
    
    FILE *output;
    FILE *fp;

    output = fopen("output.txt", "w");
    printf("Opened File, Starting Assembly\n");

    parserInitializer(fp);
    printf("parser initialized\n");

    //second pass
    while (hasMoreLines())
    {
        if(instructionType() == C_INSTRUCTION) {
            printf("C instruction\n");
            printf("------------------------\n");
            printf("dest: %s, comp: %s, jump: %s\n", dest(), comp(), jump());
            printf( "Binary Output: 111%s%s%s\n\n", dest_bin(dest()), comp_bin(comp()), jump_bin(jump()));

            fprintf(output, "111%s%s%s\n", dest_bin(dest()), comp_bin(comp()), jump_bin(jump()));
            
            continue;
        }

        printf("A instruction\n");
        printf("------------------------\n");

        int decimal = strtol(symbol(), NULL, 10); 
        int i, binary[15];

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

        advance();
    }

    fclose(output);

    return 0;
}