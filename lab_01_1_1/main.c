#include <stdio.h>
#include <math.h>

#define PI 3.14159265359
#define FULLANGLE 180.0

int main()
{
    setbuf(stdout, NULL);
    float down, upper, ang, plos, radians;
    printf("Down side, upper side, angular: ");
    scanf("%f %f %f", &down, &upper, &ang);
    radians = (ang * PI) / FULLANGLE;
    plos = fabs(((down + upper) * tan(radians)) / 2);
    printf("S = %.4f", plos);
}
