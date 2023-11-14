#include <bits/time.h>
#include <stdio.h>
#include <time.h>
#include <stddef.h>
#include "bm.h"

int bm(size_t (*fun1)(size_t), size_t (*fun2)(size_t), size_t n) {

    struct timespec start, stop;
    size_t f1 = fun1(n);
    size_t f2 = fun2(n);

    if (f1 != f2) {
        printf("the functions to benchmark return different results: %zu, %zu\n",
            f1, f2);
        return 1;
    }

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    for (int i = 0; i < 100; i++) {
        fun1(n);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double f1_time = ((stop.tv_nsec * 1e-3) - (start.tv_nsec * 1e-3)) / 100;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
    for (int i = 0; i < 100; i++) {
        fun2(n);
    }
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);
    double f2_time = ((stop.tv_nsec * 1e-3) - (start.tv_nsec * 1e-3)) / 100;

    printf("fun1: %.3f us, fun2: %.3f us\n",
        f1_time, f2_time);
    return 0;
}