#include "minimum.h"
#include "const.h"

int field(FILE* file, int *arr)
{
    int cache = 0;
    int *pb = arr;
    int *pe = arr;
    while (fscanf(file, "%d", &cache) == 1)
    {
        *pe = cache;
        pe++;
        if ((pe - pb) > 100)
            return ERR_INPUT;
    }
    if ((pe - pb) < 2)
    {
            printf("err in file");
            return ERR_INPUT;
    }
    else
        minimum(pb, pe);
    return OK;
}
