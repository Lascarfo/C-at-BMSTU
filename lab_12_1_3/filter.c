// filter.c

/**
 \file
 */

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>


#include "lib.h"

void calculate(const int *arr, const int *arr_end, int *len)
{
    const int *pos = count_pos(arr, arr_end);
    *len = pos - arr;
}


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


int key(const int *arr, const int *arr_end, int *arr_n, int **arr_n_end, int *size_buf)
{
    int rc = OK;
    if (arr == NULL || arr_end == NULL || (arr_end < arr))
    {
        return 10; // основная ошибка в полученных данных
    }
    if (arr_n == NULL && (*size_buf == 0))
    {
        calculate(arr, arr_end, size_buf);
        return 5; // нужно аллоцировать память
    }
    if (arr_n)
    {
        int cache;
        calculate(arr, arr_end, &cache);
        if (cache > *size_buf)
        {
            *size_buf = cache;
            return 10;
        }
        else
        {
            *arr_n_end = arr_n + cache;
            copy_arr(arr, arr_n, *arr_n_end);
            *size_buf = cache;
        }
    }
    else
    {
        rc = 10;
    }
    return rc;
}


// printf("arr_end: %pd\n", (void * ) arr_end);
// printf("arr: %pd\n", (void * )arr);
// printf("diff: %ld\n", (arr_end - arr));
