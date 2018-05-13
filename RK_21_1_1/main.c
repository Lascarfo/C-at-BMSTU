#include<stdio.h>

#define RIGHT 0
#define ERR_INPUT (RIGHT + 1)
#define TEN 10

int shet(int number,int *res)
{
    int err = RIGHT, cache = 0, first_max, first_min, flag = 0;
    if (number != 0)
    {
        while (number != 0)
        {
            cache = number % TEN;
            if (flag == 0)
            {
                first_max = cache;
                first_min = cache;
                flag = 1;
            }
            if (cache < first_min)
            {
                first_min = cache;
            }
            if (cache > first_max)
            {
                first_max = cache;
            }
            number = number / TEN;
        }
        if (flag == 1)
        {
            *res = first_max - first_min;
        }
        else
        {
            err = ERR_INPUT;
        }
    }
    else
    {
        err = ERR_INPUT;
    }
    return err;
}


int main(void)
{
    setbuf(stdout, NULL);
    int err = RIGHT, number = 0, res = 0;
    printf("Input number: ");
    if ((scanf("%d", &number) == 1) && (number > 0))
    {
        err = shet(number, &res);
        if (err == RIGHT)
        {
            printf ("resault is %d", res);
        }
    }
    else
    {
        printf("Please input natural number!\n");
        err = ERR_INPUT;
    }

    return err;
}
