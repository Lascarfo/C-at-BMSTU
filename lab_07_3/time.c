#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
#include "io.h"

#define N 20



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
        unsigned long long tb, te;
        int len = 1;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {1};
        unsigned long long tb, te;
        int len = 1;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {2, 1};
        unsigned long long tb, te;
        int len = 2;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {2, 1};
        unsigned long long tb, te;
        int len = 2;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {3, 2, 1};
        unsigned long long tb, te;
        int len = 3;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {3, 2, 1};
        unsigned long long tb, te;
        int len = 3;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 4;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 4;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 5;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 5;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 6;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 6;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {7, 6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 7;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {7, 6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 7;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 8;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 8;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    {
        int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 9;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        mysort(arr, arr_end, sizeof(int), cmp_int);
        te = tick();
        printf("TIME mysort: %llu\n", (te - tb));
        print(arr, arr_end);
    }
    {
        int array[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
        unsigned long long tb, te;
        int len = 9;
        int *arr = array;
        int *arr_end = array + len;
        tb = tick();
        qsort(arr, len, sizeof(int), cmp_int);
        te = tick();
        printf("TIME qsort: %llu\n", (te - tb));
        print(arr, arr_end);

    }
    return 0;

}
