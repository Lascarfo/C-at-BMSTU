#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>



#include "const.h"
#include "memory.h"
#include "calculatings.h"

/**
* \brief функция-компаратор для типа double
* \param  l, r Числа, проверяемые компаратором
*/

int cmp_double_c(double l, double r)
{
    double result = fabs(l - r);
    if (result > EPS)
        return true;
    else
        return false;
    return true;
}

/**
* \brief функция, сравнивающая две матрицы
* \param matrix_first, result_matrix матрицы для сравнения
* \param rows количество строк
* \param columns количество столбцов
* \details функция сравнивает матрицу, полученную в результате работы отдельной
* функции с результатом, предусмотренным пользователем
*/

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

/*!
 * \file
 * \fn int main(void)
 * \return code of error
 */


 /**
 * \brief это основная функция программы, выполняющая модульные тесты
 * \param void
 */

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
    {
        printf("\nTesting addition func\n");
        printf("test 1: ");
        int positive_elements = 0, expect = 0;
        int rows = 3;
        int columns = 3;
        double mat_arr1[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        double mat_arr2[3][3] = { { -1, -2, -3 }, { -4, -5, -6 }, { -7, -8, -9 } };
        double mat_arr3[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
        double *matrix1[3] = { mat_arr1[0], mat_arr1[1], mat_arr1[2] };
        double *matrix2[3] = { mat_arr2[0], mat_arr2[1], mat_arr2[2] };
        double *matrix3[3] = { mat_arr3[0], mat_arr3[1], mat_arr3[2] };

        addition(matrix1, matrix2, rows, columns, &positive_elements);
        if (check(matrix1, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test 2: ");
        int positive_elements = 0, expect = 0;
        int rows = 3;
        int columns = 3;
        double mat_arr2[3][3] = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
        double mat_arr1[3][3] = { { -1, -2, -3 }, { -4, -5, -6 }, { -7, -8, -9 } };
        double mat_arr3[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
        double *matrix1[3] = { mat_arr1[0], mat_arr1[1], mat_arr1[2] };
        double *matrix2[3] = { mat_arr2[0], mat_arr2[1], mat_arr2[2] };
        double *matrix3[3] = { mat_arr3[0], mat_arr3[1], mat_arr3[2] };

        addition(matrix1, matrix2, rows, columns, &positive_elements);
        if (check(matrix1, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test 3: ");
        int positive_elements = 0, expect = 9;
        int rows = 3;
        int columns = 3;
        double mat_arr3[3][3] = { { -1, -2, -3 }, { -4, -5, -6 }, { -7, -8, -9 } };
        double mat_arr2[3][3] = { { -1, -2, -3 }, { -4, -5, -6 }, { -7, -8, -9 } };
        double mat_arr1[3][3] = { { 0, 0, 0 }, { 0, 0, 0 }, { 0, 0, 0 } };
        double *matrix1[3] = { mat_arr1[0], mat_arr1[1], mat_arr1[2] };
        double *matrix2[3] = { mat_arr2[0], mat_arr2[1], mat_arr2[2] };
        double *matrix3[3] = { mat_arr3[0], mat_arr3[1], mat_arr3[2] };

        addition(matrix1, matrix2, rows, columns, &positive_elements);
        if (check(matrix1, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("test 4: ");
        int positive_elements = 0, expect = 0;
        int rows = 2;
        int columns = 2;
        double mat_arr1[2][3] = { { -1.1, -2.2, -3.3 }, { -4.4, -5.5, -6.6 } };
        double mat_arr2[2][3] = { { 1.1, 2.2, 3.3 }, { 4.4, 5.5, 6.6 } };
        double mat_arr3[2][3] = { { 0, 0, 0 }, { 0, 0, 0 } };
        double *matrix1[2] = { mat_arr1[0], mat_arr1[1] };
        double *matrix2[2] = { mat_arr2[0], mat_arr2[1] };
        double *matrix3[2] = { mat_arr3[0], mat_arr3[1] };

        addition(matrix1, matrix2, rows, columns, &positive_elements);
        if (check(matrix1, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        printf("\nTesting multipication func\n");
        printf("test 1: ");
        int positive_elements = 0, expect = 4;
        int rows = 2;
        int columns = 2;
        double mat_arr1[2][2] = { { 1, 2 }, { 3, 4 } };
        double mat_arr2[2][2] = { { 4, 3 }, { 2, 1 } };
        double mat_arr3[2][2] = { { 8, 5 }, { 20, 13 } };
        double *matrix1[2] = { mat_arr1[0], mat_arr1[1] };
        double *matrix2[2] = { mat_arr2[0], mat_arr2[1] };
        double *matrix3[2] = { mat_arr3[0], mat_arr3[1] };
        double **matrix4 = NULL;

        matrix4 = multiplication(matrix1, matrix2, rows, rows, columns, &positive_elements);
        if (check(matrix4, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
        free_mem(matrix4, rows);
    }
    {
        printf("test 2: ");
        int positive_elements = 0, expect = 0;
        int rows = 2;
        int columns = 2;
        double mat_arr1[2][2] = { { 0, 0 }, { 0, 0 } };
        double mat_arr2[2][2] = { { 4, 3 }, { 2, 1 } };
        double mat_arr3[2][2] = { { 0, 0 }, { 0, 0 } };
        double *matrix1[2] = { mat_arr1[0], mat_arr1[1] };
        double *matrix2[2] = { mat_arr2[0], mat_arr2[1] };
        double *matrix3[2] = { mat_arr3[0], mat_arr3[1] };
        double **matrix4 = NULL;

        matrix4 = multiplication(matrix1, matrix2, rows, rows, columns, &positive_elements);
        if (check(matrix4, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
        free_mem(matrix4, rows);
    }
    {
        printf("test 3: ");
        int positive_elements = 0, expect = 0;
        int rows = 1;
        int columns = 1;
        double mat_arr1[1][1] = { { 1 } };
        double mat_arr2[1][1] = { { 0 } };
        double mat_arr3[1][1] = { { 0 } };
        double *matrix1[1] = { mat_arr1[0] };
        double *matrix2[1] = { mat_arr2[0] };
        double *matrix3[1] = { mat_arr3[0] };
        double **matrix4 = NULL;

        matrix4 = multiplication(matrix1, matrix2, rows, rows, columns, &positive_elements);
        if (check(matrix4, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
        free_mem(matrix4, rows);
    }
    {
        printf("test 4: ");
        int positive_elements = 0, expect = 1;
        int rows = 1;
        int columns = 1;
        double mat_arr1[1][2] = { { 9.32, 2.11 } };
        double mat_arr2[2][1] = { { 9.42 }, { 1.0 } };
        double mat_arr3[1][1] = { { 89.9044 } };
        double *matrix1[1] = { mat_arr1[0] };
        double *matrix2[2] = { mat_arr2[0], mat_arr2[1] };
        double *matrix3[1] = { mat_arr3[0] };
        double **matrix4 = NULL;

        matrix4 = multiplication(matrix1, matrix2, 2, rows, columns, &positive_elements);
        if (check(matrix4, matrix3, rows, columns) && positive_elements == expect)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
        free_mem(matrix4, rows);
    }
    return OK;
}
