#include <stdio.h>
#include <stdlib.h>
#include "test.h"
#include "hanoi.h"
#include "events.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
      printf("please provide a test target\n");
      return TEST_FAILURE;
    }

    int test;

    switch (atoi(argv[1])) {
        case 1:     test = hanoi();
                    break;
        case 2:     test = events();
                    break;
        default:    test = TEST_FAILURE;
                    printf("nothing to test\n");
    }

    return test;
}