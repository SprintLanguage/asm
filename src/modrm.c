#include <sprintasm/loc.h>
#include <sprintasm/x86/modrm.h>
#include <sprintasm/x86/reg.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

void sprintasm_modrmmake(uint8_t reg, asmlocation_t* target, int* szptr, sprint_bytebuff_t buff) {
    uint8_t modrm = 0x00;

    *szptr = 1;

    if(target->type == REGISTER) {
        modrm |= MODE_REGTOREG;
        modrm |= MODRM_REGINRMFIELD(target->bytes[0]);
    }
    else {
        modrm |= MODE_REGTOMEM;

        if(target->bytes[0] == REGISTER_EBP) {
            printf("ERROR: Can't use the registry EBP whie using mode memory!\n");
            return;
        }

        modrm |= MODRM_REGINRMFIELD(target->bytes[0]);
    }

    if(target->type == DIRECT_ADDRESS) {
        modrm |= 0x05;
        *szptr = 5;
    }

    modrm |= MODRM_REGFIELD(reg);

    buff.buff[buff.sz] = modrm;
    ++buff.sz;

    if(target->type == DIRECT_ADDRESS) {
        for(int i = 0; i < 4; ++i) {
            buff.buff[buff.sz + i] = target->bytes[i];
        }

        buff.sz += 4;
    }
}