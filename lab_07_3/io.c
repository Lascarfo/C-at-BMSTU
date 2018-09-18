// io.c

#include <stdlib.h>
#include "const.h"
#include "io.h"


int count_n(FILE *file)
{
    int count = 0, cache;
    while(fscanf(file, "%d", &cache) == 1)
        count++;
    return count;
}

int read_array(FILE *file, int *arr, int *arr_end)
{
    while (arr < arr_end)
    {
        if (fscanf(file, "%d", arr) != 1)
            return ERR_ARRAY;
        arr++;
    }
    return OK;
}

int read(FILE *file, int **arr, int **arr_end)
{
    int count, rc;
    rewind(file);
    count = count_n(file);
    if (count > 0)
    {
        int *mem_buf = malloc(count * sizeof(int));
        if (mem_buf)
        {
            rewind(file);
            rc = read_array(file, mem_buf, (mem_buf + count));
            if (rc == OK)
            {
                *arr = mem_buf;
                *arr_end = mem_buf + count;
            }
            else
                free(mem_buf);
        }
        else
            rc = ERR_MEMORY;
    }
    else
        rc = ERR_EMPTY;
    return rc;
}

int save(FILE *file, const int *arr, const int *arr_end)
{
    while (arr < arr_end)
    {
        fprintf(file, "%d ", *arr);
        arr++;
    }
    fprintf(file, "\n");
    return OK;
}

void print(const int *arr, const int *arr_end)
{
    save(stdout, arr, arr_end);
    fprintf(stdout, "\n");
}
