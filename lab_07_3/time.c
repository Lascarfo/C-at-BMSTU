/**
 * \brief это программа, которая выполняет замер времени
 * \details программа вычисляет среднее арифмитическое количества циклов, затраченых на
 *  сортировку одних и тех же массивов функциями qsort и mysort для дальнейшего анализа.
 *
*/


#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "io.h"
#include "const.h"




unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}



int main(void)
{
    {
        int array[] = {1};
        int arr_copy[] = {1};
        unsigned long long start, stop, timer = OK;
        int len = 1;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(1) mysort: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));
    }
    {
        int array[] = {1};
        int arr_copy[] = {1};
        unsigned long long start, stop, timer = OK;
        int len = 1;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(1) qsort:: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));

    }
    {
        int array[] = {2, 1};
        int arr_copy[] = {2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 2;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(2) mysort: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));
    }
    {
        int array[] = {2, 1};
        int arr_copy[] = {2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 2;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(2) qsort:: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));

    }
    {
        int array[] = {3, 2, 1};
        int arr_copy[] = {3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 3;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(3) mysort: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));
    }
    {
        int array[] = {3, 2, 1};
        int arr_copy[] = {3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 3;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(3) qsort:: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));

    }
    {
        int array[] = {4, 3, 2, 1};
        int arr_copy[] = {4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 4;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(4) qsort:: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));

    }
    {
        int array[] = {4, 3, 2, 1};
        int arr_copy[] = {4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 4;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(4) mysort: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));
    }
    {
        int array[] = {5, 4, 3, 2, 1};
        int arr_copy[] = {5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 5;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(5) qsort:: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));

    }
    {
        int array[] = {5, 4, 3, 2, 1};
        int arr_copy[] = {5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 5;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(5) mysort: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));
    }
    {
        int array[] = {6, 5, 4, 3, 2, 1};
        int arr_copy[] = {6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 6;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(6) qsort:: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));

    }
    {
        int array[] = {6, 5, 4, 3, 2, 1};
        int arr_copy[] = {6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 6;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(6) mysort: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));
    }
    {
        int array[] = {7, 6, 5, 4, 3, 2, 1};
        int arr_copy[] = {7, 6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 7;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(7) mysort: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));
    }
    {
        int array[] = {7, 6, 5, 4, 3, 2, 1};
        int arr_copy[] = {7, 6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 7;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(7) qsort:: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));

    }
    {
        int array[] = {8, 7, 6, 5, 4, 3, 2, 1};
        int arr_copy[] = {8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 8;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(8) mysort: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));
    }
    {
        int array[] = {8, 7, 6, 5, 4, 3, 2, 1};
        int arr_copy[] = {8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 8;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(8) qsort:: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));

    }
    {
        int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        int arr_copy[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 9;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(9) mysort: %llu\n", timer);
        // printf("array: ");
        // print(arr, (arr + len));
    }
    {
        int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        int arr_copy[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long start, stop, timer = OK;
        int len = 9;
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
                timer += (stop - start) / (N - 1);
        }
        printf("(9) qsort:: %llu\n", timer);
        printf("array: ");
        print(arr, (arr + len));
    }
    // {
    //     int array[100];
    //     int arr_copy[100];
    //     unsigned long long start, stop, timer = OK;
    //     int len = 100;
    //     int *arr = array;
    //     for (int i = 100; i > 0; i--)
    //     {
    //         array[i] = i;
    //         arr_copy[i] = i;
    //     }
    //     for (int i = 0; i < N; i++)
    //     {
    //         for (int j = 0; j < len; j++)
    //         {
    //             array[j] = arr_copy[j];
    //         }
    //         start = tick();
    //         mysort(arr, len, sizeof(int), cmp_int);
    //         stop = tick();
    //         if (i > 0)
    //             timer += (stop - start) / (N - 1);
    //     }
    //     printf("(100) mysort: %llu\n", timer);
    //     //print(arr, (arr + len)); // life threatening!
    // }
    // {
    //     int array[100];
    //     int arr_copy[100];
    //     unsigned long long start, stop, timer = OK;
    //     int len = 100;
    //     int *arr = array;
    //     for (int i = 100; i > 0; i--)
    //     {
    //         array[i] = i;
    //         arr_copy[i] = i;
    //     }
    //     for (int i = 0; i < N; i++)
    //     {
    //         for (int j = 0; j < len; j++)
    //         {
    //             array[j] = arr_copy[j];
    //         }
    //         start = tick();
    //         qsort(arr, len, sizeof(int), cmp_int);
    //         stop = tick();
    //         if (i > 0)
    //             timer += (stop - start) / (N - 1);
    //     }
    //     printf("(100) qsort:: %llu\n", timer);
    //     //print(arr, (arr + len)); // life threatening!
    // }
    return 0;
}
