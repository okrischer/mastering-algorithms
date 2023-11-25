#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "test.h"
#include "events.h"

int receive_event(Queue* events, const Event* event) {
    Event* new_event;

    // allocate space for new event
    if ((new_event = (Event*)malloc(sizeof(Event))) == NULL) {
        return -1;
    }

    // make a copy of the event and enqueue it
    memcpy(new_event, event, sizeof(Event));
    if (queue_enqueue(events, new_event) != 0) {
        return -1;
    }

    return 0;
}

int process_event(Queue* events, int (*dispatch)(Event* event)) {
    Event* event;

    if (queue_size(events) == 0) { // no events to dispatch
        return -1;
    } else {
        if (queue_dequeue(events, (void*)&event) != 0) {
            return -1; // event could not be retrieved
        } else {
            dispatch(event);
            free(event);
        }
    }

    return 0;
}

int dispatcher(Event* event) {
    printf("dispatched event %d\n", *event);
    return 0;
}

int events() {
    Queue events;
    Event event1 = 1;
    Event event2 = 2;
    queue_init(&events, NULL);

    int success = receive_event(&events, &event1);
    if (success != 0) {
        printf("couldn't enqueue event\n");
        return TEST_FAILURE;
    }

    size_t size = queue_size(&events);
    if (size != 1) {
        printf("size of events should be %d but it is %zu\n", 1, size);
        return TEST_FAILURE;
    }

    success = receive_event(&events, &event2);

    int (*dispatch)(Event* event); // function pointer
    dispatch = dispatcher;
    success = process_event(&events, dispatch);
    if (success != 0) {
        printf("could't process event\n");
        return TEST_FAILURE;
    }

    size = queue_size(&events);
    if (size != 1) {
        printf("size of events should be %d but it is %zu\n", 1, size);
        return TEST_FAILURE;
    }

    success = process_event(&events, dispatch);
    success = process_event(&events, dispatch);
    if (success != -1) {
        printf("processing event from empty queue should not be possible\n");
        return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}