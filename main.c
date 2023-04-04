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
    while (hasMoreLines)
    {
        advance();
        
        if(instructionType() == C_INSTRUCTION) {
            printf("C instruction\n");
            fprintf(output, "111%s%s%s\n", dest_bin(dest()), comp_bin(comp()), jump_bin(jump()));
            continue;
        }

        printf("A instruction\n");

        int decimal = strtol(symbol(), NULL, 10); 
        int i;

        printf("Decimal: %d\n", decimal);
        printf("Pre Decimal to Binary Conversion\n");
        fprintf(output, "0");
        printf("0");
        // Convert decimal to binary
        for (i = 14; i >= 0; i--) {
            fprintf(output, "%d", decimal & 1);
            printf("%d", decimal & 1);
            decimal >>= 1;
        }
        fprintf(output, "\n");
        printf("\n");

    }

    fclose(fp);
    fclose(output);

    return 0;
}