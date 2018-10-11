#include "const.h"
#include "usage.h"





int addition(FILE *file_in_1, FILE *file_in_2)
{
    return OK;
}

int multiplication(FILE *file_in_1, FILE *file_in_2);
{
    return OK;
}

int char_to_int(char num)
{
    return num - '0';
}

bool counter_params(FILE *in)
{
    char symbol;
    int count = 0;
    while (symbol != '\n')
    {
        fscanf(file, "%c", &symbol)
        if !isdigit(symbol)
        {
            return false;
        }
        else
        {
            count++;
        }
    }
    if (count != 3)
    {
        return false;
    }
    return true;
}
