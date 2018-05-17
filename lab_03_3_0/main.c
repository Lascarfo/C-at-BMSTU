/*
Яроцкий Д.Д.
Программа используюет целочисленный тип (integer)
Алгоритм сортировки - пузырьком.
* please following next input rules:
* main.exec <filename> <option>
* list of options:
* c - create file
* p - read file and print numbers
* s - sort numbers
*/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define RIGHT 0
#define ERR_INPUT (RIGHT + 1)
#define ERR_FILE (ERR_INPUT + 1)
#define N 1000


int get_number_by_pos(FILE *file, int pos)
{
    int number = 0;
    fseek(file, pos * sizeof(int), SEEK_SET);
    fread(&number, sizeof(int), 1, file);
    return number;
}

void put_number_by_pos(FILE *file, int value, int pos)
{
    fseek(file, pos * sizeof(int), SEEK_SET);
    fwrite(&value, sizeof(int), 1, file);
}



void usage(void)
{
    printf("please following next input rules:\nmain.exec <filename> <option>\nlist of options:\nc - create file\np - read file and print numbers\ns - sort numbers");
}


void reading(FILE *file)
{
    int cache = 0;
    while (fread(&cache, sizeof(int), 1, file) == 1)
        fprintf(stdout,"%d ", cache);
}

int randomize(FILE *file)
{
    int number = -1, cache = 0;
    printf("Input number of random numbers: ");
    if (scanf("%d", &number) != ERR_INPUT)
        return ERR_INPUT;
    for (int i = 0; i < number; i++)
    {
        cache = rand() % N;
//      printf("cache is %d\n", cache);
        fwrite(&cache, sizeof(int), 1, file);
    }
    return RIGHT;
}


int pick(FILE *file)
{
    fseek(file, sizeof(int), SEEK_END);
    int len = ((ftell(file) / sizeof(int)) - 1);
    int fcache1, fcache2;
    bool flag;
    for (int i = len - 1; i >= 0; i--)
    {
        flag = true;
        for (int j = 0; j < i; j++)
        {
            if (get_number_by_pos(file, j) > get_number_by_pos(file, (j + 1)))
            {
                fcache1 = get_number_by_pos(file, j);
                fcache2 = get_number_by_pos(file, (j + 1));
//              printf ("caches: %d %d\n",fcache1, fcache2);
                put_number_by_pos(file, fcache1, (j + 1));
                put_number_by_pos(file, fcache2, j);
                flag = false;
            }
        }
        if (flag == true)
            return RIGHT;
    }
    return RIGHT;
}



int main(int argc, char **kvargs)
{
    setbuf(stdout, NULL);
    srand(time(NULL));
    int err = RIGHT;
    FILE *file;
    if (argc == 3)
    {
        if (strcmp(kvargs [2], "c") == 0)
        {
            file = fopen(kvargs[1],"wb");
            err = randomize(file);
            fclose(file);
        }
        else if (strcmp(kvargs [2], "p") == 0)
        {
            file = fopen(kvargs[1],"rb");
            if (file)
            {
                reading(file);
                fclose(file);
            }
            else
            {
                usage();
                err = ERR_FILE;
            }

        }
        else if (strcmp(kvargs [2], "s") == 0)
        {
            file = fopen(kvargs[1],"r+b");
            if (file)
            {
                err = pick(file);
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
