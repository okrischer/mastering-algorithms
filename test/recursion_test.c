#include <stdio.h>
#include "test.h"
#include "recursion.h"


/* testing recursion from section preliminaries */
int recursion_test() {

    int f_10 = 3628800;
    int n = 10;

    int f = factorial(n);
    if (f != f_10) {
        printf("factorial of %d should be %d, but it is %d\n", n, f_10, f);
        return TEST_FAILURE;
    }

    int ft = fact_tailrec(n, 1);
    if (ft != f_10) {
        printf("fact_tailrec of %d should be %d, but it is %d\n", n, f_10, ft);
        return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}
