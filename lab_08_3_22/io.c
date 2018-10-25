#include "io.h"
#include "const.h"
#include "calculatings.h"
#include "memory.h"




int read_params(FILE *in, int *rows, int *columns, int *positive_elements)
{
    rewind(in);
    if (fscanf(in, "%d %d %d", rows, columns, positive_elements) == 3)
    {
        if (*positive_elements > (*rows) * (*columns) || *rows < 1 || *columns < 1)
        {
            return ERR_INPUT;
        }
    }
    else
    {
        return ERR_INPUT;
    }
    return OK;
}


int read_elems(FILE *in, const int rows, const int columns, const int positive_elements, double **matrix)
{
    double cache_double;
    int cache_row, cache_column;
    for (int index = 0; index < positive_elements; index++)
    {
        if (fscanf(in, "%d %d %lf", &cache_row, &cache_column, &cache_double) != 3)
        {
            return ERR_MATRIX;
        }
        if ((cache_row < 1 || cache_row > rows) || (cache_column < 1 || cache_column > columns))
        {
            return ERR_MATRIX;
        }
        matrix[cache_row - 1][cache_column - 1] = cache_double;
    }
    return OK;
}

int read_matrix(FILE *in, double ***matrix, int *rows, int *columns, int *positive_elements)
{
    if (read_params(in, rows, columns, positive_elements) == 0)
    {
        *matrix = allocate_memory(*rows, *columns);
        if (*matrix == NULL)
        {
            return ERR_MEMORY;
        }
        zero_filling(*matrix, *rows, *columns);
        if (read_elems(in, *rows, *columns, *positive_elements, *matrix) != OK)
        {
            return ERR_MATRIX;
        }
    }
    else
    {
        return ERR_INPUT;
    }
    return OK;
}


void save(FILE *out, double **matrix, const int rows, const int columns, const int positive_elements)
{
    if (positive_elements == -1)
    {
        fprintf(out, "%d %d\n", rows, columns);
    }
    else
    {
        fprintf(out, "%d %d %d\n", rows, columns, positive_elements);
    }
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (matrix[row][column] != 0)
            {
                fprintf(out, "%d %d %0.3lf\n", row + 1, column + 1, matrix[row][column]);
            }
        }
    }
}

void print_matrix(double **matrix, const int rows, const int columns, const int positive_elements)
{
    save(stdout, matrix, rows, columns, positive_elements);
}


// void print_square(double **matrix, int row, int rows_columns)
// {
//     printf("\n");
//     for (int temp_row = 0; temp_row < row; temp_row++)
//     {
//         for (int temp_column = 0; temp_column < rows_columns; temp_column++)
//         {
//             printf("%0.2lf ", matrix[temp_row][temp_column]);
//         }
//         printf("\n");
//     }
//     printf("\n");
// }
