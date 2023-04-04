#include <regex.h>
#include <stdlib.h>
#include <string.h>
#include "regexUtils.h"


#include <stdio.h>

char* matchRegex(const char* input, const char* pattern) {
    regex_t regex;
    regmatch_t match;
    int reti;

  

    // Compile the regex pattern
    reti = regcomp(&regex, pattern, 0);
    if (reti) {
        return "";
    }

    //SEg fault  here vvvvvvvvvv

    // Execute the regex pattern on the input string
    reti = regexec(&regex, input, 1, &match, 0);

    //issue is this returning null. this function should never return NULL
    if (reti) {
        regfree(&regex);
        return "";
    }
    //SEg fault  here ^^^^^^^^^

    // Extract the matched substring
    size_t match_len = match.rm_eo - match.rm_so;
    char* result = malloc(match_len + 1);
    strncpy(result, input + match.rm_so, match_len);
    result[match_len] = '\0';

    // Free the regex object and return the matched substring
    regfree(&regex);
    return result;
}