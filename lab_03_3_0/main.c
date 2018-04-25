/*
Программа используюет целочисленный тип (integer)
Алгоритм сортировки -
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#define RIGHT 0
#define ERR_INPUT (RIGHT + 1)
#define ERR_FILE (ERR_INPUT + 1)
#define TIS 1000

void usage(void)
{
    printf("please following next input rules:\nmain.exec <filename> <option>\nlist of options:\ncf - create file\nrf - read file and print numbers\nsn - sort numbers");
}

void randomize(FILE *file)
{
    int number = -1, cache = 0;
    printf("Input number of random numbers: ");
    scanf("%d", &number);
    srand(time(NULL));
    for (int i = 0; i < number; i++)
    {
        cache = rand() % TIS;
        printf("cache is %d\n", cache);
        fwrite(&cache, sizeof(int), 1, file);
    }


}
void sortir(FILE *file)
{
    int n, i, j;
    int cache = 0, counter = 0;
    while (fread(&cache, sizeof(int), 1, file) == 1)
        counter++;
    int massiv[counter];
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < counter; i++)
    {
        fread(&cache, sizeof(int), 1, file);
        massiv[i] = cache;
    }
    for(i = 0 ; i < counter; i++)
    {
           for(j = 0 ; j < counter - i - 1 ; j++)
           {
               if(massiv[j] > massiv[j+1])
               {
                  int tmp = massiv[j];
                  massiv[j] = massiv[j+1] ;
                  massiv[j+1] = tmp;
                }
            }
     for (i = 0 ; i < counter; i++)
         printf("%d\n", massiv[i]);
     }
}

int get_number_by_pos(FILE *file, int pos)
{


}

void put_number_by_pos(FILE *file, int value, int pos)
{

}

int main(int argc, char **kvargs)
{
    setbuf(stdout, NULL);
    int err = RIGHT, flag = 0;
    float new = 0.0;
    FILE *file;
    if (argc == 3)
    {
        if (strcmp(kvargs [2], "cf") == 0)
        {
            file = fopen(kvargs[1],"wb");
            randomize(file);
            fclose(file);
        }
        else if (strcmp(kvargs [2], "rf") == 0)
        {
            file = fopen(kvargs[1],"rb");
            if (file)
            {
                int cache = 0;
                while (fread(&cache, sizeof(int), 1, file) == 1)
                    fprintf(stdout,"%d ", cache);

            }
            else
            {
                usage();
                err = ERR_FILE;
            }

        }
        else if (strcmp(kvargs [2], "sn") == 0)
        {
            file = fopen(kvargs[1],"r+b");
            if (file)
            {
                sortir(file);
                fclose(file);
            }
            else
            {
                err = ERR_FILE;
                printf("could not open file!\n");
                usage();
            }

        }
        else
        {
            usage();
            err = ERR_INPUT;
        }
    }
    else
    {
        usage();
        err = ERR_FILE;
    }
    return err;

}
