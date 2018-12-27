/**
 * \brief это программа, которая выполняет замер времени
 * \details программа вычисляет среднее арифмитическое количества циклов, затраченых на
 *  сортировку одних и тех же массивов функциями qsort и mysort для дальнейшего анализа.
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "lib.h"



unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}


unsigned long long time_mysort(int len, int *array, const int *arr_copy)
{
    unsigned long long start, stop;
    unsigned long long timer = OK;
    int *arr = array;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < len; j++)
        {
            array[j] = arr_copy[j];
        }
        start = tick();
        mysort(arr, len, sizeof(int), cmp_int);
        stop = tick();
        if (i > 0)
            timer += (stop - start);
    }
    timer /= (N - 1);
    return timer;
}

unsigned long long time_qsort(int len, int *array, const int *arr_copy)
{
    unsigned long long start, stop;
    unsigned long long timer = OK;
    int *arr = array;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < len; j++)
        {
            array[j] = arr_copy[j];
        }
        start = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        stop = tick();
        if (i > 0)
            timer += (stop - start);
    }
    timer /= (N - 1);
    return timer;
}


int *downstream(int *cache, int n)
{
    int *arr = NULL;
    arr = cache;
    for (int i = n; i > 0; i--)
    {
        *arr = i;
        arr++;
    }
    return cache;
}


int *upstream(int *cache, int n)
{
    int *arr = NULL;
    arr = cache;
    for (int i = 1; i <= n; i++)
    {
        *arr = i;
        arr++;
    }
    return cache;
}


int *randfill(int *cache, int n)
{
    int *arr = NULL;
    srand(time(NULL));
    arr = cache;
    for (int i = 1; i <= n; i++)
    {
        *arr = rand() % 10;
        arr++;
    }
    return cache;
}


// 0 - downstream, 1 – upstream, 2 - random filling
int *arr_generator(int n, int key)
{
    int *arr = NULL;
    int *cache = malloc(n * sizeof(int));
    if (cache)
    {
        switch (key)
        {
            case 0:
                arr = downstream(cache, n);
                break;
            case 1:
                arr = upstream(cache, n);
                break;
            case 2:
                arr = randfill(cache, n);
                break;
            default:
                printf("Smt gonna wrong!\n");
        }
    }
    return arr;
}

void save_r(unsigned long long timer_q, unsigned long long timer_m)
{
    FILE *file;
    file = fopen("results.txt", "a");
    if (file)
    {
        fprintf(file, "%llu %llu\n", timer_m, timer_q);
    }
}


int main_time(const int key)
{
    int rc = OK;
    int len = 0;
    int piece = 1;
    while (len != 1000)
    {
        len += piece;
        if (len < 10)
        {
            piece = 1;
        }
        else if (len < 100)
        {
            piece = 10;
        }
        else if (len <= 1000)
        {
            piece = 100;
        }
        unsigned long long timer_q = OK, timer_m = OK;
        int *array = arr_generator(len, key);
        if (array != NULL)
        {
            int *arr_copy = arr_generator(len, key);
            if (arr_copy != NULL)
            {
                timer_m = time_mysort(len, array, arr_copy);
                timer_q = time_qsort(len, array, arr_copy);
                printf("(%d) mysort: %llu\n", len, timer_m);
                printf("(%d) qsort:: %llu\n", len, timer_q);
                save_r(timer_m, timer_q);
                free(arr_copy);
            }
            else
            {
                return ERR_MEMORY;
            }
            free(array);
        }
        else
        {
            return ERR_MEMORY;
        }
    }
    return rc;
}

int main(void)
{
    int rc = OK;
    rc = main_time(0); //downstream
    if (rc == 0)
    {
        rc = main_time(1);  //upstream
    }
    if (rc == 0)
    {
        rc = main_time(2);  //random feeling
    }

    return rc;
}
