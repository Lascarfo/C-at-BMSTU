#include <stdio.h>
#include <math.h>

#define OK 0
#define ERR_IO 1
#define ERR_RANGE 2
#define MINUS -1

float calc_s(float eps, float x)
{
   float changing_x = x;
   float sum = 0.0;
   while (fabs(changing_x) >= eps)
   {
       x *= x * x;
       sum += changing_x;
       changing_x = MINUS * (x / numer);
   }
   return sum;
}


int main(void)
{
    int rc = OK;
    float eps, x, s, f, abs_f, relative;

    printf("Input eps (0 < eps <= 1) && x (|x| <= 1): ");
    if (scanf("%f%f", &eps, &x) == 2)
    {
        if ((eps > 0) && (eps <= 1) && (fabs(x) <= 1))
        {
            f = atan(x);
            s = calc_s(eps, x);
            abs_f = fabs(f - s);
            relative = abs_f / fabs(f);
            printf("s(x) = %f\nf(x) = %f\n", s, f);
            printf("abs, relative: %f, %f\n", abs_f, relative);
        }
        else
        {
            rc = ERR_RANGE;
            printf("required next conditions: 0 < eps <= 1, |x| <= 1 \n");
        }
    }
    else
    {
        printf("Incorrect type of value\n");
        rc = ERR_IO;
    }
    return rc;
}
