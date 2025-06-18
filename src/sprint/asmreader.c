#include <sprint/asmreader.h>
#include <sprintasm/x86/inst.h>
#include <sprintasm/loc.h>
#include <sprintasm/x86/modrm.h>

#include <sprint/hash.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

extern uint8_t x86registers[];
char* registernames[] = {"rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi"};

#define INS_MOVE64 3594
#define INS_MOVE32 1194
#define INS_MOVE16 427
#define INS_MOVE8 1537

#define REG_RAX 2563
#define REG_RCX 1125
#define REG_RDX 2121
#define REG_RBX 3852
#define REG_RSP 1213
#define REG_RBP 2279
#define REG_RSI 313
#define REG_RDI 2418
#define REG_EAX 1692
#define REG_ECX 2618
#define REG_EDX 2021
#define REG_EBX 1095
#define REG_ESP 962
#define REG_EBP 809
#define REG_ESI 1628
#define REG_EDI 3109
#define REG_AX 3840
#define REG_CX 38
#define REG_DX 1572
#define REG_BX 2671
#define REG_SP 521
#define REG_BP 185
#define REG_SI 2386
#define REG_DI 2029
#define REG_AL 1615
#define REG_CL 460
#define REG_DL 2462
#define REG_BL 2881
#define REG_SPL 627
#define REG_BPL 760
#define REG_SIL 715
#define REG_DIL 1860


void sprintasm_parseinstruction(char* line, sprint_bytebuff_t buff) {
    char* buffs = malloc(320);
    memset(buffs, 0, 320);

    char* token = strtok(line, " \t\n");
    int offset = 0;
    while (token && offset < 3) {
        strncpy(buffs + offset * 32, token, 31);
        token = strtok(NULL, " \t\n");
        offset++;
    }

    int instructionHash = strhash(buffs);

    switch(instructionHash) {

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

            asmlocation_t t = {0};
            sprintasm_locregister(target, &t);

            int size = 0;
            sprintasm_modrmmake(source, &t, &size, buff);
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

    sprint_bytebuff_t* bytebuff = malloc(sizeof(sprint_bytebuff_t));
    bytebuff->allocated = 128;
    bytebuff->sz = 0;

    bytebuff->buff = malloc(128);

    char c;
    while(c = *++buff) {
        if(c == '\0' || c == '\n') {
            sprintasm_parseinstruction(line, *bytebuff);
            lindex = 0;
        }
        else {
            line[lindex] = c;
            ++lindex;
        }
 
 
    }
    fclose(file);

    return *bytebuff;
}