#include <stdio.h>
#include "const.h"
#include "read.h"
#include "print.h"
#include "usage.h"
#include "findnum.h"


int main(int argc, char **argv)
{

    int error = OK, leng = OK;
    int *len = &leng;
    FILE *file;
    if (argc == 2)
    {
        int arr[N] = {0};
        int *ar = arr;
        int *ar2 = arr;
        file = fopen(argv[1], "r");
        if (file)
        {
          error = readar(file, ar, len);
          printar(ar, len);
          findnum(ar, len);
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
