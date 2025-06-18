/**
 * Sprint's Assembly Reader.
 */

#pragma once

#include <stdint.h>
#include <stdio.h>
#include <sprintasm/buff.h>

void sprintasm_parseinstruction(char* line, sprint_bytebuff_t buff);
sprint_bytebuff_t sprintasm_parseinstructions(FILE* file);