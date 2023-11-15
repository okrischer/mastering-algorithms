#include <bits/time.h>
#include <stdio.h>
#include <time.h>
#include <stddef.h>
#include "bm.h"

double bm_fun(size_t (*fun)(size_t), size_t n) {
    struct timespec start, stop;

    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &start);
        fun(n);
    clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &stop);

    double duration = ((stop.tv_nsec) - (start.tv_nsec));
    return duration;
}

/* simple benchmark for two functions of type size_t -> size_t */
int bm(size_t (*fun1)(size_t), size_t (*fun2)(size_t), size_t n) {
    double f1_dur = bm_fun(*fun1, n);
    double f2_dur = bm_fun(*fun2, n);

    if (fun1(n) != fun2(n)) {
        printf("benchmarked functions return different values\n");
        return 1;
    }

    char unit = 'n';
    if (f1_dur * 1e-6 > 1.0) {
        unit = 'm';
        f1_dur *= 1e-6;
        f2_dur *= 1e-6;
    } else if (f1_dur * 1e-3 > 1.0) {
        unit = 'u';
        f1_dur *= 1e-3;
        f2_dur *= 1e-3;
    }

    printf("fun1: %.3f %cs, fun2: %.3f %cs\n",
    f1_dur, unit, f2_dur, unit);
    return 0;
}