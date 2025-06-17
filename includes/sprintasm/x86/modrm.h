/**
 * Mod R/M bytes definitions for x86 bytecode
 */

#pragma once

#include <stdint.h>

// Mod
#define MODE_REGTOMEM 0x00 // Register to memory mode, R/M represents a register indirectly
#define MODE_8BIT_DISPLACEMENT (1 << 6) // Register to memory mode with 8bit replacemenet, R/M represents
#define MODE_8BIT_DISPLACEMENT (1 << 7)
#define MODE_REGTOREG (1 << 7) & (1 << 6)

// Registers (for reg field)

// 000
#define REGISTER_AL 0x00
#define REGISTER_AX REGISTER_AL
#define REGISTER_EAX REGISTER_AX

// 001
#define REGISTER_CL (1 << 3)
#define REGISTER_CX REGISTER_CL
#define REGISTER_ECX REGISTER_CX

// 010
#define REGISTER_DL (1 << 4)
#define REGISTER_DX REGISTER_DL
#define REGISTER_EDX REGISTER_DX

// 100
#define REGISTER_AH (1 << 5)
#define REGISTER_SP REGISTER_AH
#define REGISTER_ESP REGISTER_SP

// 101
#define REGISTER_CH ((1 << 5) | (1 << 3))
#define REGISTER_BP REGISTER_CH
#define REGISTER_EBP REGISTER_BP

// 110
#define REGISTER_DH ((1 << 5) | (1 << 4))
#define REGISTER_SI REGISTER_DH
#define REGISTER_ESI REGISTER_SI

// 111
#define REGISTER_BH ((1 << 5) | (1 << 4) | (1 << 3))
#define REGISTER_DI REGISTER_BH
#define REGISTER_EDI REGISTER_DI

/**
 * Allows to convert an register for the "reg" field to a register for the r/m field when the "mode" == MODE_REGTOREG
 */
#define REGISTER_FIELDRM(x) x >> 3