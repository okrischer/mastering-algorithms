#include <stdio.h>
#include <string.h>
#include "pointers.h"
#include "test.h"

int pointer_test() {
    int* iptr = alloc_single_pointer();
    if (get_pointer_value(iptr) != 42){
        printf("pointer_test alloc_single_pointer failed");
        return TEST_FAILURE;
    }

    if (strcmp(linked_list(), "1 2 3 ") != 0) {
        printf("pointer_test linked_list failed");
        return TEST_FAILURE;
    }

    int* array = array_reference();
    if (*(array + 4) != 4) {
        printf("pointer_test array_reference failed");
        return TEST_FAILURE;
    }

    int a = 3;
    int b = 4;
    swap(&a, &b);
    if (a != 4 || b != 3) {
        printf("pointer_test swap failed");
        return TEST_FAILURE;
    }

    char c = 'C';
    char d = 'D';
    swap_arbitrary(&c, &d, 1);
    if (c != 'D' || d != 'C') {
        printf("pointer_test swap_arbitrary failed");
        return TEST_FAILURE;
    }

    int x = 42;
    int y = 47;
    /* declare a function pointer */
    int (*match) (void* key1, void* key2);
    /* assign function pointer to a defined function */
    match = match_int;
    int match_result = match(&x, &y);
    if (match_result != 1) {
        printf("pointer_test function_pointer failed");
        return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
      printf("please provide a test target, e.g `pointer`\n");
      return TEST_FAILURE;
    }

    int test_success = 0;

    if (strcmp(argv[1], "pointer") == 0) {
        test_success = pointer_test();
    }
    return test_success;
}
