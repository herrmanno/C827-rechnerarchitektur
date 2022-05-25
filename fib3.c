#include <stdint.h>
#include <stdio.h>

#define LOOP (b = a + b, a = b - a)
#define LOOP2 (LOOP, LOOP)
#define LOOP4 (LOOP2, LOOP2)

uint64_t fib(uint32_t n) {
    register uint64_t a = 0;
    register uint64_t b = 1;

    start:
    if (n <= 1) {
        return a;
    } else if (n > 4) {
        LOOP4;
        n -= 4;
        goto start;
    } else {
        LOOP;
        n -= 1;
        goto start;
    }
}

