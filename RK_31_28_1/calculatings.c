#include <stdlib.h>
#include <stdio.h>

#include "calculatings.h"



bool cmpr_rows(double *row1, double *row2, const int columns)
{
    double temp = 0.0;

    for (int column = 0; column < columns; column++)
    {
        temp += row1[column];
        temp -= row2[column];
    }
    if (temp > 0)
    {
        return true;
    }
    return false;

}

void sort_matrix(double **matrix, const int rows, const int columns)
{
    bool flag = true;
    double *temp = NULL;
    if (rows > 1)
    {
        while (flag)
        {
            flag = false;
            for (int row = 0; row < rows - 1; row++)
            {
                if (cmpr_rows(matrix[row], matrix[row + 1], columns))
                {
                    temp = matrix[row];
                    matrix[row] = matrix[row + 1];
                    matrix[row + 1] = temp;
                    flag = true;
                }
            }
        }
    }
}


void unique_elems(double **matrix, int rows, int columns, unsigned int *count)
{
    if (columns >= 3)
    {
        for (int row = 0; row < rows; row++)
        {
            for (int column = 1; column < columns - 1; column++)
            {
                if (matrix[row][column] > matrix[row][column - 1] && matrix[row][column] < matrix[row][column + 1])
                {
                    (*count)++;
                }
            }
        }
    }
}
