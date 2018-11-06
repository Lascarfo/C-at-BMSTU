#include <math.h>
#include <stdio.h>

#include "calculatings.h"
#include "const.h"



int cmp_double_c(double l, double r)
{
    double result = fabs(l - r);
    if (result > EPS)
        return true;
    else
        return false;
    return true;
}

bool check(double **matrix_first, double **result_matrix, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (cmp_double_c(matrix_first[row][column], result_matrix[row][column]))
            {
                return false;
            }
        }
    }
    return true;
}

int main(void)
{
    {
        printf("tests for sort_matrix func:\n");
        printf("test1: ");
        double first[2][2] = { { 1.0, 2.0 }, { 3.0, 4.0 } };
        double second[2][2] = { { 1.0, 2.0 }, { 3.0, 4.0 } };
        double *matrix[2] = { first[0], first[1] };
        double *result[2] = { second[0], second[1] };
        sort_matrix(matrix, 2, 2);
        if (check(matrix, result, 2, 2))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test2: ");
        double first[2][2] = { { 3.0, 4.0 }, { 1.0, 2.0 } };
        double second[2][2] = { { 1.0, 2.0 }, { 3.0, 4.0 } };
        double *matrix[2] = { first[0], first[1] };
        double *result[2] = { second[0], second[1] };
        sort_matrix(matrix, 2, 2);
        if (check(matrix, result, 2, 2))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test3: ");
        double first[2][2] = { { 0, 0 }, { 0, 0 } };
        double second[2][2] = { { 0, 0 }, { 0, 0 } };
        double *matrix[2] = { first[0], first[1] };
        double *result[2] = { second[0], second[1] };
        sort_matrix(matrix, 2, 2);
        if (check(matrix, result, 2, 2))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("\ntests for unique_elems func:\n");
        printf("test1: ");
        double first[2][3] = { { 1.0, 2.0, 3.0 }, { 3.0, 4.0, 5.0 } };
        double *matrix[2] = { first[0], first[1] };
        unsigned int count = 0;
        unique_elems(matrix, 2, 3, &count);
        if (count == 2)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test2: ");
        double first[2][3] = { { 1.0, 2.0, 2.0 }, { 3.0, 4.0, 4.0 } };
        double *matrix[2] = { first[0], first[1] };
        unsigned int count = 0;
        unique_elems(matrix, 2, 3, &count);
        if (count == 0)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test3: ");
        double first[2][3] = { { 1.0, 2.0, 0 }, { 3.0, 4.0, 5.0 } };
        double *matrix[2] = { first[0], first[1] };
        unsigned int count = 0;
        unique_elems(matrix, 2, 3, &count);
        if (count == 1)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    return OK;
}
