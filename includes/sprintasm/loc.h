#pragma once

#include <stdint.h>

typedef enum sprintasm_locationtype_t {
    REGISTER,
    DIRECT_ADDRESS,
    ADDRESS_REGISTER
} asmlocation_typet;

typedef struct sprintasm_locationt {
    asmlocation_typet type;
    uint8_t* bytes;
} asmlocation_t;

void sprintasm_locregister(uint8_t register, asmlocation_t* loc);
void sprintasm_locaddr(uint32_t addr, asmlocation_t* loc);
void sprintasm_locregaddr(uint8_t register, asmlocation_t* loc);