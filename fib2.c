#include <stdint.h>
#include <stdio.h>

uint64_t fib(uint32_t size) {
    if (size == 1) return 0;
    if (size == 2) return 1;

    uint64_t t = 0, a = 0, b = 1;
    for (uint32_t i = 0; i < size - 2; i++) {
        t = a + b;
        a = b;
        b = t;
    }
    return t;
}

