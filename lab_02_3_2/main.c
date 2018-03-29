#include <stdio.h>

#define OK 0
#define ERR_DIG 1

void line(x, x1, x2, y, y1, y2)
{
    if (((y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1)) == 0)
        printf ("Point is on the line\n");
    if (((y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1)) > 0)
        printf("Point is higher than line\n");
    if (((y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1)) < 0)
        printf("Point is lower than line\n");
}

int main(void)
{
    int rc = OK;
    float x, x1, x2, y, y1, y2;
    printf("input x, y of point and x1, y1, x2, y2 of line:");
    if (scanf("%f %f %f %f %f %f", &x, &y, &x1, &y1, &x2, &y2) == 6)
    {
        line(x, x1, x2, y, y1, y2);
    }
    else
    {
     printf("x, x1, x2, y, y1, y2 must be a float or int!\n");
     rc = ERR_DIG;
    }
}
