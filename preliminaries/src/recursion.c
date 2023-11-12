#include "recursion.h"

/* a naive recursive implementation of n! */
int factorial(int n) {
    if (n == 1) return 1;
    return n * factorial(n - 1);
}

/* tail-recursive implementation of n! */
int fact_tailrec(int n, int a) {
    if (n == 1) return a;
    return fact_tailrec(n - 1, n * a);
}

