
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils.h"

int main()
{
    double start_time = now();
    char direction[8];
    int magnitude;
    int x = 0;
    int y = 0;
    int aim = 0;

    FILE *fp;
    fp = fopen("input.txt", "r");
    if (fp)
    {
        while (!feof(fp))
        {
            fscanf(fp, "%s %d", direction, &magnitude);

            if (strcmp(direction, "up") == 0)
            {
                aim -= magnitude;
            }
            else if (strcmp(direction, "forward") == 0)
            {
                x += magnitude;
                y += magnitude * aim;
            }
            else if (strcmp(direction, "down") == 0)
            {
                aim += magnitude;
            }
        }
        fclose(fp);
        printf("Final position is (%d,%d), multiplied: %d\n", x, y, x * y);
    }
    double end_time = now();
    print_runtime(start_time, end_time);
    return 0;
}