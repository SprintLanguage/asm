#include <sprintasm/x86/reg.h>

#include <stdint.h>

const uint8_t x86registers[] = {REGISTER_RAX, REGISTER_RCX, REGISTER_RDX, REGISTER_RBX, REGISTER_RSP, REGISTER_RBP, REGISTER_RSI, REGISTER_RDI};

regtype_t sprintasm_getregtype(uint8_t reg) {
    switch(reg) {
        case REGISTER_RAX:
        case REGISTER_RCX:
        case REGISTER_RDX:
        case REGISTER_RBX:
        case REGISTER_RSP:
        case REGISTER_RSI:
        case REGISTER_RDI:
            return BITS64;

        case REGISTER_R8:
        case REGISTER_R9:
        case REGISTER_R10:
        case REGISTER_R11:
        case REGISTER_R12:
        case REGISTER_R13:    
    }
}