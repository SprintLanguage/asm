#include <ctype.h>


unsigned int strhash(char* str) {
    unsigned long hash = 5381;
    int c;

    while (c = *str++) {
        if(c == '\0' || !isalnum(c)) return hash;
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }

    return hash;
}