/**
 * ModRM tests
 */

#include <sprintasm/x86/modrm.h>
#include <sprintasm/x86/loc.h>

#include <stdio.h>

int main() {
    asmlocation_t* target = sprintasm_locaddr(454768455);
    
    int size = 0;
    uint8_t* buff = sprintasm_modrmmake(REGISTER_EDX, target, &size);
    
    for(int i = 0; i < size; ++i) {
        printf("0x%x ", buff[i]);
    }
}