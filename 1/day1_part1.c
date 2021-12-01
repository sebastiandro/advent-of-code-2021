#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

double now()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return tv.tv_sec + tv.tv_usec / 1000000.;
}

int main()
{
    int depth = 0;
    int increases = 0;
    int prev_depth = 0;

    double end_time;
    double total_time;
    double start_time = now();

    FILE *fp;
    fp = fopen("1/input", "r");

    if (fp)
    {
        fscanf(fp, "%d", &depth);
        while (!feof(fp))
        {
            if (depth > prev_depth)
            {
                increases++;
            }
            prev_depth = depth;
            fscanf(fp, "%d", &depth);
        }
        fclose(fp);
        printf("There are %d increases\n", increases);
    }
    end_time = now();
    total_time = end_time - start_time;
    printf("Total runtime: %.4f seconds", total_time);
    return 0;
}