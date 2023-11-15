#include <stddef.h>
#include <stdio.h>
#include "frames.h"
#include "test.h"
#include "list.h"


int manage_frames() {
    // create list of frames
    List frames;
    list_init(&frames, NULL);
    int frame1 = 1;
    int frame2 = 2;
    int frame3 = 3;
    list_push(&frames, &frame3);
    list_push(&frames, &frame2);
    list_push(&frames, &frame1);

    // test size of frames
    size_t ls = list_size(&frames);
    if (ls != 3) {
        printf("list size should be %d, but it is %zu\n", 3, ls);
        return TEST_FAILURE;
    }

    // test list_pop
    int* popped;
    list_pop(&frames, (void*)&popped);
    if (*popped != 1) {
        printf("popped element should be %d, but it is %d\n", 1, *popped);
        return TEST_FAILURE;
    }
    ls = list_size(&frames);
    if (ls != 2) {
        printf("list size should be %d, but it is %zu\n", 2, ls);
        return TEST_FAILURE;
    }

    // test allocating a frame
    int frame = alloc_frame(&frames);
    if (frame != 2) {
        printf("allocated frame should be %d, but it is %d\n", 2, frame);
        return TEST_FAILURE;
    }
    ls = list_size(&frames);
    if (ls != 1) {
        printf("list size should be %d, but it is %zu\n", 1, ls);
        return TEST_FAILURE;
    }

    // test freeing a frame
    int success = free_frame(&frames, 2);
    if (success == 0) {
        ls = list_size(&frames);
        if (ls != 2) {
            printf("list size should be %d, but it is %zu\n", 2, ls);
            return TEST_FAILURE;
        }
    }

    // test no removal from empty list
    list_pop(&frames, (void*)&popped);
    list_pop(&frames, (void*)&popped);
    ls = list_size(&frames);
    if (ls != 0) {
        printf("list size should be %d, but it is %zu\n", 0, ls);
        return TEST_FAILURE;
    }
    success = list_pop(&frames, (void*)&popped);
    if (success != -1) {
        printf("popping from an empty list should yield error code");
        return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}