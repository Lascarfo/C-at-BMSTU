#include <stdio.h>

#define HL 0
#define ERR_DIG -1
#define OL HL + 1
#define DL OL + 1

int line(float x, float x1, float x2, float y, float y1, float y2)
{
    int rcc;
    if (((y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1)) == 0)
        rcc = OL;
    if (((y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1)) > 0)
        rcc = HL;
    if (((y1 - y2) * x + (x2 - x1) * y + (x1 * y2 - x2 * y1)) < 0)
        rcc = DL;
    return rcc;

}

int main(void)
{
    int rc;
    float x, x1, x2, y, y1, y2;
    if (scanf("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &x, &y) == 6)
    {
      rc = line(x, x1, x2, y, y1, y2);
    }
    else
    {
     rc = ERR_DIG;
    }
    return rc;
}
