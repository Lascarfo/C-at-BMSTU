

#include "calculatings.h"



bool cmpr_rows(double *row1, double *row2, const int columns)
{
    double temp = 0.0;

    for (int column = 0; column < columns; column++)
    {
        temp += row1[column];
        temp -= row2[column];
    }
    if (temp < 0)
    {
        true;
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
