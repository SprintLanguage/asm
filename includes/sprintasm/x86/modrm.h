/**
 * Mod R/M bytes definitions for x86 bytecode
 */

#pragma once

#include <sprintasm/x86/loc.h>

#include <stdint.h>

// Mod
#define MODE_REGTOMEM 0x00 // Register to memory mode, R/M represents a register containing a memory address, doesn't apply any displacement
#define MODE_8BIT_DISPLACEMENT 0x40 // Register to memory mode with 8bit displacement, R/M represents the register containing the address, applies a 1 byte displacement
#define MODE_32BIT_DISPLACEMENT 0x80 // Register to memory mode with 32bit displacement, R/M represents the register containing the address, applies a 4 bytes displacement
#define MODE_REGTOREG 0xC0 // Register to register mode, R/M represents the target register

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
#define REGISTER_EBX 0x20 // Special for modes with offsets
#define REGISTER_ESP 0x20
#define REGISTER_EBP 0x28
#define REGISTER_ESI 0x30
#define REGISTER_EDI 0x38

#define MODRM_REGFIELD(reg) reg >> 2
#define MODRM_REGINRMFIELD(reg) reg >> 5

uint8_t* sprintasm_modrmmake(uint8_t register, asmlocation_t* target, int* szptr);