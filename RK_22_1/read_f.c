#include <stdio.h>

void read(int *x, int *y, FILE *file1, FILE *file2)
{
    int i = -1, j = -1, cache = 0;
    while (fscanf(file1, "%d", &cache) == 1)
    {
        if (i > -1)
            x[i] = cache;
        i++;
    }
    while (fscanf(file2, "%d", &cache) == 1)
    {
        if (j > -1)
            y[j] = cache;
        j++;
     }
}
