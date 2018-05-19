#include <stdio.h>
#include <stdbool.h>


void pick(int *x, int *y, int *z, int *number, int n1, int n2)
{
    int *pa = x;
    int *pb = y;
    int *pc = z;
    bool flag = true;
    for (int i = 0; i < n1; i++)
    {
        flag = true;
        for (int i = 0; i < n2; i++)
        {
            if (*pa == *pb)
                flag = false;
            pb++;
        }
        if (flag == true)
        {
            *pa = *pc;
            pc++;
        }
        pa++;
    }


}
