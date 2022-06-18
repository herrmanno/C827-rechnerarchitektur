#include <stdint.h>
#include <stdio.h>
#include "integer.h"

Integer fib(uint32_t size) {
    Integer table[size];
    table[0] = new_integer(0);;
    table [1] = new_integer(1);;
    for (uint32_t i = 2; i < size; i++) {
        table[i] = add_integer(&table[i - 2], &table[i - 1]);
    }

    for (uint32_t i = 0; i < size - 1; i++) {
        free_integer(&table[i]);
    }
    return table[size - 1];
}

