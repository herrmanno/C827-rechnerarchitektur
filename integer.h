#include <stdint.h>
#include <stdlib.h>

typedef struct Integer {
    uint32_t length;
    uint8_t* data;
} Integer;

Integer new_integer(uint8_t);

void free_integer(Integer* i);

Integer add_integer(Integer *a, Integer *b);

char* integer_to_string(Integer*);
