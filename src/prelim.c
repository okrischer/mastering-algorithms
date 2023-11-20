#include <stdio.h>
#include <stdlib.h>
#include "recursion.h"
#include "test.h"
#include "bm.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
      printf("please provide a test target\n");
      return TEST_FAILURE;
    }

    int test;
    size_t (*fptr1)(size_t) = &fib_imper;
    size_t (*fptr2)(size_t) = &fib_tailrec;

    switch (atoi(argv[1])) {
        case 1:     test = pointer_test();
                    break;
        case 2:     test = recursion_test();
                    break;
        case 3:     test = bm(fptr1, fptr2, 100);
                    break;
        default:    test = TEST_FAILURE;
                    printf("nothing to test\n");
    }

    return test;
}
