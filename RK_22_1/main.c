#include <stdio.h>
#include "err_lib.h"
#include "read_f.h"
#include "pick_f.h"

void usage(void)
{
    fprintf(stdout, "For next time please follow next steps:\n./main.exe file1.txt file2.txt\n");
}


int main(int argc, char **argv[])
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
            int n1, n2, n3;
            fscanf(file1, "%d", &n1);
            fscanf(file2, "%d", &n2);
            if (n1 > n2)
                n3 = n1;
            else
                n3 = n2;
            int x[n1], y[n2], z[n3];
            read(x[n1], y[n2], file1, file2);
            pick(x[n1], y[n2], z[n3], &number);
        }
        else
        {
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
