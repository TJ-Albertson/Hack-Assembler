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

    char* result = (char*)malloc((7) * sizeof(char));

    char a = "0";

    if (strchr(mnemonic, "M") == 0) {
        a = "1";
    }

    result[0] = a;

    if (strcmp(mnemonic, "0") == 0) {
        *result+1="101010";
    } else if (strcmp(mnemonic, "1") == 0) {
        return "111111";
    } else if (strcmp(mnemonic, "-1") == 0) {
        return "111010";
    } else if (strcmp(mnemonic, "D") == 0) {
        return "001100";
    } else if (strcmp(mnemonic, "A") == 0 || strcmp(mnemonic, "M") == 0) {
        return "110000";
    } else if (strcmp(mnemonic, "!D") == 0) {
        return "001101";
    } else if (strcmp(mnemonic, "!A") == 0 || strcmp(mnemonic, "!M") == 0) {
        return "110001";
    } else if (strcmp(mnemonic, "-D") == 0) {
        return "001111";
    } else if (strcmp(mnemonic, "-A") == 0 || strcmp(mnemonic, "-M") == 0) {
        return "110011";
    } else if (strcmp(mnemonic, "D+1") == 0) {
        return "011111";
    } else if (strcmp(mnemonic, "A+1") == 0 || strcmp(mnemonic, "M+1") == 0) {
        return "110111";
    } else if (strcmp(mnemonic, "D-1") == 0) {
        return "001110";
    } else if (strcmp(mnemonic, "A-1") == 0 || strcmp(mnemonic, "M-1") == 0) {
        return "110010";
    } else if (strcmp(mnemonic, "D+A") == 0 || strcmp(mnemonic, "D+M") == 0) {
        return "000010";
    } else if (strcmp(mnemonic, "D-A") == 0 || strcmp(mnemonic, "D-M") == 0) {
        return "010011";
    } else if (strcmp(mnemonic, "A-D") == 0 || strcmp(mnemonic, "M-D") == 0) {
        return "000111";
    } else if (strcmp(mnemonic, "D&A") == 0 || strcmp(mnemonic, "D&M") == 0) {
        return "000000";
    } else if (strcmp(mnemonic, "D|A") == 0 || strcmp(mnemonic, "D|M") == 0) {
        return "010101";
    }

    return result;
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