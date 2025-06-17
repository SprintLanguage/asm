#include <sprintasm/x86/loc.h>
#include <sprintasm/x86/modrm.h>

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

uint8_t* sprintasm_modrmmake(uint8_t reg, asmlocation_t* target, int* szptr) {
    uint8_t modrm = 0x00;

    *szptr = 1;

    if(target->type == REGISTER) {
        modrm |= MODE_REGTOREG;
        modrm |= REGISTER_REGFIELD_TO_RM(target->bytes[0]);
    }
    else {
        modrm |= MODE_REGTOMEM;

        if(target->bytes[0] == REGISTER_EBP) {
            printf("ERROR: Can't use the registry EBP whie using mode memory!\n");
            return NULL;
        }

        modrm |= REGISTER_REGFIELD_TO_RM(target->bytes[0]);
    }

    if(target->type == DIRECT_ADDRESS) {
        modrm |= 0x05;
        *szptr = 5;
    }

    modrm |= reg;

    uint8_t* buff = malloc(*szptr);
    buff[0] = modrm;

    if(target->type == DIRECT_ADDRESS) {
        for(int i = 1; i < 5; ++i) {
            buff[i] = target->bytes[i];
        }
    }
    
    return buff;
}