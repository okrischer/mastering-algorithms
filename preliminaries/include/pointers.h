#pragma once

#include <stddef.h>

typedef struct Element_ {
    int data;
    struct Element_* next;
} Element;

int get_pointer_value(int* iptr);
int* alloc_single_pointer();
int* create_dangling_pointer();

char* linked_list();
int* array_reference();

void swap(int* x, int* y);
void swap_arbitrary(void* x, void* y, size_t size);

int match_int(void* x, void* y);