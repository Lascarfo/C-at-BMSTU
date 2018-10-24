#include <stdbool.h>


#include "calculatings.h"
#include "io.h"
#include "memory.h"


int gauss(char **argv)
{
    int rc = OK;
    FILE *file_in_1;
    FILE *file_out;
    double **matrix_first = NULL;
    file_in_1 = fopen(argv[2], "r");
    if (file_in_1)
    {
        file_out = fopen(argv[3], "w");
        if (file_out)
        {
            int rows_first, columns_first, positive_elements_first;
            rc = read_matrix(file_in_1, &matrix_first, &rows_first, &columns_first, &positive_elements_first);
            if ((rows_first == columns_first) && (rc == OK))
            {
                elimination(matrix_first, rows_first - 1);
            }
            else
            {
                rc = ERR_MATRIX;
            }
            save(file_out, matrix_first, rows_first, columns_first, positive_elements_first);
            free(matrix_first);
            fclose(file_out);
            fclose(file_in_1);
        }
        else
        {
            printf("error open file_out for write\nplease input ./app.exe h\nfor help\n");
            fclose(file_in_1);
            return ERR_FILE;
        }
    }
    else
    {
        printf("error open file_in_1 for read\nplease input ./app.exe h\nfor help\n");
        return ERR_FILE;
    }
    return rc;
}


int arithmetic(char **argv)
{
    int rc = OK;
    FILE *file_in_1;
    FILE *file_in_2;
    FILE *file_out;
    double **matrix_first = NULL;
    double **matrix_second = NULL;
    file_in_1 = fopen(argv[2], "r");
    if (file_in_1)
    {
        file_in_2 = fopen(argv[3], "r");
        if (file_in_2)
        {
            file_out = fopen(argv[4], "w");
            if (file_out)
            {
                int rows_first, rows_second, columns_first, columns_second, positive_elements_first, positive_elements_second, positive_elements;
                rows_first = rows_second = columns_first = columns_second = positive_elements_first = positive_elements_second = positive_elements = OK;
                if (read_matrix(file_in_1, &matrix_first, &rows_first, &columns_first, &positive_elements_first) != OK)
                {
                    fclose(file_in_1);
                    fclose(file_in_2);
                    fclose(file_out);
                    return ERR_MATRIX;
                }
                if (read_matrix(file_in_2, &matrix_second, &rows_second, &columns_second, &positive_elements_second) != OK)
                {
                    free_mem(matrix_first, rows_first);
                    fclose(file_in_1);
                    fclose(file_in_2);
                    fclose(file_out);
                    return ERR_MATRIX;
                }
                if ((strcmp(argv[1], "a") == 0))
                {
                    if ((columns_first = columns_second) && (rows_first == rows_second))
                    {
                        addition(matrix_first, matrix_second, rows_first, columns_first, &positive_elements);
                        save(file_out, matrix_first, rows_first, columns_second, positive_elements);
                    }
                    else
                    {
                        free_mem(matrix_first, rows_first);
                        free_mem(matrix_second, rows_second);

                        fclose(file_in_1);
                        fclose(file_in_2);
                        fclose(file_out);
                        rc = ERR_MATRIX;
                    }
                }
                else if ((strcmp(argv[1], "m") == 0))
                {
                    if (columns_first == rows_second)
                    {
                        double **matrix_multiply = multiplication(matrix_first, matrix_second, columns_first, rows_first, columns_second, &positive_elements);
                        save(file_out, matrix_multiply, rows_first, columns_second, positive_elements);
                        free_mem(matrix_multiply, rows_first);
                    }
                    else
                    {
                        free_mem(matrix_first, rows_first);
                        free_mem(matrix_second, rows_second);
                        fclose(file_in_1);
                        fclose(file_in_2);
                        fclose(file_out);
                        rc = ERR_MATRIX;
                    }
                }
                free_mem(matrix_first, rows_first);
                free_mem(matrix_second, rows_second);

                fclose(file_in_1);
                fclose(file_in_2);
                fclose(file_out);
            }
            else
            {
                printf("error open file_out for write\nplease input ./app.exe h\nfor help\n");
                fclose(file_in_1);
                fclose(file_in_2);
                return ERR_FILE;
            }
        }
        else
        {
            printf("error open file_in_2 for read\nplease input ./app.exe h\nfor help\n");
            fclose(file_in_1);
            return ERR_FILE;
        }
    }
    else
    {
        printf("error open file_in_1 for read\nplease input ./app.exe h\nfor help\n");
        return ERR_FILE;
    }
    return rc;
}

bool cmp_double(double left, double right)
{
    if (fabs(left - right) <= EPS)
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


void index_of_max(double **matrix, int rows, int rows_columns, int *max_rows, int *max_columns)
{
    double temp = matrix[rows][rows];
    for (int temp_row = rows; temp_row <= rows_columns; temp_row++)
    {
        for (int temp_column = rows; temp_column <= rows_columns; temp_column++)
        {
            if (cmp_double(temp, matrix[temp_row][temp_column]))
            {
                temp = matrix[temp_row][temp_column];
                *max_rows = temp_row;
                *max_columns = temp_column;
            }
        }
    }
}

// void swap(double **matrix, int *maximum, int row, int rows_columns)
// {
// //    print_square(matrix, row, rows_columns);
//     double temp_elem = 0.0;
//     double *temp_row = matrix[row];
//     matrix[row] = matrix[maximum[0]];
//     matrix[maximum[0]] = temp_row;
// //    print_square(matrix, row, rows_columns);
//     for (int rows = row; rows <= rows_columns; rows++)
//     {
//         temp_elem = matrix[rows][row];
//         matrix[rows][row] = matrix[rows][maximum[1]];
//         matrix[rows][maximum[1]] = temp_elem;
//     }
// //    print_square(matrix, row, rows_columns);
// }

void elimination(double **matrix, int rows_columns)
{
    int max_rows = rows_columns, max_columns = rows_columns;
    int curr_row = 0;
    int copy_of_rows_columns = rows_columns;
    while (rows_columns > 0)
    {
        max_rows = curr_row;
        max_columns = curr_row;
        index_of_max(matrix, curr_row, copy_of_rows_columns, &max_rows, &max_columns);
        printf("maximum %d %d\n", max_rows, max_columns);
//        swap(matrix, maximum, curr_row, copy_of_rows_columns);
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
    if (result_matrix != NULL)
    {
        zero_filling(result_matrix, rows_first, columns_second);
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
            for (int column_second = 0; column_second < columns_second; column_second++)
            {
                if (result_matrix[row_first][column_second] != 0)
                {
                    (*positive_elements)++;
                }
            }
        }
    }
    return result_matrix;
}
