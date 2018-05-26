#include <stdio.h>

void minimum(int *number, int *pb, int *pe)
{
    int *end = pe - 1, *pb2 = pb + 1;
    while (pb < end)
    {
        if ((*number) >  ((*pb)*(*pb2)))
        {
            *number = (*pb)*(*pb2);
        }
    pb++;
    pb2++;
    }
}
