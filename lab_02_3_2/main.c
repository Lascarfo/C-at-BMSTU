#include <stdio.h>
#include <math.h>

#define HL 0
#define ERR_DIG 5
#define OL (HL + 1)
#define DL (OL + 1)
#define EPS 1e-6f

int line(float x, float x1, float x2, float y, float y1, float y2)
{
    int rcc = ((y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1));
    if (rcc == 0)
        rcc = OL;
    else if (rcc > 0)
        rcc = HL;
    else if (rcc < 0)
        rcc = DL;
    return rcc;
}

int main(void)
{
    int rc = HL;
    float x, x1, x2, y, y1, y2;
    if (scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x, &y) == 6)   
    {
        if ((fabs(x1 - x2) <= EPS) && (fabs(y1 - y2) <= EPS))
        {
            rc = ERR_DIG;
        }
        else
        {
            printf("%d", line(x, x1, x2, y, y1, y2));
        }
    }
    else
    {
        rc = ERR_DIG;
    }
    return rc;
}
