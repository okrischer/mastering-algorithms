#pragma once
#include "stack.h"

void initialize(Stack* start, Stack* temp, Stack* goal);
void solve(Stack* start, Stack* goal, Stack* temp, int n);
int hanoi();
