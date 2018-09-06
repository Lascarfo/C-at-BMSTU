#include <stdio.h>
#include <stdbool.h>

#include "const.h"
#include "read.h"
#include "print.h"
#include "usage.h"
#include "findnum.h"



int main(int argc, char **argv)
{
    bool flag = false;
    int error = OK, leng = OK, number = OK;
    int *len = &leng, *fin_num = &number;
    FILE *file;
    if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (file)
        {
            int arr[N] = {0};
            int *ar = arr;
            error = readar(file, ar, len);
            printar(ar, len);
            flag = findnum(ar, len, fin_num);
            if (flag == false)
            {
                printf("res: %d\n", *fin_num);
            }
            else
            {
                printf("cannot find the number in this file...\n");
            }
        }
        else
        {
          error = ERR_R;
          printf("err open file\n");
        }
    }
    else
    {
      error = ERR_R;
      usage();
    }
	return error;
}
