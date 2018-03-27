#include <stdio.h>
#include <math.h>

#define PI 3.14
#define ANGULAR 0.01745329251

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
    plos = 0.5 * (down + upper) * tan(ang * ANGULAR);
    printf("S = %.4f", plos);
}
