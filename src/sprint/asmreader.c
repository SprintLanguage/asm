#include <sprint/asmreader.h>
#include <sprintasm/x86/inst.h>
#include <sprintasm/loc.h>
#include <sprintasm/x86/reg.h>
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

#define REG_AX 3840
#define REG_CX 38
#define REG_DX 1572
#define REG_BX 2671
#define REG_SP 521
#define REG_BP 185
#define REG_SI 2386
#define REG_DI 2029

#define REG_R8 3704
#define REG_R9 2653
#define REG_R10 1222
#define REG_R11 2671
#define REG_R12 3652
#define REG_R13 2760
#define REG_R14 1793
#define REG_R15 644

uint8_t sprintasm_isregextended(uint8_t reg) {
    switch(reg) {
        case REGISTER_R8:
        case REGISTER_R9:
        case REGISTER_R10:
        case REGISTER_R11:
        case REGISTER_R12:
        case REGISTER_R13:
        case REGISTER_R14:
        case REGISTER_R15:
            return 0x01;    
    }

    return 0x00;
}

uint8_t sprintasm_findreg(char* str) {
    switch(strhash(str)) {
        case REG_AX:
            return REGISTER_AL;

        case REG_CX:
            return REGISTER_CL;  
        
        case REG_BX:
            return REGISTER_BL;
         
        case REG_DX:
            return REGISTER_DL;

        case REG_SP:
            return REGISTER_SPL;
         
        case REG_BP:
            return REGISTER_BPL;

        case REG_SI:
            return REGISTER_SIL;
        
        case REG_DI:
            return REGISTER_DIL;    

        case REG_R9:
            return REGISTER_R9;    
    }
}

void sprintasm_parseinstruction(char* line, sprint_bytebuff_t* buff) {
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
        case INS_MOVE64:
        case INS_MOVE32:
        case INS_MOVE16:
        case INS_MOVE8:
            if(instructionHash == INS_MOVE64 || instructionHash == INS_MOVE16) {
                buff->buff[buff->sz] = (instructionHash == INS_MOVE64) ? PREFIX_64BITS : PREFIX_16BITS;
                +buff->sz;
            }

            buff->buff[buff->sz] = MOVE_REGTO_RM;
            ++buff->sz;

            uint8_t reg = sprintasm_findreg(buffs + 32);
            uint8_t target = sprintasm_findreg(buffs + 64);

            asmlocation_t loc = {0};
            sprintasm_locregister(target, &loc);

            int size = 0;
            sprintasm_modrmmake(reg, &loc, &size, buff);
            break;
         
        default:
            printf("%d\n", instructionHash);  
    }
}

sprint_bytebuff_t* sprintasm_parseinstructions(FILE* file) {
    fseek(file, 0, SEEK_END);
    int sz = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buff = malloc(sz + 1);
    sz = fread(buff, 1, sz, file);

    fclose(file);

    buff[sz] = '\0';

    char* line = malloc(32);
    int lindex = 0;

    sprint_bytebuff_t* bytebuff = malloc(sizeof(sprint_bytebuff_t));
    bytebuff->allocated = 128;
    bytebuff->sz = 0;

    bytebuff->buff = malloc(128);

    char c;
    while(c = *buff++) {
        printf("%c ", c);
        if(c == '\0' || c == '\n') {
            printf("Parsing line!\n");
            sprintasm_parseinstruction(line, bytebuff);
            lindex = 0;
        }
        else {
            line[lindex] = c;
            ++lindex;
        }
    }

    if(lindex > 0) {
        sprintasm_parseinstruction(line, bytebuff);
    }

    return bytebuff;
}