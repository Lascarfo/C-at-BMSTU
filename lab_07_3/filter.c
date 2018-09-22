// filter.c

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "const.h"
#include "filter.h"
#include "io.h"

const int *count_pos(const int *arr, const int *arr_end)
{
    const int *cache = NULL;
    cache = arr_end;
    while (arr < arr_end)
    {
        if (*arr < 0)
            cache = arr + 1;
        arr++;
    }
    return cache;
}

void copy_arr(const int *arr, int *arr_s, int *arr_s_end)
{
    while (arr_s < arr_s_end)
    {
        *arr_s = *arr;
        arr_s++;
        arr++;
    }
}

int key(const int *arr, const int *arr_end, int **arr_n, int **arr_n_end)
{
    int rc = OK, len = OK;
    const int *pos = NULL;
/*
    printf("arr_end: %pd\n", (void * ) arr_end);
    printf("arr: %pd\n", (void * )arr);
    printf("diff: %d\n", (arr_end - arr));
*/

    if (arr != NULL && arr_end != NULL)
    {
        pos = count_pos(arr, arr_end);
        len = pos - arr;
        int *buf1 = malloc(len * sizeof (int));
        if (buf1)
        {
            *arr_n = buf1;
            *arr_n_end = *arr_n + len;
            copy_arr(arr, *arr_n, *arr_n_end);
        }
        else
        {
            rc = ERR_MEMORY;
        }
    }
    else
    {
        rc = ERR_ARRAY;
    }
    return rc;
}
