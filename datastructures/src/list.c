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
        if (list_rem_next(list, NULL, (void**)&data) == 0
                && list->destroy != NULL) {
            list->destroy(data);
        }
    }
}

/* insert an element into a list just after a specified element */
int list_ins_next(List* list, ListElem* after, const void* data) {
    ListElem* new_elem;

    // allocate memory for new element
    if ((new_elem = (ListElem*)malloc(sizeof(ListElem))) == NULL) {
        return -1;
    }

    new_elem->data = (void*)data;

    // find inserting position
    if (after == NULL) { // insert at the head of the list
        new_elem->next = list->head;
        list->head = new_elem;
    } else { // insert after specified element
        new_elem->next = after->next;
        after->next = new_elem;
    }

    list->size += 1;
    return 0;
}

/* insert an element at the head of the list */
int list_push(List *list, const void *data) {
    return list_ins_next(list, NULL, data);
}

/* remove an element just after a specified element and free memory */
int list_rem_next(List* list, ListElem* after, void** data) {
    ListElem* old_elem;

    // no removal from an empty list
    if (list_size(list) == 0) {
        return -1;
    }

    // find removal position
    if (after == NULL) { // remove from the head of the list
        *data = list->head->data;
        old_elem = list->head;
        list->head = list->head->next;
    } else { // remove after specified element
        if (after->next == NULL) { // do not remove if after is the tail
            return -1;
        }
        *data = after->next->data;
        old_elem = after->next;
        after->next = after->next->next;
    }

    free(old_elem);
    list->size -= 1;
    return 0;
}

/* remove an element from the head of the list */
int list_pop(List *list, void **data) {
    return list_rem_next(list, NULL, data);
}