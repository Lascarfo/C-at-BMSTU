#include <stdio.h>

void read(int *x, FILE *file1)
{
    cache = 0;
    while (fscanf(file1, "%d", &cache) == 1)
    {
        x[i] = cache;
    }
}
