#include "io.h"
#include "const.h"
#include "calculatings.h"


void read_params(FILE *in, int *rows, int *columns, int *positive_elements)
{
    rewind(in);
    char symbol;
    int params[] = {0};
    int index = 0;
    while (symbol != '\n')
    {
        fscanf(file, "%c", &symbol)
        if isdigit(symbol)
        {
            params[index++] = char_to_int(symbol);
        }
    }
    *rows = params[0];
    *columns = params[1];
    *positive_elements = params[2];
}


int arithmetic(char **argv)
{
    FILE *file_in_1;
    FILE *file_in_2;
    FILE *file_out;
    file_in_1 = fopen(argv[2], "r");
    if (file_in_1)
    {
        file_in_2 = fopen(argv[3], "r");
        if (file_in_2)
        {
            file_out = fopen(argv[4], "w");
            if (file_out)
            {

            }
            else
            {
                printf("error open file_out for write\nplease input ./app.exe h\nfor help\n");
                return ERR_FILE;
            }
        }
        else
        {
            printf("error open file_in_2 for read\nplease input ./app.exe h\nfor help\n");
            return ERR_FILE;
        }
    }
    else
    {
        printf("error open file_in_1 for read\nplease input ./app.exe h\nfor help\n");
        return ERR_FILE;
    }
    return OK;
}


int read_matrix(FILE *in, double *matrix[])
{
    if (counter_params(in))
    {
        int rows, columns, positive_elements;
        read_params(in, &rows, &columns, &positive_elements);
        if (rows > 0 && columns > 0)
        {

        }
        else
        {
            return ERR_INPUT;
        }

    }
    else
    {
        return ERR_INPUT;
    }

    return OK;
}


void print_matrix(double *matrix[]);
