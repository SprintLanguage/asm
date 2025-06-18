/**
 * x86 registers
 */

#pragma once

#include <stdint.h>

// 64-bit register variants (x86-64 processors only)
#define REGISTER_RAX 0x00
#define REGISTER_RCX 0x20
#define REGISTER_RDX 0x40
#define REGISTER_RBX 0x60
#define REGISTER_RSP 0x80
#define REGISTER_RBP 0xA0
#define REGISTER_RSI 0xC0
#define REGISTER_RDI 0xE0

// 32-bit register variants (everywhere)
#define REGISTER_EAX 0x00
#define REGISTER_ECX 0x20
#define REGISTER_EDX 0x40
#define REGISTER_EBX 0x60
#define REGISTER_ESP 0x80
#define REGISTER_EBP 0xA0
#define REGISTER_ESI 0xC0
#define REGISTER_EDI 0xE0

// 16-bit register variants (everywhere)
#define REGISTER_AX 0x00
#define REGISTER_CX 0x20
#define REGISTER_DX 0x40
#define REGISTER_BX 0x60
#define REGISTER_SP 0x80
#define REGISTER_BP 0xA0
#define REGISTER_SI 0xC0
#define REGISTER_DI 0xE0


// 8-bit register variants (everywhere)
#define REGISTER_AL 0x00
#define REGISTER_CL 0x20
#define REGISTER_DL 0x40
#define REGISTER_BL 0x60
#define REGISTER_SPL 0x80
#define REGISTER_BPL 0xA0
#define REGISTER_SIL 0xC0
#define REGISTER_DIL 0xE0