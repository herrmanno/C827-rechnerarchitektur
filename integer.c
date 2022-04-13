#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "integer.h"

Integer new_integer(uint8_t n) {
    uint8_t* data = malloc(sizeof(uint8_t));
    data[0] = n;
    Integer i = { 1, data };
    return i;
}

void free_integer(Integer* i) {
    free(i->data);
}

uint8_t get(Integer* i, uint32_t n) {
    if (n < i->length) {
        return i->data[n];
    } else {
        return 0;
    }
}

Integer add_integer(Integer *a, Integer *b) {
    uint32_t length = 0;
    uint32_t max_length = a->length > b->length ? a->length : b->length;
    uint8_t* data = malloc((sizeof(uint8_t)) * (max_length + 1));

    uint8_t remainder = 0;
    for (uint32_t i = 0; i < max_length; i++) {
        uint8_t sum = get(a,i) + get(b,i) + remainder;
        data[i] = sum % 10;
        remainder = sum > 9 ? 1 : 0;
    }
    if (remainder) {
        data[max_length] = 1;
        length = max_length + 1;
    } else {
        length = max_length;
    }

    Integer i = { length, data };
    return i;
}


char* integer_to_string(Integer* i) {
    uint32_t size = (sizeof(char)) * (i->length + 1);
    char* str = malloc(size); 
    str[size - 1] = 0;
    for (uint32_t j = 0; j < i->length; j++) {
        str[size - 2 - j] = i->data[j] + 48;
    }

    return str;
}
