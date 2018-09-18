// filter.c

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "const.h"
#include "filter.h"
#include "io.h"

int count_pos(const int *arr, const int *arr_end)
{
    int pos = 1, cache = -1;
    while (arr < arr_end)
    {
        if (*arr < 0)
            cache = pos;
        arr++;
        pos++;
    }
    return cache;
}

void copy_arr(const int *arr, int *arr_s, int *arr_s_end)
{
    for (int i = 0; i < (arr_s_end - arr_s); i++)
        *(arr_s + i) = *(arr + i);
}

int key(const int *arr, const int *arr_end, int **arr_n, int **arr_n_end)
{
    int rc = OK, len = OK;
/*
    printf("arr_end: %pd\n", (void * ) arr_end);
    printf("arr: %pd\n", (void * )arr);
    printf("diff: %d\n", (arr_end - arr));
*/

    if (arr != NULL && arr_end != NULL)
    {
        int pos = count_pos(arr, arr_end);
        len = (pos != -1) ? pos : (arr_end - arr);
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
