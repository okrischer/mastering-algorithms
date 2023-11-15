#include <stdlib.h>
#include "frames.h"
#include "list.h"

/* allocate a frame if available */
int alloc_frame(List* frames) {
    int frame_num;
    int* data;
    if (list_size(frames) == 0) { // no frames available
        return -1;
    } else {
        if (list_pop(frames, (void*)&data) != 0) { // couldn't get a frame
            return -1;
        } else {
            frame_num = *data;
        }
    }
    return frame_num;
}

int free_frame(List* frames, int frame_num) {
    int* data;
    if ((data = (int*)malloc(sizeof(int))) == NULL) {
        return -1;
    }
    // put the frame back into the list of available frames
    *data = frame_num;
    if (list_push(frames, data) != 0) { // couldn't put the frame back
        return -1;
    }
    return 0;
}