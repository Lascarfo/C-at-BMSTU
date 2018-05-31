/*
Вычислить значение min(x[0]*x[1], x[1]*x[2],x[2]*x[3], ..., x[n-3]*x[n-2], x[n-2]*x[n-1]), где
x[i] - элементы массива x из n элементов.
*/


#include <limits.h>
#include "field.h"
#include "usage.h"
#include "const.h"


int main(int argc, char** argv)
{
    int err = OK;
    int arr[ARR] = {0};
    FILE* file;
    if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (file)
        {
            err = field(file, arr);
            fclose(file);
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

    return err;
}

