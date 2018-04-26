#include <stdio.h>


#define RIGHT 0
#define ERR_LENGHT (RIGHT + 1)
#define ERR_INPUT (ERR_LENGHT + 1)
#define MAS 10


int polin(int number)
{
   int reverse = 0, cache = 0, checker = 0;
   cache = number;
   while( cache != 0 )
   {
      reverse = reverse * 10;
      reverse = reverse + cache%10;
      cache = cache/10;
   }
   if ( number == reverse )
      checker = 1;
   else
      checker = 2;
   return checker;
}

void del(int *mas, int i)
{
    int pred = MAS;
    for (; i < pred - 1; i++)
    {
      mas[i] = mas[i+1];
      pred--;
    }
}

int main(void)
{
    int err = RIGHT, cache = 0, count = 0, lenght = 0, number = 0;
    float trash = 0.0;
    printf("input linght of mass ot 0 to 10: ");
    scanf("%d", &lenght);
    if ((lenght < 0) && (lenght > 10))
        return ERR_LENGHT;
    int mas[MAS] = {0};
    printf("Input int numbers (< 10), for stop input input STRING.\n");
    for (int i = 0; i < lenght; i++)
        if (scanf("%d", &cache) != 1)
        {
            printf("pls inp int numb!\n");
            err = ERR_INPUT;
            return err;
        }
        else
        {
            mas[i] = cache;
        }
    for (int i = 0; i < lenght; i++)
        if (polin(mas[i]) == 1)
            del(mas, i);
    for (int i = 0; i < lenght; i++)
        printf("%d ", mas[i]);
    return err;
}

