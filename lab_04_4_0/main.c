#include <stdio.h>
#include <stdbool.h>


#define RIGHT 0
#define COMPLETE 5
#define ERR_LENGTH (RIGHT + 1)
#define ERR_INPUT (ERR_LENGTH + 1)
#define MAS 10


int sortirovka(int *mass, int len)
{
    int fcache;
    bool flag;
    for (int i = len - 1; i >= 0; i--)
    {
        flag = true;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                fcache = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = fcache;
                flag = false;
            }
        }
        if (flag == true)
            return COMPLETE;
    }
    return RIGHT;
}

int inp(int *massiv, int *length)
{
    int err = RIGHT, cache = 0;
    printf("input length of mass ot 0 to 10: ");
    scanf("%d", length);
    if (((*length < 0) && (*length > 10)))
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
    int err = RIGHT, length = 0;
    int massiv[MAS];
    err = inp(massiv, &length);
    int check = sortirovka(massiv, length);
    if ((err == RIGHT) && (check == COMPLETE))
    {
        for (int i = 0; i < length; i++)
            printf("%d ", massiv[i]);
    }
    return err;
}

