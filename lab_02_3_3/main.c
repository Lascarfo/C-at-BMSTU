#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE ERR_IO + 1
#define MINUS -1

float calc_s(float eps, float x)
{
    float changing_x = x;
    float sum = 0.0;
    float number = 1.0;
    while (fabs(changing_x) > eps)
    {
        sum += changing_x;
        number += 2;
        changing_x *= MINUS * (number - 2) * x * x / number;
    }
    return sum;
}


int main(void)
{
    int rc = OK;
    float eps, x, s, f, abs_f, relative;
    if (scanf("%f%*c%f", &x, &eps) == 2)
    {
        if ((eps > 0) && (eps < 1) && (fabs(x) <= 1) && (x != 0))
        {
            f = atan(x);
            s = calc_s(eps, x);
            abs_f = fabs(f - s);
            relative = fabs((f - s) / f);
            printf("%f%f%f%f", s, f, abs_f, relative);
        }
        else
        {
            rc = ERR_RANGE;
        }
    }
    else
    {
        rc = ERR_IO;
    }
    return rc;
}
