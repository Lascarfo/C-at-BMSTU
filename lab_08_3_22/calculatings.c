#include <stdbool.h>


#include "calculatings.h"


void zero_filling(double **matrix, const int rows, const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
             matrix[i][j] = 0;
//             printf("matrix %lf\n", matrix[i][j]);
        }
    }
}

int addition(FILE *file_in_1, FILE *file_in_2)
{
    return OK;
}

int multiplication(FILE *file_in_1, FILE *file_in_2)
{
    return OK;
}

int char_to_int(char num)
{
    return num - '0';
}

bool counter_params(FILE *in)
{
    char symbol = '\0';
    int count = 0;
    while (count < 3)
    {
        fscanf(in, "%c ", &symbol);
        if (symbol == '\n')
        {
            break;
        }
        if (!isdigit(symbol))
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


double **allocate_memory(const int rows, const int columns)
{
    double **matrix = malloc(rows * sizeof(double*) + rows * columns * sizeof(double));
    if (matrix)
    {
        for (int index = 0; index < rows; index++)
        {
            matrix[index] = (double*)((char*) matrix + rows * sizeof(double*) + index * columns * sizeof(double));
        }
    }
    return matrix;
}
