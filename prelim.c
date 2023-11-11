#include <stdio.h>
#include <string.h>
#include "pointers.h"

int pointer_test() {
    /* allocate pointer and get pointer value */
    int* iptr = alloc_single_pointer();
    if (get_pointer_value(iptr) != 42){
        printf("pointer_test alloc_single_pointer failed");
        return 1;
    }

    /* create a linked list */
    if (strcmp(linked_list(), "1 2 3 ") != 0) {
        printf("pointer_test linked_list failed");
        return 1;
    }

    /* create a reference to an array */
    int* array = array_reference();
    if (*(array + 4) != 4) {
        printf("pointer_test array_reference failed");
        return -1;
    }

    /* swapping two integer values */
    int a = 3;
    int b = 4;
    swap(&a, &b);
    if (a != 4 || b != 3) {
        printf("pointer_test swap failed");
        return 1;
    }

    return 0;
}

int main(int argc, char* argv[]) {
    if (argc < 2) return 1;
    int test_success = 0;
    if (strcmp(argv[1], "pointer") == 0) {
        test_success = pointer_test();
    }
    return test_success;
}