
/*
Вычисляет сумму площадь прямоугольника и круга.
*/
#include <stdio.h>
#define PI 3.14

float rectangle(float a, float b)
{
  float sr;
  sr = a * b;
  return(sr);
}

float circle(float r)
{
  float sc;
  sc = PI * r * r;
  return(sc);
}

int main(void)
{

 float sr, sc, a, b, r, s;
 printf("Input r: ");
 scanf("%f",&r);
 printf("Input a and b: ");
 scanf("%f %f",&a, &b);
 sc = circle(r);
 sr = rectangle(a, b);
 s = sc + sr;
 printf("Square of circle plus rectangle is %8.3f\n", s);
return 0;
}
