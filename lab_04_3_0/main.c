#include <stdio.h>
#include <stdbool.h>



#define RIGHT 0
#define ERR_LENGTH (RIGHT + 1)
#define ERR_INPUT (ERR_LENGTH + 1)
#define MAS 10


int polin(int number)
{
   int reverse = 0, cache = 0;
   bool checker = false;
   cache = number;
   while( cache != 0 )
   {
      reverse = reverse * 10;
      reverse = reverse + cache%10;
      cache = cache/10;
   }
   if ( number == reverse )
      checker = true;
   else
      checker = false;
   return checker;
}

void del(int *mas, int i, int length)
{
    int pred = length;
    for (; i < pred - 1; i++)
    {
      mas[i] = mas[i+1];
      pred--;
    }
}

int inp(int *massiv, int *length)
{
  int err = RIGHT, cache = 0;
  printf("input lingth of mass ot 0 to 10: ");
  scanf("%d", length);
  //if (((length < 0) && (*length > 10)))
  //    printf("pls inp int numb!\n");
  //    return ERR_LENGTH;
  printf("Input int numbers (< 10), for stop input input STRING.\n");
  for (int i = 0; i < *length; i++)
      if (scanf("%d", &cache) == 1)
      {
          massiv[i] = cache;
      }
      else
      {
          printf("pls inp int numb!\n");
          err = ERR_INPUT;
          return err;
      }
    return RIGHT;
}


int main(void)
{
    int err = RIGHT, length = 0;
    int massiv[MAS];
    err = inp(massiv, &length);
    for (int i = 0; i < length; i++)
        if (polin(massiv[i]) == true)
            del(massiv, i, length);
    for (int i = 0; i < length; i++)
        printf("%d ", massiv[i]);
    return err;
}

