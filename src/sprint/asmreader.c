#include <sprint/asmreader.h>
#include <sprintasm/x86/inst.h>
#include <sprintasm/loc.h>
#include <sprintasm/x86/reg.h>
#include <sprintasm/x86/modrm.h>
#include <sprintasm/x86/rex.h>

#include <sprint/hash.h>

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

void sprintasm_parseregister(unsigned int token, asm_register_t* reg) {
    switch(token) {
        // 64-bit registers
        case TOKEN_RAX: reg->bit = REGISTER_RAX; reg->type = BITS64; break;
        case TOKEN_RCX: reg->bit = REGISTER_RCX; reg->type = BITS64; break;
        case TOKEN_RDX: reg->bit = REGISTER_RDX; reg->type = BITS64; break;
        case TOKEN_RBX: reg->bit = REGISTER_RBX; reg->type = BITS64; break;
        case TOKEN_RSP: reg->bit = REGISTER_RSP; reg->type = BITS64; break;
        case TOKEN_RBP: reg->bit = REGISTER_RBP; reg->type = BITS64; break;
        case TOKEN_RSI: reg->bit = REGISTER_RSI; reg->type = BITS64; break;
        case TOKEN_RDI: reg->bit = REGISTER_RDI; reg->type = BITS64; break;

        // 64-bit extended registers (REX)
        case TOKEN_R8:  reg->bit = REGISTER_R8;  reg->type = REX_EXTENDED; break;
        case TOKEN_R9:  reg->bit = REGISTER_R9;  reg->type = REX_EXTENDED; break;
        case TOKEN_R10: reg->bit = REGISTER_R10; reg->type = REX_EXTENDED; break;
        case TOKEN_R11: reg->bit = REGISTER_R11; reg->type = REX_EXTENDED; break;
        case TOKEN_R12: reg->bit = REGISTER_R12; reg->type = REX_EXTENDED; break;
        case TOKEN_R13: reg->bit = REGISTER_R13; reg->type = REX_EXTENDED; break;
        case TOKEN_R14: reg->bit = REGISTER_R14; reg->type = REX_EXTENDED; break;
        case TOKEN_R15: reg->bit = REGISTER_R15; reg->type = REX_EXTENDED; break;

        // 32-bit registers
        case TOKEN_EAX: reg->bit = REGISTER_EAX; reg->type = BITS32; break;
        case TOKEN_ECX: reg->bit = REGISTER_ECX; reg->type = BITS32; break;
        case TOKEN_EDX: reg->bit = REGISTER_EDX; reg->type = BITS32; break;
        case TOKEN_EBX: reg->bit = REGISTER_EBX; reg->type = BITS32; break;
        case TOKEN_ESP: reg->bit = REGISTER_ESP; reg->type = BITS32; break;
        case TOKEN_EBP: reg->bit = REGISTER_EBP; reg->type = BITS32; break;
        case TOKEN_ESI: reg->bit = REGISTER_ESI; reg->type = BITS32; break;
        case TOKEN_EDI: reg->bit = REGISTER_EDI; reg->type = BITS32; break;

        // 16-bit registers
        case TOKEN_AX: reg->bit = REGISTER_AX; reg->type = BITS16; break;
        case TOKEN_CX: reg->bit = REGISTER_CX; reg->type = BITS16; break;
        case TOKEN_DX: reg->bit = REGISTER_DX; reg->type = BITS16; break;
        case TOKEN_BX: reg->bit = REGISTER_BX; reg->type = BITS16; break;
        case TOKEN_SP: reg->bit = REGISTER_SP; reg->type = BITS16; break;
        case TOKEN_BP: reg->bit = REGISTER_BP; reg->type = BITS16; break;
        case TOKEN_SI: reg->bit = REGISTER_SI; reg->type = BITS16; break;
        case TOKEN_DI: reg->bit = REGISTER_DI; reg->type = BITS16; break;

        // 8-bit registers
        case TOKEN_AL:  reg->bit = REGISTER_AL;  reg->type = BITS8; break;
        case TOKEN_CL:  reg->bit = REGISTER_CL;  reg->type = BITS8; break;
        case TOKEN_DL:  reg->bit = REGISTER_DL;  reg->type = BITS8; break;
        case TOKEN_BL:  reg->bit = REGISTER_BL;  reg->type = BITS8; break;
        case TOKEN_SPL: reg->bit = REGISTER_SPL; reg->type = BITS8; break;
        case TOKEN_BPL: reg->bit = REGISTER_BPL; reg->type = BITS8; break;
        case TOKEN_SIL: reg->bit = REGISTER_SIL; reg->type = BITS8; break;
        case TOKEN_DIL: reg->bit = REGISTER_DIL; reg->type = BITS8; break;

        default:
            // Unknown token, set to zero/invalid
            reg->bit = 0;
            reg->type = BITS64;

            printf("ERR: You provided an inexistent register in your parameters, so no assembly for you");
            break;
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
        case TOKEN_MOVE64:
        case TOKEN_MOVE32:
        case TOKEN_MOVE16:
        case TOKEN_MOVE8:        
            asm_register_t source = {0};
            asm_register_t target = {0};

            sprintasm_parseregister(strhash(buffs + 32), &source);
            sprintasm_parseregister(strhash(buffs + 64), &target);

            if(source.type != target.type && source.type != BITS64 && target.type != BITS64 && source.type != REX_EXTENDED && target.type != REX_EXTENDED) {
                printf("ERROR: The provided registers aren't of the same size! While this is technically correct, it isn't recommended for clarity!\n");
                return;
            }

            if((instructionHash == TOKEN_MOVE8 && source.type != BITS8) || (instructionHash == TOKEN_MOVE16 && source.type != BITS16) || (instructionHash == TOKEN_MOVE32 && source.type != BITS32)) {
                printf("ERROR: Instruction mismatch! Tried using a sized instruction for a differently sized register!");
                return;
            }

            if(instructionHash == TOKEN_MOVE64) {
                uint8_t rex = REX_PREFIX_BASE | (1 << REX_PREFIX_USE64BIT_OPERANDSZ);

                if(source.type == REX_EXTENDED) rex |= (1 << REX_PREFIX_REGFIELD_EXTENSION);
                if(target.type == REX_EXTENDED) rex |= (1 << REX_PREFIX_RMFIELD_EXTENSION);
            
                buff->buff[buff->sz] = rex;
                ++buff->sz;
            }

            buff->buff[buff->sz] = MOVE_REGTO_RM;
            ++buff->sz;

            asmlocation_t loc = {0};
            sprintasm_locregister(target.bit, &loc);

            int size = 0;
            sprintasm_modrmmake(source.bit, &loc, &size, buff);
            break;
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