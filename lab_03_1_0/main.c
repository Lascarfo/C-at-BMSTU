#include <stdio.h>

#define RIGHT 0
#define ERR_MAIN 1

int maximum(int *number)
{
    int rc = RIGHT, reedu = 0, cachedd = 0, flag = 0, flag1 = 0;
    while (fscanf(stdin, "%d", &reedu) == 1)
    {
        cachedd++;
        if (flag == 1)
        {
            if (flag1 == 0)
            {
                *number = reedu;
                flag1 = 1;
                flag = 0;
            }
            else if (reedu > *number)
            {
                *number = reedu;
                flag = 0;
            }
        }
        if (reedu < 0)
        {
            flag = 1;
        }
    }
    if ((cachedd == 0) || (*number == -1))
        rc = ERR_MAIN;
    return rc;
}

void usage(void)
{
    printf("Another time please input integers and negative number. For stop input string.");
}

int main(void)
{
    int number = -1, rc = RIGHT;
    printf("input numbers (LITERAL for cancel): ");
    rc = maximum(&number);
    if (rc != 0)
        usage();
    else
        fprintf(stdout, "max number before negative is %d", number);
    return rc;
}
