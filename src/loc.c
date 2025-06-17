#include <sprintasm/x86/loc.h>

#include <stdlib.h>

asmlocation_t* sprintasm_locregister(uint8_t reg) {
    asmlocation_t* loc = malloc(sizeof(asmlocation_t));
    
    loc->type = REGISTER;
    loc->bytes = (uint8_t){reg};

    return loc;
}

asmlocation_t* sprintasm_locaddr(uint32_t addr) {
    asmlocation_t* loc = malloc(sizeof(asmlocation_t));
    uint8_t* b = (uint8_t*) &addr;

    loc->type = REGISTER;
    loc->bytes = (uint8_t*){b[0], b[0], b[2], b[3]};

    return loc;
}

asmlocation_t* sprintasm_locregaddr(uint8_t reg) {
    asmlocation_t* loc = malloc(sizeof(asmlocation_t));
    
    loc->type = ADDRESS_REGISTER;
    loc->bytes = (uint8_t*) {reg};

    return loc;
}