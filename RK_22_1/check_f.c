#include <stdbool.h>

bool check_f(int n2, int *pa, int *pb)
{
    flag = true;
    for (int i = 0; i < n2; i++)
    {
    //          printf("pa, pb: %d, %d\n", *pa, *pb);
        if (*pa == *pb)
            flag = false;
        pb++;
    }
    return flag;
}
