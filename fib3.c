#include <stdint.h>
#include <stdio.h>

static uint64_t fib_rec(uint32_t n, uint64_t a, uint64_t b) {
    start:
    if (n == 1) {
        return a;
    } else {
        n -= 1;
        uint64_t t = a + b;
        a = b;
        b = t;
        goto start;
    }
}

uint64_t fib(uint32_t size) {
    return fib_rec(size, 0, 1);
}

