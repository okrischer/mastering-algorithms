#include <stdio.h>
#include <stdlib.h>
#include "test.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
      printf("please provide a test target (1 for pointer, 2 for recursion)\n");
      return TEST_FAILURE;
    }

    int test;

    switch (atoi(argv[1])) {
        case 1:     test = pointer_test();
                    break;
        case 2:     test = recursion_test();
                    break;
        default:    test = TEST_FAILURE;
                    printf("nothing to test\n");
    }

    return test;
}
