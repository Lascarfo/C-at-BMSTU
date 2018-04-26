#include <stdio.h>


#define RIGHT 0
#define ERR_LENGHT (RIGHT + 1)
#define ERR_INPUT (ERR_LENGHT + 1)
#define MAS 10


int elem(int mas[MAS], int *final, int lenght, int *number)
{
    int middle = 0, cache = 0;
    for (int i = 0; i < lenght; i++)
    {
        middle += mas[i];
    }
    middle /= lenght;
    for (int i = 0; i < lenght; i++)
    {
        if (mas[i] > middle)
        {
            final[cache] = mas[i];
            cache++;
        }
    }
    return cache;
}



int main(void)
{
    int err = RIGHT, cache = 0, count = 0, lenght = 0, number = 0;
    float trash = 0.0;
    printf("input linght of mass ot 0 to 10: ");
    scanf("%d", &lenght);
    if ((lenght < 0) && (lenght > 10))
        return ERR_LENGHT;
    int massiv[MAS] = {0}, final[MAS] = {0};
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
    lenght = elem(massiv, final, lenght, &number);
    for (int i = 0; i < lenght; i++)
        printf("%d ", final[i]);
    return err;
}

