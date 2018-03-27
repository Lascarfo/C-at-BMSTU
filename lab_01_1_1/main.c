#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define FULLANGLE 180.0

int main(void)
{
    float down, upper, plos, height, ang;
    printf("Down side, upper side, angular: ");
    scanf("%f %f %f", &down, &upper, &ang);
    height = 0.5 * fabs(down - upper) * tan((ang * PI) / FULLANGLE);
    plos = 0.5 * (down + upper) * height;
    printf("S = %.4f\n", plos);
}
