/**
 * \brief это программа, выполняющая модульные тесты
 * \details модульные тесты написаны для функций key и mysort.
*/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "const.h"
#include "sort.h"
#include "filter.h"
#include "io.h"


unsigned long long tick(void)
{
    unsigned long long d;
    __asm__ __volatile__ ("rdtsc" : "=A" (d) );
    return d;
}

bool check(const int *result, const int *arr_s, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (*(result + i) != *(arr_s + i))
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char *argv[])
{
    bool printi = false;
    if (argc == 2)
    {
        if (strcmp(argv[1], "p") == 0)
            printi = true;
        else
            printi = false;
    }

    {  //key func from filter.h tests

        printf("\t\t\t***key*** func tests:\n");
        {
            printf("\n");
            printf("first array:\n");
            bool flag = true;
            int key_flag;
            int len = 5;
            int array[] = { 1, 2, 3, 4, 5 };
            int result[] = { 1, 2, 3, 4, 5 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            int *arr_s, *arr_s_end;
            arr_s = arr_s_end = NULL;
            key_flag = key(arr, arr_end, &arr_s, &arr_s_end);
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
                printf("  filtered: ");
                print(arr_s, arr_s_end);
            }
            flag = check(res, arr_s, len);
            if (key_flag != 0)
                flag = false;
            printf("test 1 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
            free(arr_s);
        }
        {
            printf("second array:\n");
            bool flag = true;
            int key_flag;
            int len = 5;
            int array[] = { 1, 2, 3, 4, 5, -1 };
            int result[] = { 1, 2, 3, 4, 5 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len + 1;
            int *arr_s, *arr_s_end;
            arr_s = arr_s_end = NULL;
            key_flag = key(arr, arr_end, &arr_s, &arr_s_end);
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
                printf("  filtered: ");
                print(arr_s, arr_s_end);
            }
            flag = check(res, arr_s, len);
            if (key_flag != 0)
                flag = false;
            printf("test 2 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
            free(arr_s);
        }
        {
            printf("third array:\n");
            bool flag = true;
            int key_flag;
            int len = 2;
            int array[] = { 1, 2, -3, 4, 5 };
            int result[] = { 1, 2 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + 5;
            int *arr_s, *arr_s_end;
            arr_s = arr_s_end = NULL;
            key_flag = key(arr, arr_end, &arr_s, &arr_s_end);
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
                printf("  filtered: ");
                print(arr_s, arr_s_end);
            }
            flag = check(res, arr_s, len);
            if (key_flag != 0)
                flag = false;
            printf("test 3 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
            free(arr_s);
        }
        {
            printf("fourth array:\n");
            bool flag = true;
            int key_flag;
            int len = 0;
            int array[] = { -1, 2, 3, 4, 5 };
            int result[1];
            int *res = result;
            int *arr = array;
            int *arr_end = arr + 5;
            int *arr_s, *arr_s_end;
            arr_s = arr_s_end = NULL;
            key_flag = key(arr, arr_end, &arr_s, &arr_s_end);
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
                printf("  filtered: ");
                print(arr_s, arr_s_end);
            }
            flag = check(res, arr_s, len);
            if (key_flag != 0)
                flag = false;
            printf("test 4 was %s\n", (flag) ? "not passed" : "passed");
            printf("\n");
            free(arr_s);
        }
    }
    {  //mysort func from mysort.h tests
        printf("\t\t\t***mysort*** func tests:\n");
        {
            printf("\n");
            printf("first array:\n");
            unsigned long long start, stop;
            bool flag = true;
            int len = 5;
            unsigned long long timer = OK;
            int array[] = { 1, 2, 3, 4, 5 };
            int arr_copy[] = { 1, 2, 3, 4, 5 };
            int result[] = { 1, 2, 3, 4, 5 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
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
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("sorting time: %llu\n", timer);
            }
            flag = check(res, arr, len);
            printf("test 1 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
        {
            printf("second array:\n");
            unsigned long long start, stop;
            unsigned long long timer = OK;
            bool flag = true;
            int len = 5;
            int array[] = { 5, 4, 3, 2, 1 };
            int arr_copy[] = { 5, 4, 3, 2, 1 };
            int result[] = { 1, 2, 3, 4, 5 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    array[j] = arr_copy[j];
                }
                start = tick();
                mysort(arr, len, sizeof(int), cmp_int);
                stop = tick();
                if (i > 0) // на первой итерации насчитывал 1400 - 1600 тактов, на всех последующих -– 100 - 300
                {
                    timer += (stop - start) / (N - 1);
                }
            }
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("sorting time: %llu\n", timer);
            }
            flag = check(res, arr, len);
            printf("test 2 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
        {
            printf("third array:\n");
            unsigned long long start, stop;
            unsigned long long timer = OK;
            bool flag = true;
            int len = 5;
            int array[] = { 1, 3, 2, 5, 0 };
            int arr_copy[] = { 1, 3, 2, 5, 0 };
            int result[] = { 0, 1, 2, 3, 5 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
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
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("sorting time: %llu\n", timer);
            }
            flag = check(res, arr, len);
            printf("test 3 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
        {
            printf("fourth array:\n");
            unsigned long long start, stop;
            unsigned long long timer = OK;
            bool flag = true;
            int len = 5;
            int array[] = { 1, 1, 1, 1, 1 };
            int arr_copy[] = { 1, 1, 1, 1, 1 };
            int result[] = { 1, 1, 1, 1, 1 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
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
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("sorting time: %llu\n", timer);
            }
            flag = check(res, arr, len);
            printf("test 4 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
        {
            printf("fifth array:\n");
            unsigned long long start, stop;
            unsigned long long timer = OK;
            bool flag = true;
            int len = 2;
            int array[] = { 2, 1 };
            int arr_copy[] = { 2, 1 };
            int result[] = { 1, 2 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
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
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("TIME mysort: %llu\n", (stop - start));
            }
            flag = check(res, arr, len);
            printf("test 5 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
        {
            printf("sixth array:\n");
            unsigned long long start, stop;
            unsigned long long timer = OK;
            bool flag = true;
            int len = 2;
            int array[] = { 1, 2 };
            int arr_copy[] = { 1, 2 };
            int result[] = { 1, 2 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
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
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("sorting time: %llu\n", timer);
            }
            flag = check(res, arr, len);
            printf("test 6 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
        {
            printf("seventh array:\n");
            unsigned long long start, stop;
            unsigned long long timer = OK;
            bool flag = true;
            int len = 1;
            int array[] = { 1 };
            int arr_copy[] = { 1 };
            int result[] = { 1 };
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
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
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("sorting time: %llu\n", timer);
            }
            flag = check(res, arr, len);
            printf("test 7 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
        {
            printf("eighth array:\n");
            unsigned long long start, stop;
            unsigned long long timer = OK;
            bool flag = true;
            int len = 0;
            int array[1];
            int arr_copy[1];
            int result[1];
            int *res = result;
            int *arr = array;
            int *arr_end = arr + len;
            if (printi)
            {
                printf("primordial: ");
                print(arr, arr_end);
            }
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
            if (printi)
            {
                printf("    sorted: ");
                print(arr, arr_end);
                printf("sorting time(?): %llu\n", timer);
            }
            flag = check(res, arr, len);
            printf("test 8 was %s\n", (flag) ? "passed" : "not passed");
            printf("\n");
        }
    }
    return OK;
}
