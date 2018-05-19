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
        if (file1)
        {
            if (fscanf(file1, "%d", &cache) != 1)
            {
                fprintf(stdout, "no such numbers in file1");
                return ERR_FILE;
            }
            else
            {
                if (cache > 0)
                {

                }
                else
                {
                    fprintf(stdout, "len < 1");
                    return ERR_FILE;
                }
            }
        }
        else
        {
            fprintf(stdout, "Cannot open file 1");
            return ERR_FILE;
        }
        if (file2)
        {
            if (fscanf(file2, "%d", &cache) != 1)
            {
                fprintf(stdout, "no such numbers in file2");
                return ERR_FILE;
            }
            else
            {
                if (cache > 0)
                {

                }
                else
                {
                    fprintf(stdout, "len < 1");
                    return ERR_FILE;
                }
            }
        }
        else
        {
            fprintf(stdout, "Cannot open file 2");
            return ERR_FILE;
        }

    }
    {                                                   //test func pick_f

    }
    return RIGHT;
}
