#include <stdio.h>
#include <stdbool.h>


#define RIGHT 0
#define ERR_LENGHT (RIGHT + 1)
#define ERR_INPUT (ERR_LENGHT + 1)
#define MAS 10


void sortir(int *mass, int len)
{
    int fcache;
    bool flag;
    for (int i = len - 1; i >= 0; i--)
    {
        flag = 1;
        for (int j = 0; j < i; j++)
        {
            if (mass[j] > mass[j + 1])
            {
                fcache = mass[j];
                mass[j] = mass[j + 1];
                mass[j + 1] = fcache;
                flag = 0;
            }
        }
        if (flag == 1)
            break;
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
    sortir(mas, lenght);
    for (int i = 0; i < lenght; i++)
        printf("%d ", mas[i]);
    return err;
}

