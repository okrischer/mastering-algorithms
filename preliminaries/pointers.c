#include <stdio.h>
#include <stdlib.h>
#include "pointers.h"


void get_pointer_value(int* iptr) {
    int* jptr = iptr; // jptr points to the same object as iptr
    printf("iptr points to %d, jptr points to %d\n", *iptr, *jptr);
    *jptr = 42; // changing a dangling pointers value leads to a segmentation fault
    printf("iptr points to %d, jptr points to %d\n", *iptr, *jptr);
}

int* alloc_single_pointer() {
    int* iptr = (int*)malloc(sizeof(int));
    *iptr = 10;
    return iptr;
}

int* create_dangling_pointer() {
    int a = 10;
    int* iptr = &a;
    return iptr;
}

void linked_list() {
    Element tail = {3, NULL};
    Element elem = {2, &tail};
    Element head = {1, &elem};
    Element* current = &head;

    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}