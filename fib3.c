#include <stdint.h>
#include <stdio.h>

#define LOOP (t = a + b, a = b, b = t)
#define LOOP2 (LOOP, LOOP)
#define LOOP4 (LOOP2, LOOP2)

uint64_t fib(uint32_t n) {
    uint64_t t = 0;
    uint64_t a = 0;
    uint64_t b = 1;

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

