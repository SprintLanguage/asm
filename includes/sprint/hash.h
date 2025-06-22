#pragma once

/**
 * Creates a hash of the given string.
 */
unsigned int strhash(char* string);

/**
 * Appends the given character to the given hash pointer.
 */
void strhash_append(unsigned int* hashptr, char c);