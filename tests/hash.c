#include <stdio.h>
#include <sprint/hash.h>
#include <string.h>
#include <ctype.h>


const char* registers[] = {
    "move64", "move32", "move16", "move8",
    "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
    "r8", "r9", "r10", "r11", "r12", "r13", "r14", "r15",
    "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi",
    "ax", "cx", "dx", "bx", "sp", "bp", "si", "di",
    "al", "cl", "dl", "bl", "spl", "bpl", "sil", "dil"
};

char* upperCase(char str[256]) {
    for(int i = 0; i < strlen(str); ++i) {
        str[i] = toupper(str[i]);
    }

    return str;
}

int main() {
    char buffer[256];

    for(int i = 0; i < 44; ++i) {
        strncpy(buffer, registers[i], sizeof(buffer));
        buffer[sizeof(buffer) - 1] = '\0';
        unsigned int hash = strhash(buffer);
        upperCase(buffer);
        printf("#define TOKEN_%s %d\n", buffer, hash);
    }
}