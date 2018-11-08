/**
 \file
 */

#include <stdlib.h>

#include "memory.h"


/**
* \brief функция, освобождающая память, которая была заняюта матрицей
* \param matrix матрица для освобождения
* \param rows количество строк
*/

void free_mem(double **matrix, const int rows)
{
    free(matrix);
}

/**
* \brief эта функция выделяет память под матрицу
* \param rows количество строк
* \param columns количество столбцов
*/

double **allocate_memory(const int rows, const int columns)
{
    double **matrix = NULL;
    if (rows > 0 && columns > 0)
    {
        matrix = malloc(rows * sizeof(double*) + rows * columns * sizeof(double));
        if (matrix)
        {
            for (int index = 0; index < rows; index++)
            {
                matrix[index] = (double*)((char*) matrix + rows * sizeof(double*) + index * columns * sizeof(double));
            }
        }
    }
    return matrix;
}
