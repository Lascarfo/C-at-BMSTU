#include "const.h"
#include <stdio.h>

int read_params(FILE *file, int *rows, int *columns)
{
    if (fscanf(file, "%d %d", rows, columns) != 2)
    {
        return ERR_FILE;
    }
    if (*rows < 1 || *columns < 1)
    {
        return ERR_MATRIX;
    }
    return OK;
}

int read_matrix(FILE *file, double **matrix, const int rows, const int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (fscanf(file, "%lf", &matrix[row][column]) != 1)
            {
                return ERR_MATRIX;
            }
        }
    }
    return OK;
}



void print_matrix(double **matrix, const int rows, const int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            printf("%0.0lf ", matrix[row][column]);
        }
        printf("\n");
    }
}
