#include <stdio.h>


#define RIGHT 0
#define ERR_LENGTH (RIGHT + 1)
#define ERR_INPUT (ERR_LENGTH + 1)
#define MAS 10


int counter(int const mas[MAS],int length, int *number)
{
    int err = RIGHT;
    for (int i = 0; i < length; i++)
    {
        if ((mas[i] % 2) == 0)
        {
            *number += mas[i];
        }
    }
    return err;
}

int inp(int *massiv, int *length)
{
    int err = RIGHT, cache = 0;
    printf("input lingth of mass ot 0 to 10: ");
    scanf("%d", length);
    if (((*length < 0) && (*length > 10)) == 0)
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
    int massiv[MAS];
    err = inp(massiv, &length);
    if (err == 0)
        err = counter(massiv, length, &number);
    if (err == 0)
        printf("%d", number);
    return err;
}
