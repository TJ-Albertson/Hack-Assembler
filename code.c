#include "code.h"
#include <stdio.h>
#include <stdlib.h>

char* dest_bin(char* mnemonic) {
    if (strcmp(mnemonic, "M") == 0) {
        return "001";
    } else if (strcmp(mnemonic, "D") == 0) {
        return "010";
    } else if (strcmp(mnemonic, "DM") == 0) {
        return "011";
    } else if (strcmp(mnemonic, "A") == 0) {
        return "100";
    } else if (strcmp(mnemonic, "AM") == 0) {
        return "101";
    } else if (strcmp(mnemonic, "AD") == 0) {
        return "110";
    } else if (strcmp(mnemonic, "ADM") == 0) {
        return "111";
    } else {
        return "000";
    }
}

char* comp_bin(char* mnemonic) {

    //printf("comp mnemonic: %s\n", mnemonic);
    //char* result = (char*)malloc((7) * sizeof(char));

    char a = '0';

    if (strchr(mnemonic, 'M') != 0) {
        a = '1';
    }

    char *original;

    if (strcmp(mnemonic, "0") == 0) {
        original="101010";
    } else if (strcmp(mnemonic, "1") == 0) {
        original="111111";
    } else if (strcmp(mnemonic, "-1") == 0) {
        original="111010";
    } else if (strcmp(mnemonic, "D") == 0) {
        original="001100";
    } else if (strcmp(mnemonic, "A") == 0 || strcmp(mnemonic, "M") == 0) {
        original="110000";
    } else if (strcmp(mnemonic, "!D") == 0) {
        original="001101";
    } else if (strcmp(mnemonic, "!A") == 0 || strcmp(mnemonic, "!M") == 0) {
        original="110001";
    } else if (strcmp(mnemonic, "-D") == 0) {
        original="001111";
    } else if (strcmp(mnemonic, "-A") == 0 || strcmp(mnemonic, "-M") == 0) {
        original="110011";
    } else if (strcmp(mnemonic, "D+1") == 0) {
        original="011111";
    } else if (strcmp(mnemonic, "A+1") == 0 || strcmp(mnemonic, "M+1") == 0) {
        original="110111";
    } else if (strcmp(mnemonic, "D-1") == 0) {
        original="001110";
    } else if (strcmp(mnemonic, "A-1") == 0 || strcmp(mnemonic, "M-1") == 0) {
        original="110010";
    } else if (strcmp(mnemonic, "D+A") == 0 || strcmp(mnemonic, "D+M") == 0) {
        original="000010";
    } else if (strcmp(mnemonic, "D-A") == 0 || strcmp(mnemonic, "D-M") == 0) {
        original="010011";
    } else if (strcmp(mnemonic, "A-D") == 0 || strcmp(mnemonic, "M-D") == 0) {
        original="000111";
    } else if (strcmp(mnemonic, "D&A") == 0 || strcmp(mnemonic, "D&M") == 0) {
        original="000000";
    } else if (strcmp(mnemonic, "D|A") == 0 || strcmp(mnemonic, "D|M") == 0) {
        original="010101";
    }

    char *newstr = malloc(strlen(original) + 2);
    newstr[0] = a;
    strcpy(newstr + 1, original);

    printf("newstr: %s\n", newstr);
    return newstr;
}

char* jump_bin(char* mnemonic) {
    if (strcmp(mnemonic, "JGT") == 0) {
        return "001";
    } else if (strcmp(mnemonic, "JEQ") == 0) {
        return "010";
    } else if (strcmp(mnemonic, "JGE") == 0) {
        return "011";
    } else if (strcmp(mnemonic, "JLT") == 0) {
        return "100";
    } else if (strcmp(mnemonic, "JNE") == 0) {
        return "101";
    } else if (strcmp(mnemonic, "JLE") == 0) {
        return "110";
    } else if (strcmp(mnemonic, "JMP") == 0) {
        return "111";
    } else {
        return "000";
    }
}