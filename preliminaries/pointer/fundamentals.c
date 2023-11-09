#include <stdio.h>
#include "fundamentals.h"

int main(void) {
    get_pointer_value();
    return 0;
}

void get_pointer_value() {
    int a = 10;
    int* iptr = &a;
    int* jptr = iptr;
    printf("iptr points to %d, jptr points to %d\n", *iptr, *jptr);
    *jptr = 42;
    printf("iptr points to %d, jptr points to %d\n", *iptr, *jptr);
}