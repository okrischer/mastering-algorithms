#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pointers.h"


/* get and reassign the value of a pointer */
int get_pointer_value(int* iptr) {
    int* jptr = iptr;
    *jptr = 42;
    return *iptr;
}

/* allocate memory for a single pointer */
int* alloc_single_pointer() {
    int* iptr = (int*)malloc(sizeof(int));
    *iptr = 10;
    return iptr;
}

/* create and return a dangling pointer */
int* create_dangling_pointer() {
    int a = 10;
    int* iptr = &a;
    return iptr;
}

/* create a simple linked list and return a string representation */
char* linked_list() {
    Element tail = {3, NULL};
    Element elem = {2, &tail};
    Element head = {1, &elem};
    Element* current = &head;

    char e[3];
    static char list[6];
    while (current != NULL) {
        sprintf(e, "%d ", current->data);
        strcat(list, e);
        current = current->next;
    }
    return list;
}

/* create, initialize and return a static array */
int* array_reference() {
    static int a[5];
    int* iptr = a;
    for (int i = 0; i < 5; i++) {
        *iptr = i;
        iptr++;
    }
    return a;
}

/* swap integer values by reference */
void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

/* swap values of arbitrary type */
void swap_arbitrary(void* x, void* y, size_t size) {
    void* tmp = malloc(size);
    memcpy(tmp, x, size);
    memcpy(x, y, size);
    memcpy(y, tmp, size);
    free(tmp);
}

/* simple integer matching function for testing function pointers */
int match_int(void* x, void* y) {
    if (*(int*)x == *(int*)y) {
        return 0;
    } else {
        return 1;
    }
}