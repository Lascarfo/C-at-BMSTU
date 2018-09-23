#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#include "sort.h"
#include "io.h"

//  swap func

void swap (void *left, void *right, size_t size)
{
    char buf[size];
    memcpy(buf, left, size);
    memcpy(left, right, size);
    memcpy(right, buf, size);

}

// compare for int

int cmp_int(const void *left, const void *right)
{
    return(*(int*)(left) - *(int*)(right));
}

// mysort function num. 6

void mysort(void *base, size_t nitems, size_t size, int(*cmpr)(const void*, const void*))
{
    if (nitems != 0)
    {
        char *arr_s = base;
        char *arr_s_end = arr_s + nitems * size - size;

        bool even = false;

        while (arr_s != arr_s_end)
        {
            even = !even;
            if (even)
            {
                if (cmpr(arr_s_end, (arr_s_end - size)) < 0)
                {
                    swap(arr_s_end, (arr_s_end - size), size);
                    arr_s = base;
                    arr_s_end = (char* )(base) + nitems * size - size;

                }
                else
                    arr_s_end -= size;
            }
            else
            {
                if (cmpr(arr_s, (arr_s + size)) > 0)
                {
                    swap(arr_s, (arr_s + size), size);
                    arr_s = base;
                    arr_s_end = (char* )(base) + nitems * size - size;
                }
                else
                    arr_s += size;
            }
        }
    }    
}
