#include "stack.h"
#include <stddef.h>
#include <stdio.h>

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

int main(void) {
    Stack start, temp, goal;
    initialize(&start, &temp, &goal);

    printf("size of start: %zu\n", stack_size(&start));
    printf("size of goal: %zu\n", stack_size(&goal));

    solve(&start, &goal, &temp, DISCS);

    printf("size of start: %zu\n", stack_size(&start));
    printf("size of goal: %zu\n", stack_size(&goal));
}