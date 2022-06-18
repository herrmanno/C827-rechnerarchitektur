#include <stdint.h>

uint64_t fib_tailrec(uint64_t a, uint64_t b, uint32_t n);

uint64_t fib(uint32_t size) {
    return fib_tailrec(1, 1, size);
}

uint64_t fib_tailrec(uint64_t a, uint64_t b, uint32_t n) {
    if (n == 1) {
        return a;
    } else {
        return fib_tailrec(b, b + a, n - 1);
    }
}

