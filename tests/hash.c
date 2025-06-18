#include <stdio.h>
#include <sprint/hash.h>


const char* registers[] = {
    "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
    "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi",
    "ax", "cx", "dx", "bx", "sp", "bp", "si", "di",
    "al", "cl", "dl", "bl", "spl", "bpl", "sil", "dil"
};

int main2() {
    printf("move64: %d\n", strhash("move64"));
    printf("move32: %d\n", strhash("move32"));
    printf("move16: %d\n", strhash("move16"));
    printf("move8: %d\n", strhash("move8"));

    for(int i = 0; i < 32; ++i) {
        printf("%s: %d\n", registers[i], strhash(registers[i]));
    }
}