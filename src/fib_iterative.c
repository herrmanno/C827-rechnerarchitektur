#include <stdint.h>
#include <stdio.h>

uint64_t fib(uint32_t size) {
    uint64_t a = 1;
    uint64_t b = 1;
    for (uint32_t i = 2; i < size; i++) {
        b = b + a;
        a = b - a;
    }
    return b;
}

