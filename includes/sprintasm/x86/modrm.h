/**
 * Mod R/M bytes definitions for x86 bytecode
 */

#pragma once

#include <sprintasm/loc.h>
#include <sprintasm/buff.h>

#include <stdint.h>

// Mod
#define MODE_REGTOMEM 0x00 // Register to memory mode, R/M represents a register containing a memory address, doesn't apply any displacement
#define MODE_8BIT_DISPLACEMENT 0x40 // Register to memory mode with 8bit displacement, R/M represents the register containing the address, applies a 1 byte displacement
#define MODE_32BIT_DISPLACEMENT 0x80 // Register to memory mode with 32bit displacement, R/M represents the register containing the address, applies a 4 bytes displacement
#define MODE_REGTOREG 0xC0 // Register to register mode, R/M represents the target register

#define MODRM_REGFIELD(reg) reg >> 2
#define MODRM_REGINRMFIELD(reg) reg >> 5

void sprintasm_modrmmake(uint8_t register, asmlocation_t* target, int* szptr, sprint_bytebuff_t buff);