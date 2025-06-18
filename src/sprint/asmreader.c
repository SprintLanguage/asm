#include <sprint/asmreader.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

uint8_t* sprintasm_parseinstruction(char* line) {
    char* buffs = malloc(320);
    memset(buffs, 0, 320);

    char* token = strtok(line, " \t\n");
    int offset = 0;
    while (token && offset < 3) {
        strncpy(buffs + offset * 32, token, 31);
        token = strtok(NULL, " \t\n");
        offset++;
    }

    printf("Name: %s\n", buffs);
    printf("Arg 1: %s\n", buffs + 32);
    printf("Arg 2: %s\n", buffs + 64);

    return (uint8_t*)buffs;
}

uint8_t* sprintasm_parseinstructions(FILE* file) {

}