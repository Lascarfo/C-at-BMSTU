#include <stdio.h>

#define ZERO 0
#define NOTHING_INPUT -1
#define NOTHING_BEFORE_MINUS -2


int process(FILE *f, int count)
{
    if (count == 0)
        return NOTHING_INPUT;
    else
    {
        int max_num = -1;
        int cachedd = 0;
        for (int i = 0; i < count; i++)
        {
            fscanf(f, "%d ", &cachedd);
            if (cachedd < ZERO)
            {
                max_num = NOTHING_BEFORE_MINUS;
            }
            if (cachedd > max_num)
            {
                max_num = cachedd;
            }
        }
        return max_num;

     }
}

int main(void)
{
    int number = 0, count = 0;
    int new;
    new = 0;
    new ++;
    FILE *f = fopen("text.txt", "w");

    printf("input numbers (CTRL+Z + ENTER or LITERAL for cancel): ");
    while (scanf("%d", &number) == 1)
    {
            fprintf(f, "%d ", number);
            count++;
     }
    fclose(f);
    FILE *e = fopen("text.txt", "r");
    new = process(e, count);

    printf("maximum chislo above (or error code (-1, -2)): %d", new);
    fclose(e);

}
