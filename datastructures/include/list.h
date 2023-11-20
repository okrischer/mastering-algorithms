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
    ListElem*   tail;

    size_t      (*match)(const void* key1, const void* key2);
    void        (*destroy)(void* data);
} List;


void list_init(List* list, void (*destroy)(void* data));
void list_destroy(List* list);
int list_ins_next(List* list, ListElem* after, const void* data);
int list_rem_next(List* list, ListElem* after, void** data);

#define list_size(list) ((list)->size)
#define list_head(list) ((list)->head)
#define list_tail(list) ((list)->tail)
#define is_head(list, elem) ((elem) == (list)->head ? 1 : 0)
#define is_tail(elem) ((elem)->next == NULL ? 1 : 0)
