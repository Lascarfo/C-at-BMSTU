#include <stdbool.h>


#include "calculatings.h"


void free_mem(double **matrix, const int rows)
{
    for (int row = 0; row < rows; row++)
    {
        free(matrix[row]);
    }
    free(matrix);
}

void zero_filling(double **matrix, const int rows, const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
             matrix[i][j] = 0;
//             printf("matrix %lf\n", matrix[i][j]);
        }
    }
}

void addition(double **matrix_first, double **matrix_second, const int rows, const int columns, int *positive_elements)
{
    *positive_elements = 0;
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            matrix_first[row][column] += matrix_second[row][column];
            if (matrix_first[row][column] != 0)
            {
                (*positive_elements)++;
            }
        }
    }
}

double **multiplication(double **matrix_first, double **matrix_second, const int columns_first_rows_sec, const int rows_first, const int columns_second, int *positive_elements)
{
    double **result_matrix = allocate_memory(rows_first, columns_second);
    for(int row_first = 0; row_first < rows_first; row_first++)
    {
        for(int column_second = 0; column_second < columns_second; column_second++)
        {
            for(int column_first_row_sec = 0; column_first_row_sec < columns_first_rows_sec; column_first_row_sec++)
            {
                result_matrix[row_first][column_second] += matrix_first[row_first][column_first_row_sec] * matrix_second[column_first_row_sec][column_second];
                if (result_matrix[row_first][column_second] != 0)
                {
                    (*positive_elements)++;
                }
            }
        }
    }
    return result_matrix;
}

int char_to_int(char num)
{
    return num - '0';
}

bool counter_params(FILE *in)
{
    char symbol = '\0';
    int count = 0;
    while (count < 3)
    {
        fscanf(in, "%c ", &symbol);
        if (symbol == '\n')
        {
            break;
        }
        if (!isdigit(symbol))
        {
            return false;
        }
        else
        {
            count++;
        }
    }
    if (count != 3)
    {
        return false;
    }
    return true;
}




double **allocate_memory(const int rows, const int columns)
{
    double **matrix = malloc(rows * sizeof(double*) + rows * columns * sizeof(double));
    if (matrix)
    {
        for (int index = 0; index < rows; index++)
        {
            matrix[index] = (double*)((char*) matrix + rows * sizeof(double*) + index * columns * sizeof(double));
        }
    }
    return matrix;
}
