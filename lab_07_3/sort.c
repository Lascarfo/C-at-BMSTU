/**
 \file
 */


#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "sort.h"
#include "io.h"

//  swap func

/**
* \brief эта функция меняет расположение элементов
* \details на вход функции подается два адреса элементов, которые нужно поменять и размер этих элементов в байтах;
*  функция меняет эти элементы местами при помощи встроенной функции memcpy.
*/

void swap(void *left, void *right, size_t size)
{
    char buf[size];
    memcpy(buf, left, size);
    memcpy(left, right, size);
    memcpy(right, buf, size);
}

// compare for int

/**
* \brief эта функция сравнивает два переданных элемента типа int
* \details функция-компаратор получает два объекта и вычисляет и разность, соотвествуя типу.
*/


int cmp_int(const void *left, const void *right)
{
    return (*(int*)(left) - *(int*)(right));
}

// compare for char

/**
* \brief эта функция сравнивает два переданных элемента типа char
*/

int cmp_char(const void *left, const void *right)
{
    return (*(char*)left) - (*(char*)right);
}


// compare for double

/**
* \brief эта функция сравнивает два переданных элемента типа double
*/


int cmp_double(const void *left, const void *right)
{
    const double compare = (*(double*)left) - (*(double*)right);
    if (compare < 0)
    {
        return -1;
    }
    if (compare > 0)
    {
        return 1;
    }
    return 0;
}

// mysort function num. 6
/**
* \brief эта функция предназначена для сортировки массива заданным алогритмом
* \details функция mysort использует алгоритм модифицированного пузрька II, который выполняет проходы сверху по
*  четным итерациям и проходы снизу по нечетным; во всех остальных аспектах используются принципы обычного пузырька.
*/



void mysort(void *base, size_t nitems, size_t size, int(*cmpr)(const void*, const void*))
{
    if (nitems != 0)
    {
        char *arr_s = base;
        char *arr_s_end = arr_s + nitems * size - size;
        char *start = base;
        char *end = arr_s + nitems * size - size;
        bool even = false;

        while (end >= start)
        {
            even = !even;
            if (even)
            {
                while (arr_s_end > start)
                {
                    if (cmpr(arr_s_end, (arr_s_end - size)) < 0)
                    {
                        swap(arr_s_end, (arr_s_end - size), size);
                    }
                    arr_s_end -= size;
                }
                start += size;
                arr_s_end = end;
            }
            else
            {
                while (arr_s < end)
                {
                    if (cmpr(arr_s, (arr_s + size)) > 0)
                    {
                        swap(arr_s, (arr_s + size), size);
                    }
                    arr_s += size;
                }
                end -= size;
                arr_s = start;
            }
        }
    }
}
