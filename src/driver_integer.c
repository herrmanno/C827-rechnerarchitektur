#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include "integer.h"

Integer fib(uint32_t);

int main(int argc, char** argv) {
    uint32_t count = 10;
    if (argc > 1) {
        char* end;
        long tmp_count = strtoll(argv[1], &end, 10);
        if (errno != ERANGE && tmp_count != 0) {
            count = (uint32_t) tmp_count;
        } else {
            printf("Bad argument");
            return 1;
        }
    }
    for (uint32_t i = 1; i <= count; i++) {
        Integer f = fib(i);
        printf("%u: %s\n", i, integer_to_string(&f));
        free_integer(&f);
    }

    return 0;
}
