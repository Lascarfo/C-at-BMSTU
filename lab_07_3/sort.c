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

void mysort(void *base, void *base_end, size_t size, int(*cmpr)(const void*, const void*))
{

    char *arr_s = base;
    char *arr_s_end = (char* )(base_end) - size;



    bool even = true;
    bool end = true;

    if (arr_s == arr_s_end + size)
        end = false;

    while (end)
    {
        end = false;
        arr_s = base;
        arr_s_end = (char* )(base_end) - size;
        // print((void*)(arr_s), (void*)(arr_s_end + 4));
        // printf("arr_s: %d\n", *arr_s);
        // printf("arr_s_end: %d\n", *arr_s_end);
        while (arr_s != arr_s_end)
        {
            if (even)
            {
                if (cmpr(arr_s_end, (arr_s_end - size)) < 0)
                {
                    swap(arr_s_end, (arr_s_end - size), size);
                    end = true;
                }
                arr_s_end -= size;
                even = false;
            }
            else
            {
                if (cmpr(arr_s, (arr_s + size)) > 0)
                {
                    swap(arr_s, (arr_s + size), size);
                    end = true;
                }
                arr_s += size;
                even = true;
            }
        }
    }
}
