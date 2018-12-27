// io.c

/**
 \file
 */

#include <stdlib.h>

#include "lib.h"



/**
* \brief эта функция определяет количество элементов в файле
* \details эта функция считает количество чисел типа [int] в файле
*  до тех пор, пока не найдет несоответсвующий объект, либо до конца файла.
*/

int count_n(FILE *file)
{
    int count = 0, cache;
    while (fscanf(file, "%d", &cache) == 1)
        count++;
    return count;
}


/**
* \brief эта функция считывает из файла числа типа [int]
* \details функция считывает целые числа, если по каким - либо причинам происходит ошибка считывания,
*  то функция возвращает код ошибки.
*/

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


/**
* \brief это основная функция файла, которая выполняет считывание чисел из файла в массив
* \details функция считает количество чисел в файле, затем выделяет для них память в системе, если память выделена успешно,
*  то числа переписываются в созданный массив, который попадает в основную функцию (@main) программы.
*/

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
}

void print_double(const double *arr, const double *arr_end)
{
    while (arr < arr_end)
    {
        fprintf(stdout, "%.1f ", *arr);
        arr++;
    }
    fprintf(stdout, "\n");
}

void print_char(const char *arr, const char *arr_end)
{
    while (arr < arr_end)
    {
        fprintf(stdout, "%c ", *arr);
        arr++;
    }
    fprintf(stdout, "\n");
}
