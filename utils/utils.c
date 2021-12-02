#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "utils.h"

double now()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.;
}

void print_runtime(double start_time, double end_time)
{
    printf("Total runtime: %.4f seconds\n", end_time - start_time);
}