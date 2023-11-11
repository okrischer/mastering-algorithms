#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pointers.h"


int get_pointer_value(int* iptr) {
    int* jptr = iptr;
    *jptr = 42;
    return *iptr;
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

char* linked_list() {
    Element tail = {3, NULL};
    Element elem = {2, &tail};
    Element head = {1, &elem};
    Element* current = &head;

    static char e[3];
    static char list[6];
    while (current != NULL) {
        sprintf(e, "%d ", current->data);
        current = current->next;
        strcat(list, e);
    }
    return list;
}

int* array_reference() {
    static int a[5];
    int* iptr = a;
    for (int i = 0; i < 5; i++) {
        *iptr = i;
        iptr++;
    }
    return a;
}

void swap(int* x, int* y) {
    int tmp = *x;
    *x = *y;
    *y = tmp;
}