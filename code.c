#include "code.h"
#include <stdio.h>
#include <stdlib.h>

char* dest_bin(char* mnemonic) {

    char* bits = malloc(4 * sizeof(char));  // allocate 4 bytes for the null terminator
    memset(bits, '0', 3 * sizeof(char));   // set all bits to 0
    
    if (strchr(mnemonic, 'A') != NULL) {
        bits[0] = '1';
    }
    if (strchr(mnemonic, 'D') != NULL) {
        bits[1] = '1';
    }
    if (strchr(mnemonic, 'M') != NULL) {
        bits[2] = '1';
    }
    
    bits[3] = '\0';  // null terminate the string
    
    return bits;
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
    } else {
        original="101010";
    }

    char *newstr = malloc(strlen(original) + 2);
    newstr[0] = a;
    strcpy(newstr + 1, original);

    //printf("newstr: %s\n", newstr);
    return newstr;
}

char* jump_bin(char* mnemonic) {

    //printf("jump mnemonic: %s\n", mnemonic);

    if (strstr(mnemonic, "JGT")) {
        return "001";
    } else if (strstr(mnemonic, "JEQ")) {
        return "010";
    } else if (strstr(mnemonic, "JGE")) {
        return "011";
    } else if (strstr(mnemonic, "JLT")) {
        return "100";
    } else if (strstr(mnemonic, "JNE")) {
        return "101";
    } else if (strstr(mnemonic, "JLE")) {
        return "110";
    } else if (strstr(mnemonic, "JMP")) {
        return "111";
    } else {
        return "000";
    }
}