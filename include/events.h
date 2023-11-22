#pragma once
#include "queue.h"

typedef int Event;

int receive_event(Queue* events, const Event* event);
int process_event(Queue* events, int (*dispatch)(Event* event));
int dispatcher(Event* event);
int events();