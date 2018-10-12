#include "io.h"
#include "const.h"
#include "calculatings.h"





void read_params(FILE *in, int *rows, int *columns, int *positive_elements)
{
    rewind(in);
    char symbol = '\0';
    int params[3] = {0};
    int index = 0;
    while (symbol != '\n')
    {
        fscanf(in, "%c", &symbol);
        if (isdigit(symbol))
        {
            params[index++] = char_to_int(symbol);
        }
    }
    *rows = params[0];
    *columns = params[1];
    *positive_elements = params[2];
}


int read_elems(FILE *in, const int rows, const int columns, const int positive_elements, double **matrix)
{
    double cache_double;
    int cache_row, cache_column;
    for (int index = 0; index < positive_elements; index++)
    {
        fscanf(in, "%d %d %lf", &cache_row, &cache_column, &cache_double);
        if ((cache_row < 1 || cache_row > rows) || (cache_column < 1 || cache_column > columns))
        {
            return ERR_MATRIX;
        }
        //printf("%d %d %lf\n", cache_row, cache_column, cache_double);
        matrix[cache_row - 1][cache_column - 1] = cache_double;
    }
    return OK;
}

int read_matrix(FILE *in, double ***matrix, int *rows, int *columns, int *positive_elements)
{
    if (counter_params(in))
    {
        read_params(in, rows, columns, positive_elements);
//        printf("in %d, rows %d, columns %d\n", rows, columns, positive_elements);
        if (*rows > 0 && *columns > 0)
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
//            print_matrix(matrix, *rows, *columns, *positive_elements);
        }
        else
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

int arithmetic(char **argv)
{
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
                read_matrix(file_in_1, &matrix_first, &rows_first, &columns_first, &positive_elements_first);
                read_matrix(file_in_2, &matrix_second, &rows_second, &columns_second, &positive_elements_second);
                if (strcmp(argv[1], "a") == 0)
                {
                    addition(matrix_first, matrix_second, rows_first, columns_first, &positive_elements);
                    save(file_out, matrix_first, rows_first, columns_second, positive_elements);
                }
                else
                {
                    if (columns_first == rows_second)
                    {
                        double **matrix_multiply = multiplication(matrix_first, matrix_second, columns_first, rows_first, columns_second, &positive_elements);
                        save(file_out, matrix_multiply, rows_first, columns_second, positive_elements);
                        free_mem(matrix_multiply, rows_first);
                    }
                    else
                    {
                        // oops...
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
    return OK;
}





void save(FILE *out, double **matrix, const int rows, const int columns, const int positive_elements)
{
    fprintf(out, "%d %d %d\n", rows, columns, positive_elements);
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (matrix[row][column] != 0)
            {
                fprintf(out, "%d %d %0.1lf\n", row + 1, column + 1, matrix[row][column]);
            }
        }
    }
    fprintf(out, "\n");
}

void print_matrix(double **matrix, const int rows, const int columns, const int positive_elements)
{
    save(stdout, matrix, rows, columns, positive_elements);
}
