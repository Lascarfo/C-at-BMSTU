#include <stdio.h>
#include <stdbool.h>
#include "calculatings.h"

#include "const.h"



bool check(double **matrix_first, double **result_matrix, int rows, int columns)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (matrix_first[row][column] != result_matrix[row][column])
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
        printf("Testing allocate_memory func\n");
        printf("test 1: ");
        double **matrix_first = NULL;
        matrix_first = allocate_memory(1, 1);
        if (matrix_first != NULL)
        {
            free(matrix_first);
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test 2: ");
        double **matrix_first = NULL;
        matrix_first = allocate_memory(0, 0);
        if (matrix_first == NULL)
        {
            printf("passed\n");
        }
        else
        {
            free(matrix_first);
            printf("not passed\n");
        }
    }
    {
        printf("test 3: ");
        double **matrix_first = NULL;
        matrix_first = allocate_memory(10, 1);
        if (matrix_first != NULL)
        {
            free(matrix_first);
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    // {
    //     printf("\nTesting addition func\n");
    //     printf("test 1: ");
    //     int positive_elements = 0, expect = 0;
    //     int rows = 3;
    //     int columns = 3;
    //     double matrix_firstt[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //     double matrix_secondd[3][3] = {{-1, -2, -3}, {-4, -5, -6}, {-7, -8, -9}};
    //     double result_matrixx[3][3] = {{0, 0, 0}, {0, 0, 0}, {0, 0, 0}};
    //
    //     addition(matrix_first, matrix_second, rows, columns, &positive_elements);
    //     if (check(matrix_first, result_matrix, rows, columns) && positive_elements = expect)
    //     {
    //         printf("passed\n");
    //     }
    //     else
    //     {
    //         printf("not passed\n");
    //     }
    //
    //
    // }
    return OK;
}
