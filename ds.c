#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "test.h"


int main(int argc, char* argv[]) {
    if (argc < 2) {
      printf("please provide a test target\n");
      return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}
