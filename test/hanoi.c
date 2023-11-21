#include <stddef.h>
#include <stdio.h>
#include "stack.h"
#include "test.h"

#define DISCS 8

void initialize(Stack* start, Stack* temp, Stack* goal) {
    stack_init(start, NULL);
    stack_init(temp, NULL);
    stack_init(goal, NULL);

    static int disc1 = 1;
    static int disc2 = 2;
    static int disc3 = 3;
    static int disc4 = 4;
    static int disc5 = 5;
    static int disc6 = 6;
    static int disc7 = 7;
    static int disc8 = 8;

    stack_push(start, &disc8);
    stack_push(start, &disc7);
    stack_push(start, &disc6);
    stack_push(start, &disc5);
    stack_push(start, &disc4);
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
    if (size != 8) {
        printf("size of start should be %d but is %zu\n", 8, size);
        return TEST_FAILURE;
    }

    int* next_disc = stack_peek(&start);
    if (*next_disc != 1) {
        printf("first disc of start should be %d but is %d\n", 1, *next_disc);
        return TEST_FAILURE;
    }

    solve(&start, &goal, &temp, DISCS);

    size = stack_size(&start);
    if (size != 0) {
        printf("size of start should be %d but is %zu\n", 0, size);
        return TEST_FAILURE;
    }

    size = stack_size(&goal);
    if (size != 8) {
        printf("size of goal should be %d but is %zu\n", 8, size);
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

    return TEST_SUCCESS;
}