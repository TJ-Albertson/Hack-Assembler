#include "code.h"

char* dest_bin(char* mnemonic) {
    int d1 = strchr(mnemonic, 'A') ? 1 : 0;
    int d2 = strchr(mnemonic, 'D') ? 1 : 0;
    int d3 = strchr(mnemonic, 'M') ? 1 : 0;

    return "" + d1 + d2 + d3;
}

char* comp_bin(char* mnemonic) {

    int c1 = (strchr(mnemonic, '0')) ? 0 : 1;
    int c2 = (strchr(mnemonic, '1')) ? 0 : 1;
    int c3 = (strchr(mnemonic, '-') || strchr(mnemonic, '!')) ? 1 : 0;
    int c4 = (strchr(mnemonic, 'D')) ? 0 : 1;
    int c5 = (strchr(mnemonic, 'A') || strchr(mnemonic, 'M')) ? 0 : 1;
    int c6 = (strchr(mnemonic, 'A') || strchr(mnemonic, 'D')) ? 1 : 0;
    int c7 = (strchr(mnemonic, 'M')) ? 1 : 0;

    return "" + c1 + c2 + c3 + c4 + c5 + c6 + c7;
}

char* jump_bin(char* mnemonic) {
    int j1 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'G')) ? 1 : 0;
    int j2 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'E')) ? 1 : 0;
    int j3 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'L')) ? 1 : 0;
    int j4 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'N')) ? 1 : 0;
    int j5 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'M')) ? 1 : 0;
    int j6 = (strchr(mnemonic, 'J') && strchr(mnemonic, 'P')) ? 1 : 0;

    return "" + j1 + j2 + j3 + j4 + j5 + j6;
}