#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define FULLANGLE 180

int main(void)
{
    int ang;
    float down, upper, plos, radians;
    printf("Down side, upper side, angular: ");
    scanf("%f %f %d", &down, &upper, &ang);
    radians = 0.5 * (down - upper) * tan((ang * PI) / FULLANGLE);
    plos = fabs(((down + upper) * tan(radians)) / 2);
    printf("S = %.4f\n", plos);
}
