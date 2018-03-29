#include <stdio.h>
#include <ctype.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

int NOD(int a, int b)
{
    while(a > 0 && b > 0)
        if(a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main(void)
{
    int a, b, rc = OK;
    printf("input (a and b) > 0: ");
    if (scanf("%d %d", &a, &b) == 2)
    {
        if (a > 0 && b > 0)
        {
            printf("NOD = %d\n", NOD(a, b));
        }
        else
        {
            rc = ERR_RANGE;
            printf("a or b < 0!\n");
        }

    }
    else
    {
        rc = ERR_IO;
        printf("a or b is not int!\n");
    }
    return rc;
}
