#include <stdio.h>
#include <sprint/hash.h>


const char* registers[] = {
    "ax", "cx", "dx", "bx", "sp", "bp", "si", "di",
    "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15"
};

int main() {
    printf("move64: %d\n", strhash("move64"));
    printf("move32: %d\n", strhash("move32"));
    printf("move16: %d\n", strhash("move16"));
    printf("move8: %d\n", strhash("move8"));

    for(int i = 0; i < 32; ++i) {
        printf("%s: %d\n", registers[i], strhash(registers[i]));
    }
}