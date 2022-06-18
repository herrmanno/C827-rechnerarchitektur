#include <stdint.h>
#include <stdlib.h>

uint64_t fib_cache(uint32_t n, uint64_t cache[]);

uint64_t fib(uint32_t n) {
    if (n <= 2) {
        return 1;
    } else {
        uint64_t *cache = (uint64_t*) calloc(n, sizeof(uint64_t));
        if (cache == 0) {
            exit(1);
        }
        cache[0] = cache[1] = 1;
        uint64_t result = fib_cache(n - 1, cache);
        free(cache);
        return result;
    }
}

uint64_t fib_cache(uint32_t n, uint64_t cache[]) {
    if (cache[n] == 0) {
        cache[n] = fib_cache(n - 2, cache) + fib_cache(n - 1, cache);
    }
    return cache[n];
}
