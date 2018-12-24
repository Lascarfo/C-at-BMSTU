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

// void free_mem(double **matrix, const int rows)
// {
//     free(matrix);
// }


void free_mem(double **matrix, const int rows)
{
    for (int row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}


/**
* \brief эта функция выделяет память под матрицу
* \param rows количество строк
* \param columns количество столбцов
*/

// double **allocate_memory(const int rows, const int columns)
// {
//     double **matrix = NULL;
//     if (rows > 0 && columns > 0)
//     {
//         matrix = malloc(rows * sizeof(double*) + rows * columns * sizeof(double));
//         if (matrix)
//         {
//             for (int index = 0; index < rows; index++)
//             {
//                 matrix[index] = (double*)((char*) matrix + rows * sizeof(double*) + index * columns * sizeof(double));
//             }
//         }
//     }
//     return matrix;
// }



double **allocate_memory(const int rows, const int columns)
{
    double **matrix = NULL;
    if (rows > 0 && columns > 0)
    {
        matrix = calloc(rows, sizeof(double *));
        if (matrix == NULL)
        {
            return NULL;
        }
        for (int row = 0; row < rows; row++)
        {
            matrix[row] = malloc(columns * sizeof(double));
            if (matrix[row] == NULL)
            {
                free_mem(matrix, rows);
                return NULL;
            }
        }
    }
    return matrix;
}
