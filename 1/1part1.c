#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "utils.h"

int main()
{
    int depth = 0;
    int increases = 0;
    int prev_depth = 0;

    double start_time = now();

    FILE *fp;
    fp = fopen("input.txt", "r");

    if (fp)
    {
        fscanf(fp, "%d", &depth);
        while (!feof(fp))
        {
            if (depth > prev_depth)
                increases++;

            prev_depth = depth;
            fscanf(fp, "%d", &depth);
        }
        fclose(fp);
        printf("There are %d increases\n", increases);
    }
    double end_time = now();
    print_runtime(start_time, end_time);
    return 0;
}