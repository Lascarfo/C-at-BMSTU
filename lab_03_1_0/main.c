#include <stdio.h>

#define ERR_MAIN -1

int maximum(int *rc, int *number)
{
    int reedu, cachedd = 0, flag = 0;
    fscanf(stdin, "%d", &cachedd);
    while (fscanf(stdin, "%d", &reedu) == 1)
    {
        cachedd++;
        if (flag == 1)
            if (*number < reedu)
                *number = reedu;
        if (reedu < 0)
        {
            flag += 1;
        }
    }
    if ((cachedd == 0) || (*number == -1))
        *rc = ERR_MAIN;
    return *rc;
}

void usage(void)
{
    printf("Another time please input integers and negative number. For stop input string.");
}

int main(void)
{
    int number = -1, rc = 0;
    printf("input numbers (CTRL+Z + ENTER or LITERAL for cancel): ");
    rc = maximum(&rc, &number);
    if (rc != 0)
        usage();
    else
        fprintf(stdout, "max number before negative is %d", number);
    return rc;
}
