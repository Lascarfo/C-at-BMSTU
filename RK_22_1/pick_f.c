#include <stdio.h>
#include <stdbool.h>
#include "check_f.h"


void pick(int *x, int *y, int *number, int n1, int n2)
{
    int *pa = x;
    int *pb = y;
    bool flag = true;
    bool flag1 = true;
    for (int i = 0; i < n1; i++)
    {
        pb = y;
        flag = check_f(n2, pa, pb);
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
