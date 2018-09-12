#include <stdio.h>

void printar(int *ar, int *len)
{
  printf("Array from file: ");
  for (int i = 0; i < *len; i++)
  {
    printf("%d ", *ar);
    ar++;
  }
  printf("\n");
}
