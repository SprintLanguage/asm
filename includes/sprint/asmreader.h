/**
 * Sprint's Assembly Reader.
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <sprintasm/buff.h>

sprint_bytebuff_t sprintasm_parseinstruction(char* line);
sprint_bytebuff_t sprintasm_parseinstructions(FILE* file);