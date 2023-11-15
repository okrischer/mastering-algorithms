#include <stdlib.h>
#include "list.h"


/* initializes an empty linked list, setting head and tail to NULL */
void list_init(List* list, void (*destroy)(void* data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
}

/* delete a list by removing all elements and freeing allocated memory */
void list_destroy(List* list) {
    void* data;
    while (list_size(list) > 0) {
        if (list_pop(list, (void**)&data) == 0
                && list->destroy != NULL) {
            list->destroy(data);
        }
    }
}

/* insert an element at the head of the list */
int list_push(List* list, const void* data) {
    ListElem* new_elem;

    // allocate memory for new element
    if ((new_elem = (ListElem*)malloc(sizeof(ListElem))) == NULL) {
        return -1;
    }

    new_elem->data = (void*)data;
    new_elem->next = list->head;
    list->head = new_elem;
    list->size += 1;
    return 0;
}

/* remove the element from the head of the list and free memory */
int list_pop(List* list, void** data) {
    ListElem* old_elem;

    // no removal from an empty list
    if (list_size(list) == 0) {
        return -1;
    }

    *data = list->head->data;
    old_elem = list->head;
    list->head = list->head->next;
    free(old_elem);
    list->size -= 1;
    return 0;
}