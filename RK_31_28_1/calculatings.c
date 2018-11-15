#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#include "const.h"
#include "calculatings.h"



int cmp_double(double left, double right)
{
    double compare = (left - right);
    if (EPS > fabs(compare))
    {
        return 2;
    }
    compare = (left - right);
    if (compare < 0)
    {
        return -1;
    }
    if (compare > 0)
    {
        return 1;
    }
    return 0;
}

bool cmpr_rows(double *row1, double *row2, const int columns)
{
    double temp = 0.0;

    for (int column = 0; column < columns; column++)
    {
        temp += row1[column];
        temp -= row2[column];
    }
    if (temp > EPS)
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


unsigned int unique_elems(double *row, int columns)
{
    bool left = false, right = false;
    unsigned int count = 0;
    {
        for (int elem = 0; elem < columns; elem++)
        {
            left = true;
            right = true;
            if (elem != 0 && elem != columns - 1) // не уверен, крайние элементы уникальные, или нет
            {
                for (int cmp = 0; cmp < columns; cmp++)
                {
                    if (cmp < elem && cmp_double(row[cmp], row[elem]) != -1)
                    {
                        // printf("< cmp: %d\n", cmp_double(row[cmp], row[elem]));
                        // printf("indexis: %d %d\n", cmp, elem);
                        // printf("elems: %0.2f %0.2f\n", row[cmp], row[elem]);
                        left = false;
                    }
                    else if (cmp > elem && (cmp_double(row[cmp], row[elem]) != 1))
                    {
                        // printf("> cmp: %d\n", cmp_double(row[cmp], row[elem]));
                        // printf("indexis: %d %d\n", cmp, elem);
                        // printf("elems: %0.2f %0.2f\n", row[cmp], row[elem]);
                        right = false;
                    }
                }
                // printf("elem: %d\n", elem + 1);
                // printf("left:%d right:%d\n", left, right);
                if (right && left)
                {
                    count++;
                }
            }
        }
    }
    return count;
}
