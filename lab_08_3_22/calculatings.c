#include <stdbool.h>


#include "calculatings.h"
#include "io.h"
//
//
// void free_mem(double **matrix, const int rows)
// {
//     for (int row = 0; row < rows; row++)
//     {
//         free(matrix[row]);
//     }
//     //free(matrix);
// }


bool cmp_double(double left, double right)
{
    if (fabs(left - right) <= eps)
    {
        return false;
    }
    if (left < right)
    {
        return true;
    }
    return false;
}

void zero_filling(double **matrix, const int rows, const int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
             matrix[i][j] = 0;
        }
    }
}


void index_of_max(double **matrix, int rows, int rows_columns, int *maximum)
{
    double temp = matrix[rows][rows];
    for(int temp_row = rows; temp_row <= rows_columns; temp_row++)
    {
        for(int temp_column = rows; temp_column <= rows_columns; temp_column++)
        {
            if (cmp_double(temp, matrix[temp_row][temp_column]))
            {
                temp = matrix[temp_row][temp_column];
                maximum[0] = temp_row;
                maximum[1] = temp_column;
            }
        }
    }
}

void swap(double **matrix, int *maximum, int row, int rows_columns)
{
    print_square(matrix, row, rows_columns);
    double temp_elem = 0.0;
    double *temp_row = matrix[row];
    matrix[row] = matrix[maximum[0]];
    matrix[maximum[0]] = temp_row;
    print_square(matrix, row, rows_columns);
    for (int rows = row; rows <= rows_columns; rows++)
    {
        temp_elem = matrix[rows][row];
        matrix[rows][row] = matrix[rows][maximum[1]];
        matrix[rows][maximum[1]] = temp_elem;
    }
    print_square(matrix, row, rows_columns);
}

void elimination(double **matrix, int rows_columns)
{
    int maximum[2] = { rows_columns, rows_columns };
    int curr_row = 0;
    int copy_of_rows_columns = rows_columns;
    while (rows_columns > 0)
    {
        maximum[0] = curr_row;
        maximum[1] = curr_row;
        index_of_max(matrix, curr_row, copy_of_rows_columns, maximum);
        printf("maximum %d %d\n", maximum[0], maximum[1]);
        swap(matrix, maximum, curr_row, copy_of_rows_columns);
        curr_row++;
        rows_columns--;
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
    for (int row_first = 0; row_first < rows_first; row_first++)
    {
        for (int column_second = 0; column_second < columns_second; column_second++)
        {
            for (int column_first_row_sec = 0; column_first_row_sec < columns_first_rows_sec; column_first_row_sec++)
            {
                result_matrix[row_first][column_second] += matrix_first[row_first][column_first_row_sec] * matrix_second[column_first_row_sec][column_second];
            }
        }
    }
    for (int row_first = 0; row_first < rows_first; row_first++)
    {
        for( int column_second = 0; column_second < columns_second; column_second++)
        {
            if (result_matrix[row_first][column_second] != 0)
            {
                (*positive_elements)++;
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
