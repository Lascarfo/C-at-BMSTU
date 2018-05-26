#include <stdio.h>
#include "minimum.c"
#define OK 0
#define ARR 100

void minimum(int *number, int *pb, int *pe);

int field(FILE* file, int *arr, int *number)
{
    int cache = 0;
    int *pb = arr;
    int *pe = arr;
    for (int i = 0; i < ARR; i++)
    {
        if (fscanf(file, "%d", &cache) == 1)
        {
            *pe = cache;
            pe++;
        }
    }
    minimum(number, pb, pe);
    return OK;
}
