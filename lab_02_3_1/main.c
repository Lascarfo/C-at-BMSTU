#include <stdio.h>
#include <ctype.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2

int largest_common_divisor(int a, int b)
{
    while (a > 0 && b > 0)
        if (a > b)
            a %= b;
        else
            b %= a;
    return a + b;
}

int main(void)
{
    int a, b, rc = OK;
    if (scanf("%d %d", &a, &b) == 2)
    {
        if (a > 0 && b > 0)
        {
            printf("%d", largest_common_divisor(a, b));
        }
        else
        {
            rc = ERR_RANGE;
        }
    }
    else
        rc = ERR_IO;
    return rc;
}
