#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <omp.h>

uint64_t fib(uint32_t);

int main(int argc, char** argv) {
    #pragma omp parallel for shared(argc,argv)
    for (uint32_t i = 1; i < argc; i++) {
        long n = strtoll(argv[i], 0, 10);
        if (errno != ERANGE && n != 0) {
            printf("%u: %llu\n", ((uint32_t) n), fib((uint32_t) n));
        } else {
            printf("Bad argument: %s", argv[i]);
        }
    }

    return 0;
}
