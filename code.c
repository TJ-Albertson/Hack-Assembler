#include "code.h"
#include <stdio.h>
#include <stdlib.h>

char* dest_bin(char* mnemonic) {

    //printf("dest mnemonic: %s\n", mnemonic);

    char* result = (char*)malloc((3) * sizeof(char));

    char d1 = strchr(mnemonic, 'A') ? '1' : '0';
    char d2 = strchr(mnemonic, 'D') ? '1' : '0';
    char d3 = strchr(mnemonic, 'M') ? '1' : '0';

    result[0] = d1;
    result[1] = d2;
    result[2] = d3;

    return result;
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

    //printf("jump mnemonic: %s\n", mnemonic);

    char* result = (char*)malloc((3) * sizeof(char));

    int j1 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'G')) ? '1' : '0';
    int j2 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'E')) ? '1' : '0';
    int j3 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'L')) ? '1' : '0';
    int j4 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'N')) ? '1' : '0';
    int j5 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'M')) ? '1' : '0';
    int j6 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'P')) ? '1' : '0';

    result[0] = j1;
    result[1] = j2;
    result[2] = j3;

    return result;
}