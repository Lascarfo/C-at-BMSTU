/*
Вычислить значение min(x[0]*x[1], x[1]*x[2],x[2]*x[3], ..., x[n-3]*x[n-2], x[n-2]*x[n-1]), где
x[i] - элементы массива x из n элементов.
*/


#include <limits.h>
#include "field.c"
#include "usage.c"

#define ERR_OFILE 1
#define ERR_ARR 2
#define ERR_INPUT 3


void usage(void);

int field(FILE* file, int *arr, int *number);

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
