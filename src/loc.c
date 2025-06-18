#include <sprintasm/loc.h>
#include <stdlib.h>

void sprintasm_locregister(uint8_t reg, asmlocation_t* loc) {
    loc->type = REGISTER;
    loc->bytes = malloc(1);
    loc->bytes[0] = reg;
}

void sprintasm_locaddr(uint32_t addr, asmlocation_t* loc) {
    uint8_t* b = (uint8_t*) &addr;

    loc->type = DIRECT_ADDRESS;
    loc->bytes = malloc(4);

    loc->bytes[0] = b[0];
    loc->bytes[1] = b[1];
    loc->bytes[2] = b[2];
    loc->bytes[3] = b[3];
}

void sprintasm_locregaddr(uint8_t reg, asmlocation_t* loc) {
    loc->type = ADDRESS_REGISTER;
    loc->bytes = malloc(1);
    loc->bytes[0] = reg;
}