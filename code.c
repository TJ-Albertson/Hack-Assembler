#include "code.h"
#include <stdio.h>
#include <stdlib.h>

char* dest_bin(char* mnemonic) {
    if (mnemonic == NULL) {
        return "000";
    } else if (strcmp(mnemonic, "M") == 0) {
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
        return NULL;
    }
}

char* comp_bin(char* mnemonic) {

    //printf("comp mnemonic: %s\n", mnemonic);

    char* result = (char*)malloc((7) * sizeof(char));

    
    int c1 = (strchr(mnemonic, '0')) ? '0' : '1';
    int c2 = (strchr(mnemonic, '1')) ? '0' : '1';
    int c3 = (strchr(mnemonic, '-') || strchr(mnemonic, '!')) ? '1' : '0';
    int c4 = (strchr(mnemonic, 'D')) ? '0' : '1';
    int c5 = (strchr(mnemonic, 'A') || strchr(mnemonic, 'M')) ? '0' : '1';
    int c6 = (strchr(mnemonic, 'A') || strchr(mnemonic, 'D')) ? '1' : '0';
    int c7 = (strchr(mnemonic, 'M')) ? '1' : '0';

    result[0] = c1;
    result[1] = c2;
    result[2] = c3;
    result[3] = c4;
    result[4] = c5;
    result[5] = c6;
    result[6] = c7;

    return result;
}

char* jump_bin(char* mnemonic) {
    if (mnemonic == NULL) {
        return "000";
    } else if (strcmp(mnemonic, "JGT") == 0) {
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
        return NULL;
    }
}