/*
Вычислить значение min(x[0]*x[1], x[1]*x[2],x[2]*x[3], ..., x[n-3]*x[n-2], x[n-2]*x[n-1]), где
x[i] - элементы массива x из n элементов.
*/


#include <stdio.h>
#include <limits.h>

#define OK 0
#define ARR 100
#define ERR_OFILE 1
#define ERR_ARR 2
#define ERR_INPUT 3


void usage(void)
{
    fprintf(stdout, "Please make input following next instructions:\nmain.exec main.txt\n");
}

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

int main(int argc, char** argv)
{
    int err = OK;
    int number = INT_MAX;
    int arr[ARR] = {0};
    FILE* file;
    if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (file)
        {
            err = field(file, arr, &number);
        }
        else
        {
            err = ERR_OFILE;
        }
    }
    else
    {
        usage();
        err = ERR_OFILE;
    }
    if (number == INT_MAX)
    {
        err = ERR_INPUT;
    }
    else
    {
        fprintf(stdout, "MIN number is: %d\n", number);
    }
    return err;
}
