#include "recursion.h"
#include <stddef.h>

/* naive recursive implementation of n! */
size_t factorial(size_t n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

/* tail-recursive implementation of n! */
size_t fact_tailrec(size_t n, size_t a) {
    if (n == 1) return a;
    return fact_tailrec(n - 1, n * a);
}

/* naive recursive implementation of fibonacci numbers */
size_t fibonacci(size_t n) {
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

/* private helper function for fib_tailrec */
size_t fib_helper(size_t n, size_t a, size_t b) {
    if (n < 2) return b;
    return fib_helper(n-1, b, a+b);
}
/* naive recursive implementation of fibonacci numbers */
size_t fib_tailrec(size_t n) {
    return fib_helper(n, 0, 1);
}
