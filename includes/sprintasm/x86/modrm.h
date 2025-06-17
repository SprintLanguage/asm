/**
 * Mod R/M bytes definitions for x86 bytecode
 */

#pragma once

#include <stdint.h>

// Mod
#define MODE_REGTOMEM 0x00
#define MODE_8BIT_DISPLACEMENT (1 << 6)
#define MODE_8BIT_DISPLACEMENT (1 << 7)
#define MODE_REGTOREG (1 << 7) & (1 << 6)




