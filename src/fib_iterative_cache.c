#include <stdint.h>
#include <stdlib.h>

uint64_t fib(uint32_t size) {
    uint64_t *table = (uint64_t*) malloc(size * sizeof(uint64_t));
    if (table == 0) {
        exit(1);
    }
    table[0] = 1;
    table [1] = 1;
    for (uint32_t i = 3; i <= size; i++) {
        table[i - 1] = table[i - 3] + table[i - 2];
    }
    uint64_t result = table[size - 1];
    free(table);
    return result;
}

