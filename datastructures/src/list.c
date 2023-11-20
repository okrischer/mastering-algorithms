#include <stdlib.h>
#include "list.h"


/* initializes an empty linked list, setting head and tail to NULL */
void list_init(List* list, void (*destroy)(void* data)) {
    list->size = 0;
    list->destroy = destroy;
    list->head = NULL;
    list->tail = NULL;
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

/* insert an element after a given element */
int list_ins_next(List* list, ListElem* after, const void* data) {
    ListElem* new_elem;

    // allocate memory for new element
    if ((new_elem = (ListElem*)malloc(sizeof(ListElem))) == NULL) {
        return -1;
    }

    new_elem->data = (void*)data;

    if (after == NULL) { // insert at the head of the list
        if (list_size(list) == 0) { // set tail for empty list
            list->tail = new_elem;
        }
        new_elem->next = list->head;
        list->head = new_elem;
    } else { // insert elsewhere
        if (after == list->tail) { // set tail if after is tail
            list->tail = new_elem;
        }
        new_elem-> next = after->next;
        after->next = new_elem;
    }

    list->size++;
    return 0;
}

/* remove the element from the head of the list and free memory */
int list_rem_next(List* list, ListElem* after, void** data) {
    ListElem* old_elem;

    // no removal from an empty list
    if (list_size(list) == 0) {
        return -1;
    }

    if (after == NULL) { // remove from the head of the list
        *data = list->head->data;
        old_elem = list->head;
        list->head = list->head->next;
        if (list_size(list) == 1) { // set tail to NULL if there is only one element
            list->tail = NULL;
        }

    } else { // remove elsewhere
        if (after == list->tail) { // cannot remove after tail
            return -1;
        }
        *data = after->next->data;
        old_elem = after->next;
        after->next = after->next->next;
        if (after->next == NULL) { // set tail
            list->tail = after;
        }
    }

    free(old_elem);
    list->size--;
    return 0;
}