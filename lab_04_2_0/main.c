#include <stdio.h>


#define RIGHT 0
#define ERR_LENGTH (RIGHT + 1)
#define ERR_INPUT (ERR_LENGTH + 1)
#define MAS 10

int mid(int const mas[MAS], int length)
{
    int middle = 0;
    for (int i = 0; i < length; i++)
    {
        middle += mas[i];
    }
    middle /= length;
    return middle;
}

int elem(int const mas[MAS], int *final, int length, int *number)
{
    int cache = 0;
    int middle = mid(mas, length);
    for (int i = 0; i < length; i++)
    {
        if (mas[i] > middle)
        {
            final[cache] = mas[i];
            cache++;
        }
    }
    return cache;
}

int inp(int *massiv, int *length)
{
    int err = RIGHT, cache = 0;
    printf("input lingth of mass ot 0 to 10: ");
    if (scanf("%d", length) != 1)
        return ERR_INPUT;
    if ((*length < 0) || (*length > 10))
    {
        printf("pls inp int numb!\n");
        return ERR_LENGTH;
    }
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
    int err = RIGHT, length = 0, number = 0;
    int massiv[MAS], final[MAS];
    err = inp(massiv, &length);
    length = elem(massiv, final, length, &number);
    for (int i = 0; i < length; i++)
        printf("%d ", final[i]);
    return err;
}

