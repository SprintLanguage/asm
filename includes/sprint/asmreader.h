/**
 * Sprint's Assembly Reader.
 */

#pragma once

#include <stdint.h>
#include <stdio.h>

#include <sprintasm/buff.h>
#include <sprintasm/x86/reg.h>

#define TOKEN_MOVE64 238836422
#define TOKEN_MOVE32 238836321
#define TOKEN_MOVE16 238836259
#define TOKEN_MOVE8 267538516

#define TOKEN_RAX 193504464
#define TOKEN_RCX 193504530
#define TOKEN_RDX 193504563
#define TOKEN_RBX 193504497
#define TOKEN_RSP 193505050
#define TOKEN_RBP 193504489
#define TOKEN_RSI 193505043
#define TOKEN_RDI 193504548

#define TOKEN_R8 5863727
#define TOKEN_R9 5863728
#define TOKEN_R10 193502808
#define TOKEN_R11 193502809
#define TOKEN_R12 193502810
#define TOKEN_R13 193502811
#define TOKEN_R14 193502812
#define TOKEN_R15 193502813

#define TOKEN_EAX 193490307
#define TOKEN_ECX 193490373
#define TOKEN_EDX 193490406
#define TOKEN_EBX 193490340
#define TOKEN_ESP 193490893
#define TOKEN_EBP 193490332
#define TOKEN_ESI 193490886
#define TOKEN_EDI 193490391

#define TOKEN_AX 5863230
#define TOKEN_CX 5863296
#define TOKEN_DX 5863329
#define TOKEN_BX 5863263
#define TOKEN_SP 5863816
#define TOKEN_BP 5863255
#define TOKEN_SI 5863809
#define TOKEN_DI 5863314

#define TOKEN_AL 5863218
#define TOKEN_CL 5863284
#define TOKEN_DL 5863317
#define TOKEN_BL 5863251
#define TOKEN_SPL 193506036
#define TOKEN_BPL 193487523
#define TOKEN_SIL 193505805
#define TOKEN_DIL 193489470

void sprintasm_parseregister(unsigned int token, asm_register_t* reg);

void sprintasm_parseinstruction(char* line, sprint_bytebuff_t* buff);
sprint_bytebuff_t* sprintasm_parseinstructions(FILE* file);