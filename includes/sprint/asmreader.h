/**
 * Sprint's Assembly Reader.
 */

#pragma once

#include <stdint.h>
#include <stdio.h>

uint8_t* sprintasm_parseinstruction(char* line);
uint8_t* sprintasm_parseinstructions(FILE* file);