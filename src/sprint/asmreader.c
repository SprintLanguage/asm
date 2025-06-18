#include <sprint/asmreader.h>
#include <sprintasm/x86/inst.h>
#include <sprintasm/loc.h>
#include <sprintasm/x86/modrm.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern uint8_t x86registers[];
char* registernames[] = {"rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"};

sprint_bytebuff_t sprintasm_parseinstruction(char* line) {
    char* buffs = malloc(320);
    memset(buffs, 0, 320);

    char* token = strtok(line, " \t\n");
    int offset = 0;
    while (token && offset < 3) {
        strncpy(buffs + offset * 32, token, 31);
        token = strtok(NULL, " \t\n");
        offset++;
    }

    if(strcmp(buffs, "move64")) {
        uint8_t source = 0;
        uint8_t target = 0;

        for(int i = 0; i < 8; ++i) {
            if(strcmp(buffs + 32, registernames[i]) == 0) {
                source = x86registers[i];
            }

            if(strcmp(buffs + 64, registernames[i]) == 0) {
                target = x86registers[i];
            }

            asmlocation_t* t = sprintasm_locregister(target);
            
            int size = 0;
            uint8_t* buff = sprintasm_modrmmake(source, t, &size);
        }
    }
}

sprint_bytebuff_t sprintasm_parseinstructions(FILE* file) {
    fseek(file, 0, SEEK_SET);
    int sz = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buff = malloc(sz + 1);
    fread(buff, 1, sz, file);

    buff[sz] = '\0';

    char* line = malloc(32);
    int lindex = 0;

    char c;
    while(c = *++buff) {
        if(c == '\0' || c == '\n') {
            sprintasm_parseinstruction(line, out);
            lindex = 0;
        }
        else {
            line[lindex] = c;
            ++lindex;
        }
 
 
    }
    fclose(out);
    fclose(file);
}