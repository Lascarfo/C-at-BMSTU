#include <stdio.h>


void findnum(int *ar, int *len)
{
  int num = -1, cache = 1;
  for (int i = 0; i < *len; i++)
  {
    cache = *ar;
    if (cache < 0)
    {
      printf("\nResault: %d\n", *(ar + sizeof(int)));
      break;
    }
    ar = ar + sizeof(int);
  }
}
