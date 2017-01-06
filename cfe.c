#include <math.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

void alloc_abort(size_t len) {
    printf("Error -- failed to allocate %zu bytes.\nAbort.\n", 
            len);
    abort();
}

/*
 * compute the continued fraction representation
 * of the square root of n, returning it as an
 * array and storing the length in *len.
 */
uint64_t* fraction_sqrt(uint64_t n, size_t *len) {
    const double a0 = sqrt(n);
    uint64_t a = floor(a0);

    size_t cap = 4;
    uint64_t *frac = malloc(sizeof(uint64_t) * cap);
    if (!frac) {
        alloc_abort(sizeof(uint64_t) * cap);
    }

    frac[0] = a;
    *len = 1;
    
    if (a0 * a0 == (double) n) {
        /* n is a perfect square */
        return frac;
    }

    uint64_t m = 0;
    uint64_t d = 1;

    const uint64_t end = a * 2;
    while (a != end) {
        m = d * a - m;
        d = (n - m * m) / d;
        a = floor((a0 + (double) m) / (double) d);

        frac[(*len)++] = a;
        if (*len >= cap) {
            cap *= 1.5;
            frac = realloc(frac, sizeof(uint64_t) * cap);
            if (!frac) {
                alloc_abort(sizeof(uint64_t) * cap);
            }
        }
    }

    return frac;
}

/*
 * print a continued fraction to stdout
 */
void print_fraction(const uint64_t *frac, size_t len) {
    printf("[%zu", frac[0]); 
    if (len != 1) {
        printf("; ");
    }

    for (size_t i = 1; i < len; ++i) {
        if (i != 1) {
            printf(", ");
        }
        printf("%zu", frac[i]);
    }

    printf("]\n");
}

int main(int argc, char **argv) {

    for (int i = 1; i < argc; ++i) {
        size_t len = 0;
        uint64_t *frac = fraction_sqrt(strtoull(argv[i], NULL, 10), &len);
        print_fraction(frac, len);
        free(frac);
    }

    return 0;
}
