#include <stdio.h>
#include <math.h>

#define PI 3.14

int main()
{
    setbuf(stdout, NULL);
    float down, upper, ang, plos;
    printf("Down side: ");
    scanf("%f", &down);
    printf("Upper side: ");
    scanf("%f", &upper);
    printf("Angular: ");
    scanf("%f", &ang);
    plos = fabs(0.5 * (down * down - upper * upper) * tan((ang * PI) / 180));
    printf("S = %.4f", plos);
}
