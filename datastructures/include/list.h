#pragma once
#include <stddef.h>


/* datastructure for linked list elements */
typedef struct ListElem_ {
    void*               data;
    struct ListElem_*   next;
} ListElem;

/* datastructure for linked lists */
typedef struct List_ {
    size_t      size;
    ListElem*   head;

    size_t      (*match)(const void* key1, const void* key2);
    void        (*destroy)(void* data);
} List;


void list_init(List* list, void (*destroy)(void* data));
void list_destroy(List* list);
int list_push(List* list, const void* data);
int list_pop(List* list, void** data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define is_head(list, elem) ((elem) == (list)->head ? 1 : 0)
