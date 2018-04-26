#include <stdio.h>


#define RIGHT 0
#define ERR_LENGHT (RIGHT + 1)
#define ERR_INPUT (ERR_LENGHT + 1)
#define MAS 10


int counter(int mas[MAS],int lenght, int *number)
{
    int err = RIGHT;
    for (int i = 0; i < lenght; i++)
    {
        if ((mas[i] % 2) == 0)
            *number += mas[i];
    }
    return err;
}



int main(void)
{
    int err = RIGHT, cache = 0, count = 0, lenght = 0, number = 0;
    float trash = 0.0;
    printf("input linght of mass ot 0 to 10: ");
    scanf("%d", &lenght);
    if ((lenght < 0) && (lenght > 10))
        return ERR_LENGHT;
    int massiv[MAS] = {0};
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
            massiv[i] = cache;
        }
    err = counter(massiv, lenght, &number);
    if (err == 0)
        printf("summ is %d\n", number);
    return err;
}

