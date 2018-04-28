#include <stdio.h>
#include <math.h>
#include <errno.h>
#include <string.h>

#define RIGHT 0
#define ERR_INP (RIGHT + 1)
#define ERR_IN_FILE (ERR_INP + 1)
#define ERR_OPEN (ERR_IN_FILE + 1)

int mid(FILE* file, float *cached_num, float *semi_num)
{
    float data_cache = 0.0, sum = 0.0, count = 0.0;
    while (fscanf(file, "%f", &data_cache) == 1)
    {
        count++;
        sum += data_cache;
        if (data_cache > *cached_num)
        {
            *cached_num = data_cache;
        }
    }
    *semi_num = sum / count;
    return count;
}

void sear (FILE *file, float *number, float cached_num, float count, float semi_num)
{
    float pre_cached_num = 0.0, data_cache = 0.0;
    fseek(file, 0, 0);
    for (int i = 0; i < count; i++)
    {
        fscanf(file, "%f", &data_cache);
        pre_cached_num = fabs(semi_num - data_cache);
        if (pre_cached_num < cached_num)
        {
            cached_num = pre_cached_num;
            *number = data_cache;
        }
    }
}


int search(FILE *file, float *number, float *cached_num)
{
    float count = 0.0, semi_num = 0.0;
    count = mid(file, cached_num, &semi_num);
    if (count == 0)
        return ERR_IN_FILE;
    else
    {
        sear (file, number, *cached_num, count, semi_num);
        return RIGHT;
    }
}

int main(int argc, char **argv)
{
    int err = RIGHT;
    float number = 0.0, cached_num;
    FILE *file;

    if (argc == 2)
    {
        file = fopen(argv[1], "r");
        if (file)
        {
            err = search(file, &number, &cached_num);
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
        printf("The number: %.4f\n", number);
    return err;
}
