#include <stdlib.h>

#include "memory.h"

double **allocate_matrix(const int rows, const int columns)
{
    double **matrix = NULL;
    matrix = malloc(rows  * sizeof(double*));
    if (matrix == NULL)
    {
        return NULL;
    }
    else
    {
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = calloc(columns, sizeof(double));
        }
    }
    return matrix;

}

void free_mem(double **matrix, const int rows)
{
    for (int row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}
