/**
 * Mod R/M bytes definitions for x86 bytecode
 */

#pragma once

#include <stdint.h>

// Mod
#define MODE_REGTOMEM 0x00 // Register to memory mode, R/M represents a register indirectly
#define MODE_8BIT_DISPLACEMENT 0x40 // Register to memory mode with 8bit replacemenet, R/M represents
#define MODE_32BIT_DISPLACEMENT 0x80
#define MODE_REGTOREG 0xC0

// Registers (for reg field)

// 8 bit registers
#define REGISTER_AL 0x00
#define REGISTER_CL 0x08
#define REGISTER_DL 0x10
#define REGISTER_AH 0x20
#define REGISTER_CH 0x28
#define REGISTER_DH 0x30
#define REGISTER_BH 0x38

// 16 bit registers
#define REGISTER_AX 0x00
#define REGISTER_CX 0x08
#define REGISTER_DX 0x10
#define REGISTER_SP 0x20
#define REGISTER_ESP 0x20
#define REGISTER_BP 0x28
#define REGISTER_SI 0x30
#define REGISTER_DI 0x38

// 32 bit registers
#define REGISTER_EAX 0x00
#define REGISTER_ECX 0x08
#define REGISTER_EDX 0x10
#define REGISTER_ESP 0x20
#define REGISTER_EBP 0x28
#define REGISTER_ESI 0x30
#define REGISTER_EDI 0x38

/**
 * Allows to convert an register for the "reg" field to a register for the r/m field when the "mode" == MODE_REGTOREG
 */
#define REGISTER_REGFIELD_TO_RM(x) x << 3