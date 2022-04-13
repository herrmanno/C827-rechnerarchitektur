#include <stdint.h>
#include <stdio.h>

uint64_t fib(uint32_t size) {
    uint64_t table[size];
    table[0] = 0;
    table [1] = 1;
    for (uint32_t i = 2; i < size; i++) {
        table[i] = table[i - 2] + table[i - 1];
    }
    return table[size - 1];
}

