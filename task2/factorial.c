#include "unique.h"

static unsigned long long fact(unsigned n) {
    return (n < 2) ? 1ULL : n * fact(n - 1);
}

int main(void) {
    uniq_print_header("factorial");  // Prints the Proof Header

    unsigned n = 12; // Number for factorial
    printf("n=%u, n!=%llu\n", n, fact(n));

    return 0;
}

