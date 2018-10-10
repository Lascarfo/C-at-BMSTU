// filter.c

/**
 \file
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "const.h"
#include "filter.h"
#include "io.h"

/**
* \brief эта функция определяет номер элемента
* \details эта функция возвращает указатель на элемент массива, соответствующий
* \ условию функции - фильтра.
*/


const int *count_pos(const int *arr, const int *arr_end)
{
    const int *cache = arr_end;
    while (arr < arr_end)
    {
        if (*arr < 0)
            cache = arr;
        arr++;
    }
    return cache;
}

/**
* \brief эта функция копирует все элементы из старого массива в новый
* \details
*/


void copy_arr(const int *arr, int *arr_s, int *arr_s_end)
{
    while (arr_s < arr_s_end)
    {
        *arr_s = *arr;
        arr_s++;
        arr++;
    }
}

/**
* \brief эта отсеивает все числа в массиве, которые соответствуют заданному условию
* \details функция выполняет заданную проверку, в данном случае она определяет последнее отрицательное
* число в массиве; если такого числа нет, то возвращает абсолютно идентичный изначальному массив.
*/


int key(const int *arr, const int *arr_end, int **arr_n, int **arr_n_end)
{
    int rc = OK, len = OK;
    const int *pos = NULL;
/*
    printf("arr_end: %pd\n", (void * ) arr_end);
    printf("arr: %pd\n", (void * )arr);
    printf("diff: %d\n", (arr_end - arr));
*/

    if ((arr != NULL && arr_end != NULL) && (arr < arr_end))
    {
        pos = count_pos(arr, arr_end);
        len = pos - arr;
        if (len > 0)
        {
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
            rc = ERR_MEMORY;
        }
    }
    else
    {
        rc = ERR_ARRAY;
    }
    return rc;
}
