#pragma once

#include <stdint.h>

typedef struct sprint_bytebuff_t {
    uint8_t* buff;
    int sz;
    int allocated;
} sprint_bytebuff_t;