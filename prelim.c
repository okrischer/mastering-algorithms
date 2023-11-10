#include <stdio.h>
#include "pointers.h"

int main(void) {
    int* iptr = alloc_single_pointer();
    get_pointer_value(iptr);
    int* dangling = create_dangling_pointer();
    /* this will lead to a segmentation fault */
    // get_pointer_value(dangling);
    linked_list();
    return 0;
}