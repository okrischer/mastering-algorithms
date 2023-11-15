#pragma once
#include "list.h"

int alloc_frame(List* frames);
int free_frame(List* frames, int frame_num);
