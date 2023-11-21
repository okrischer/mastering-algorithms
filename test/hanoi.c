#include <stddef.h>
#include <stdio.h>
#include "stack.h"
#include "test.h"

void initialize(Stack* start, Stack* temp, Stack* goal) {
    stack_init(start, NULL);
    stack_init(temp, NULL);
    stack_init(goal, NULL);

    static int disc1 = 1;
    static int disc2 = 2;
    static int disc3 = 3;

    stack_push(start, &disc3);
    stack_push(start, &disc2);
    stack_push(start, &disc1);
}

void solve(Stack* start, Stack* goal, Stack* temp, int n) {
    if (n == 1) {
        int* disc;
        stack_pop(start, (void*)&disc);
        stack_push(goal, disc);
    } else {
        solve(start, temp, goal, n-1);
        solve(start, goal, temp, 1);
        solve(temp, goal, start, n-1);
    }
}

int hanoi() {
    Stack start, temp, goal;
    initialize(&start, &temp, &goal);

    size_t size = stack_size(&start);
    if (size != 3) {
        printf("size of start should be %d but is %zu\n", 3, size);
        return TEST_FAILURE;
    }

    int* next_disc = stack_peek(&start);
    if (*next_disc != 1) {
        printf("first disc of start should be %d but is %d\n", 1, *next_disc);
        return TEST_FAILURE;
    }

    solve(&start, &goal, &temp, 3);

    size = stack_size(&start);
    if (size != 0) {
        printf("size of start should be %d but is %zu\n", 0, size);
        return TEST_FAILURE;
    }

    size = stack_size(&goal);
    if (size != 3) {
        printf("size of goal should be %d but is %zu\n", 3, size);
        return TEST_FAILURE;
    }

    stack_pop(&goal, (void*)&next_disc);
    if (*next_disc != 1) {
        printf("first disc of goal should be %d but is %d\n", 1, *next_disc);
        return TEST_FAILURE;
    }

    stack_pop(&goal, (void*)&next_disc);
    if (*next_disc != 2) {
        printf("next disc of goal should be %d but is %d\n", 2, *next_disc);
        return TEST_FAILURE;
    }

    stack_pop(&goal, (void*)&next_disc);
    if (*next_disc != 3) {
        printf("next disc of goal should be %d but is %d\n", 3, *next_disc);
        return TEST_FAILURE;
    }

    int success = stack_pop(&goal, (void*)&next_disc);
    if (success != -1) {
        printf("popping from empty list should not be successful\n");
        return TEST_FAILURE;
    }

    return TEST_SUCCESS;
}