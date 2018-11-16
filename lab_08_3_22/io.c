/**
 \file
 */



#include "io.h"
#include "const.h"
#include "calculatings.h"
#include "memory.h"



/**
* \brief эта функция считывает параметры
* \details параметры –– количество строк, столбцов, ненулевых элементов
* \param in файл для чтения
* \param rows количество строк
* \param columns количество столбцов
* \param positive_elements количество ненулевых элементов
*/

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

/**
* \brief эта функция считывает элементы с матрицы
* \param in файл для чтения
* \param rows количество строк
* \param columns количество столбцов
* \param positive_elements количество ненулевых элементов
* \param matrix матрица, в которую будут записаны числа с файла
*/

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

/**
* \brief это основная функция считывания матрицы
* \details функция связывает read_elems() и read_params()
* \param in файл для чтения
* \param rows количество строк
* \param columns количество столбцов
* \param positive_elements количество ненулевых элементов
* \param matrix исходная матрица
*/

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

/**
* \brief эта функция сохраняет матрицу в файл
* \details матрица будет сохранена в координатном виде
* \param out файл для записи
* \param rows количество строк
* \param columns количество столбцов
* \param positive_elements количество ненулевых элементов
* \param matrix матрица для записи
*/

void save(FILE *out, double **matrix, const int rows, const int columns, const int positive_elements)
{
    fprintf(out, "%d %d %d\n", rows, columns, positive_elements);
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            if (cmp_w_null(matrix[row][column]))
            {
                fprintf(out, "%d %d %f\n", row + 1, column + 1, matrix[row][column]);
            }
        }
    }
}

/**
* \brief эта функция печатает матрицу
* \param rows количество строк
* \param columns количество столбцов
* \param positive_elements количество ненулевых элементов
* \param matrix исходная матрица
*/

void print_matrix(double **matrix, const int rows, const int columns, const int positive_elements)
{
    save(stdout, matrix, rows, columns, positive_elements);
}




void print_square(double **matrix, int row, int rows_columns)
{
    printf("\n");
    for (int temp_row = 0; temp_row < row; temp_row++)
    {
        for (int temp_column = 0; temp_column < rows_columns; temp_column++)
        {
            printf("%0.2lf ", matrix[temp_row][temp_column]);
        }
        printf("\n");
    }
    printf("\n");
}
