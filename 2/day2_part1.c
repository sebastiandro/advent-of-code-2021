
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <string.h>

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

    char direction[16];
    int magnitude;
    int increases = 0;
    int prev_depth = 0;
    int x = 0;
    int y = 0;

    FILE *fp;
    fp = fopen("2/input", "r");
    if (fp)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s %d", direction, &magnitude);

            if (strcmp(direction, "up") == 0)
            {
                y -= magnitude;
            }
            else if (strcmp(direction, "forward") == 0)
            {
                x += magnitude;
            }
            else if (strcmp(direction, "down") == 0)
            {
                y += magnitude;
            }
        }
        fclose(fp);
        printf("Final position is (%d,%d), multiplied: %d\n", x, y, x * y);
    }
    end_time = now();
    total_time = end_time - start_time;
    printf("\nTotal runtime: %.4f seconds\n", total_time);
    return 0;
}