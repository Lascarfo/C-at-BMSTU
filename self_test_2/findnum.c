#include <stdio.h>
#include <stdbool.h>


bool findnum(int *ar, int *len, int *fin_num)
{
    bool flag = true;
    int num = -1;
    for (int i = 0; i < *len; i++)
    {
        if (*ar < 0 && (((*len) - 1) != i) && flag == true)
        {
            *fin_num = *(ar + 1);
            flag = false;
        }
        ar++;
    }
    return flag;
}
