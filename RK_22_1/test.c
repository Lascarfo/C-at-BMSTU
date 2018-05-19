#include <stdio.h>
#include "err_lib.h"
#include "read_f.h"
#include "pick_f.h"

int main(void)
{
    {                                               //test func read_f
        FILE *file1;
        FILE *file2;
        int cache = 0;
        file1 = fopen ("file1.txt", "r");
        file2 = fopen ("file2.txt", "r");
        if (file1)
        {
            if (fscanf(file1, "%d", &cache) != 1)
            {
                fprintf(stdout, "no such numbers in file1\n");
                return ERR_FILE;
            }
            else
            {
                if (cache > 0)
                {
                }
                else
                {
                    fprintf(stdout, "len < 1\n");
                    return ERR_FILE;
                }
            }
        }
        else
        {
            fprintf(stdout, "Cannot open file 1\n");
            return ERR_FILE;
        }
        if (file2)
        {
            if (fscanf(file2, "%d", &cache) != 1)
            {
                fprintf(stdout, "no such numbers in file2\n");
                return ERR_FILE;
            }
            else
            {
                if (cache > 0)
                {
                    fprintf(stdout, "All test with files are ok!\n");
                }
                else
                {
                    fprintf(stdout, "len < 1\n");
                    return ERR_FILE;
                }
            }
        }
        else
        {
            fprintf(stdout, "Cannot open file 2\n");
            return ERR_FILE;
        }

    }
    {
        int number = 0;                                                    //test func pick_f
        int x[] = {1, 2, 8, 5, 0, 2, 9, 0, 5};
        int y[] = {3, -4, 0, 7, 2};
        int n1 = 9, n2 = 5;
        pick(x, y, &number, n1, n2);
        if (number == RIGHT)
        {
            fprintf(stdout, "pick_f test are ok!\n");
        }
        else
        {
            fprintf(stdout, "pick_f test are not ok!\n");
            return ERR_ARR;
        }
    }
    return RIGHT;
}
