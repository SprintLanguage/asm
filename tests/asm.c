#include <sprint/asmreader.h>
#include <sprint/pe/pe.h>

#include <benchmark/bench.h>
#include <stdlib.h>

int main() {
    FILE* f = fopen("examples/test.sasm", "r");

    sprint_bytebuff_t* buff = sprintasm_parseinstructions(f);
    buff->buff[buff->sz] = 0xC3; // ret / exit code
    ++buff->sz;
    
    FILE* out = fopen("out.exe", "w");

    for(int i = 0; i < buff->sz; ++i) {
        printf("0x%x ", buff->buff[i]);
    }

    sprint_writepeexecutable(out, buff);
}