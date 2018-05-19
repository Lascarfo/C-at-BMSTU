#include <stdio.h>
#include "err_lib.h"
#include "read_f.h"
#include "pick_f.h"

void usage(void)
{
    fprintf(stdout, "For next time please follow next steps:\n./main.exe file1.txt file2.txt\n");
}


int main(int argc, char **argv)
{
    int rc = RIGHT, number = 0;
    FILE *file1;
    FILE *file2;
    if (argc == 3)
    {
        file1 = fopen(argv[1], "r");
        file2 = fopen(argv[2], "r");
        if (file1 && file2)
        {
            int n1, n2;
            fscanf(file1, "%d", &n1);
            fscanf(file2, "%d", &n2);
            int x[n1], y[n2];
            printf("n1, n2: %d, %d\n", n1, n2);
            read(x, y, file1, file2);
            printf("x, y: %d, %d\n", *x, *y);
            pick(x, y, &number, n1, n2);
            printf("fin number %d", number);
        }
        else
        {
            fprintf(stdout, "err open file(s)\n");
            usage();
            return ERR_FILE;
        }

    }
    else
    {
        rc = ERR_FILE;
        usage();
    }
    return rc;
}
