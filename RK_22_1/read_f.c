#include <stdio.h>

void read(int *x, int *y, FILE *file1, FILE *file2)
{
    cache = 0;
    while (fscanf(file1, "%d", &cache) == 1)
    {
        x[i] = cache;
    }
    while (fscanf(file2, "%d", &cache) == 1)
    {
        y[j] = cache;
    }
}
