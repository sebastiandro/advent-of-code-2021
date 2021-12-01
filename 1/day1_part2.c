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
    double end_time;
    double total_time;
    double start_time = now();

    FILE *fp;
    fp = fopen("1/input", "r");

    int window[3];
    int increases = 0;
    int line_ix = 0;
    int window_sum;
    int prev_sum = 0;
    int depth;

    if (fp)
    {
        fscanf(fp, "%d", &depth);
        while (!feof(fp))
        {

            // read depth
            window[line_ix % 3] = depth;

            line_ix++;
            fscanf(fp, "%d", &depth);

            if (line_ix < 3)
                continue;

            // compare window sums
            window_sum = 0;
            for (int i = 0; i < 3; i++)
                window_sum += window[i];

            if (window_sum > prev_sum)
                increases++;

            prev_sum = window_sum;
        }
        fclose(fp);
        printf("There are %d increases\n", increases);
    }
    end_time = now();
    total_time = end_time - start_time;
    printf("Total runtime: %.4f seconds", total_time);
    return 0;
}