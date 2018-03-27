#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define FULLANGLE 180.0

int main()
{
    setbuf(stdout, NULL);
    float down, upper, ang, plos, radians;
    printf("Down side: ");
    scanf("%f", &down);
    printf("Upper side: ");
    scanf("%f", &upper);
    printf("Angular: ");
    scanf("%f", &ang);
    radians = (ang * PI) / FULLANGLE;
    plos = fabs(0.5 * (down + upper)* tan(radians));
    printf("S = %.4f", plos);
}
