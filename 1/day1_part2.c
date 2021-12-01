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
    fp = fopen("input", "r");

    int window[3] = {0, 0, 0};
    int line_ix = 0;
    int window_sum = 0;
    int prev_sum = 0;
    if (fp)
    {
        fscanf(fp, "%d", &depth);
        while (!feof(fp))
        {

            // read net depth
            window[line_ix % 3] = depth;

            line_ix++;
            fscanf(fp, "%d", &depth);

            if (line_ix < 3)
                continue;

            // compare window sums
            window_sum = 0;
            for (int i = 0; i < 3; i++)
            {
                window_sum += window[i];
            }

            if (window_sum > prev_sum)
            {
                increases++;
            }
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