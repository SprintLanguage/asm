/**
 * ModRM tests
 */

#include <sprintasm/x86/modrm.h>
#include <sprintasm/x86/loc.h>
#include <sprintasm/x86/reg.h>


#include <stdio.h>

int main() {
    asmlocation_t* target = sprintasm_locaddr(454768455);
    asmlocation_t* reg = sprintasm_locregister(REGISTER_ESP);
    
    int size = 0;

    uint8_t* buff = sprintasm_modrmmake(REGISTER_EDX, reg, &size);
    
    for(int i = 0; i < size; ++i) {
        printf("0x%x ", buff[i]);
    }
}