/**
 * x86 instructions
 */

#define MOVE_REGTO_RM 0x89
#define MOVE_RMTO_REG 0x8B

#define MOVE_IMMEDIATETO_REG 0xB8 // Need to add register code to it
#define MOVE_IMMEDIATETO_RM 0x

#define MOVE_EAXTO_ADDR 0xA1
#define MOVE_ADDRTO_EAX 0xA3

#define PREFIX_16BITS 0x66
#define PREFIX_64BITS 0x48