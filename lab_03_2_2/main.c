#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>

#define RIGHT 0
#define ERR_INP (RIGHT + 1)
#define ERR_IN_FILE (ERR_INP + 1)
#define ERR_OPEN (ERR_IN_FILE + 1)

int mid(FILE* file, float *semi_num)
{
    float data_cache = 0.0, sum = 0.0, count = 0.0;
    while (fscanf(file, "%f", &data_cache) == 1)
    {
        count++;
        sum += data_cache;
    }
    if (count != RIGHT)
        *semi_num = sum / count;
    return count;
}

void dispers(FILE* file, float semi_num, float *number)
{
    for (int i = 0; i < (int)(semi_num); i++)
    {
        *number += (i * i) * 2;
    }
    float cache = (semi_num * 2) - 1;
    *number = *number / cache;
}

int search(FILE* file, float *number)
{
    int rc = RIGHT;
    float count = 0.0, semi_num = 0.0;
    count = mid(file, &semi_num);
    if (count == 0)
        return ERR_IN_FILE;
    else
    {
        dispers(file, semi_num, number);
        rc = RIGHT;
    }
    return rc;
}

int main(int argc, char **argv)
{
    int err = RIGHT;
    float number = 0.0;
    FILE* file;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (file)
        {
            err = search(file, &number);
            fclose(file);
        }
        else
        {
            fprintf(stderr,"Cannot open %s file because next err: %s\n", argv[1], strerror(errno));
            err = ERR_OPEN;
        }
    }
    else
    {
        fprintf(stdout, "input format:\nmain.exe <filename.txt>\n");
        err = ERR_INP;
    }
    if (err == RIGHT)
        printf("The dispersion number: %.4f\n", number);
    return err;
}



