#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "usage.h"
#include "const.h"
#include "io.h"
#include "filter.h"
#include "sort.h"

int main(int argc, char *argv[])
{
    int rc = OK;
    FILE *file_in;
    FILE *file_out;
    if (argc == 3)
    {
        file_in = fopen(argv[1], "r");
        if (file_in)
        {
            file_out = fopen(argv[2], "w");
            if (file_out)
            {
                int *arr_s = NULL, *arr_s_end = NULL;
                rc = read(file_in, &arr_s, &arr_s_end);
                if (rc == OK)
                {
                    if ((arr_s_end - arr_s) > 1)
                    {
                        mysort((void*)(arr_s), (void*)(arr_s_end), sizeof(int), cmp_int);
                    }
                    if (rc == OK)
                    {
                        save(file_out, arr_s, arr_s_end);
                    }
                    free(arr_s);
                }
                fclose(file_out);
            }
            else
            {
                fprintf(stdout, "Problems with open file main_out.txt\n");
                usage();
                rc = ERR_FILE;
            }
            fclose(file_in);
        }
        else
        {
            fprintf(stdout, "Problems with open file main_in.txt\n");
            usage();
            rc = ERR_FILE;
        }
    }
    else if ((argc == 4) && (strcmp(argv[3], "f") == 0))
    {
        file_in = fopen(argv[1], "r");
        if (file_in)
        {
            file_out = fopen(argv[2], "w");
            if (file_out)
            {
                int *arr = NULL, *arr_end = NULL;
                rc = read(file_in, &arr, &arr_end);
                if (rc == OK)
                {
                    int *arr_s = NULL, *arr_s_end = NULL;
                    rc = key(arr, arr_end, &arr_s, &arr_s_end);  // вызов функции - фильтра
                    if ((arr_s_end - arr_s) > 1)
                    {
                        mysort((void*)(arr_s), (void*)(arr_s_end), sizeof(int), cmp_int);
                    }
                    if (rc == OK)
                    {
                        save(file_out, arr_s, arr_s_end);
                        free(arr_s);
                    }
                    free(arr);
                }
                fclose(file_out);
            }
            else
            {
                fprintf(stdout, "Problems with open file main_out.txt\n");
                usage();
                rc = ERR_FILE;
            }
            fclose(file_in);
        }
        else
        {
            fprintf(stdout, "Problems with open file main_in.txt\n");
            usage();
            rc = ERR_FILE;
        }
    }
    else
    {
        usage();
        return ERR_EMPTY;
    }
    return rc;
}
