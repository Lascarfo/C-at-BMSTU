#include "minimum.h"
#include "const.h"

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
