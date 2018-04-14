#include<stdio.h>
#include<math.h>

#define RIGHT 0
#define ERR_TEST 25
#define ERR_OPEN_FILE 24
#define CHET 2
#define MIN -999999



int max_nechet(FILE *file, int *number)
{
    int err = ERR_TEST, cache = 0, flag = 0, max = 0, del = 0;
    while (fscanf(file, "%d", &cache) == 1)
    {
        if (flag == 0)
        {
            max = MIN;
            flag = 1;
        }
        del = cache % CHET;
        if (del != 0)
        {
            if (cache >= max)
            {
                *number = cache;
                err = RIGHT;
            }
        }
    }
    return err;
}


void usage(void)
{
    printf("Follow next steps:\nmain.exe <filename.txt>\n");
}

int main(int argc, char** argv)
{
    FILE *file;
    int number = 0, err = RIGHT;
    file = fopen(argv[1], "r");
    if (file)
    {
        err = max_nechet(file, &number);
        fclose(file);
        printf("Maxumum nechet number is %d", number);
    }
    else
    {
        err = ERR_OPEN_FILE;
        usage();
    }
    if (err == ERR_TEST)
    {
        printf("No request numbers in file\n");
        err = RIGHT;
    }
    return err;
}
