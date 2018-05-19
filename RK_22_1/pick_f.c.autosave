#include <stdio.h>
#include <stdbool.h>


void pick(int *x, int *y, int *number, int n1, int n2)
{
    int *pa = x;
    int *pb = y;
    bool flag = true;
    bool flag1 = true;
    for (int i = 0; i < n1; i++)
    {
        pb = y;
        flag = true;
        for (int i = 0; i < n2; i++)
        {
//          printf("pa, pb: %d, %d\n", *pa, *pb);
            if (*pa == *pb)
                flag = false;
            pb++;
        }
        if (flag == true)
        {
            if (flag1 == true)
            {
                *number = *pa;
                flag1 = false;
            }
            else if (*number > *pa)
                *number = *pa;
        }
        pa++;
    }
}
