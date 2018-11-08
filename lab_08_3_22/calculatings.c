/**
 \file
 */

#include <stdbool.h>


#include "calculatings.h"
#include "io.h"
#include "memory.h"



/**
* \brief функция, результатом выполнения которой является решение СЛАУ
* \details эта функция работает считывает матрицу с файла и передает ее в
* функцию method, где происходят дальнейшие вычисления, а затем сохраняет результат в файл
* \param argv в этом массиве хранятся символы, поданые на ввод
*/


int gauss(char **argv)
{
    int rc = OK;
    FILE *file_in_1;
    FILE *file_out;
    file_in_1 = fopen(argv[2], "r");
    if (file_in_1)
    {
        file_out = fopen(argv[3], "w");
        if (file_out)
        {
            double **matrix_first = NULL;
            int rows_first, columns_first, positive_elements_first, positive_elements;
            if (read_matrix(file_in_1, &matrix_first, &rows_first, &columns_first, &positive_elements_first) != OK)
            {
                if (matrix_first)
                {
                    free_mem(matrix_first, rows_first);
                }
                rc = ERR_MATRIX;
            }
            else if (matrix_first)
            {
                if (rows_first == columns_first - 1)
                {
                    double **res_matrix = NULL;
                    res_matrix = allocate_memory(rows_first, 1);
                    if (res_matrix)
                    {
                        zero_filling(res_matrix, rows_first, 1);
                        method(matrix_first, res_matrix, rows_first, columns_first);
                        positive_elements = not_null_elems(res_matrix, rows_first, 1);
                        save(file_out, res_matrix, rows_first, 1, positive_elements);
                        free_mem(res_matrix, rows_first);
                    }
                    else
                    {
                        rc = ERR_MATRIX;
                    }
                }
                free_mem(matrix_first, rows_first);
            }
            else
            {
                rc = ERR_MATRIX;
            }
            fclose(file_out);
        }
        else
        {
            rc = ERR_FILE;
        }
        fclose(file_in_1);
    }
    else
    {
        return ERR_FILE;
    }
    return rc;
}


/**
* \brief функция, выполняющая арифметические операции
* \details результатом вычислений этой функции является готовая матрица
* состоящая либо из суммы элементов двух матриц, либо произведения
* первой матрицы на вторую
* \param argv в этом массиве хранятся символы, поданые на ввод
*/

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
                    if (matrix_first)
                    {
                        free_mem(matrix_first, rows_first);
                    }
                    rc = ERR_MATRIX;
                }
                else if (read_matrix(file_in_2, &matrix_second, &rows_second, &columns_second, &positive_elements_second) != OK)
                {
                    if (matrix_second)
                    {
                        free_mem(matrix_second, rows_second);
                    }
                    rc = ERR_MATRIX;
                }
                else if (matrix_first)
                {
                    if (matrix_second)
                    {
                        if ((strcmp(argv[1], "a") == 0))
                        {
                            if ((columns_first = columns_second) && (rows_first == rows_second))
                            {
                                addition(matrix_first, matrix_second, rows_first, columns_first, &positive_elements);
                                save(file_out, matrix_first, rows_first, columns_second, positive_elements);
                            }
                            else
                            {
                                rc = ERR_MATRIX;
                            }
                        }
                        else
                        {
                            if (columns_first == rows_second)
                            {
                                double **matrix_multiply = multiplication(matrix_first, matrix_second, columns_first, rows_first, columns_second, &positive_elements);
                                if (matrix_multiply)
                                {
                                    save(file_out, matrix_multiply, rows_first, columns_second, positive_elements);
                                    free_mem(matrix_multiply, rows_first);
                                }
                                else
                                {
                                    rc = ERR_MATRIX;
                                }
                            }
                            else
                            {
                                rc = ERR_MATRIX;
                            }
                        }
                        free_mem(matrix_second, rows_second);
                    }
                    free_mem(matrix_first, rows_first);
                }
                fclose(file_out);
            }
            else
            {
                rc = ERR_FILE;
            }
            fclose(file_in_2);
        }
        else
        {
            rc = ERR_FILE;
        }
        fclose(file_in_1);
    }
    else
    {
        rc = ERR_FILE;
    }
    return rc;
}


/**
* \brief компаратор для типа double
* \details функция сравнивает два числа типа double с точностью EPS
* и возвращает пользователю результат сравнения
* \param  l, r Числа, проверяемые компаратором
*/


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


/**
* \brief функция, которая сравнивает поданное число с нулем с точностью EPS
* \param number число для проверки
*/

bool cmp_w_null(double number)
{
    if (fabs(number) < EPS)
    {
        return false;
    }
    return true;
}

/**
* \brief эта функция заполняет матрицу нулями
* \param matrix исходная матрица
* \param rows количество строк
* \param columns количество столбцов
*/


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

/**
* \brief функция находит индекс максимального элемента
* \details функция записывает индекс максимального элемента
* по строке и столбцу
* \param matrix исходная матрица
* \param current текущий элемент
* \param rows количесво строк
* \param max_rows, max_columns переменные, в которых хранятся индексы максимального элемента
*/

void index_of_max(const double **matrix, const int current, const int rows, int *max_rows, int *max_columns)
{
    double temp = matrix[current][current];
    *max_rows = current;
    *max_columns = current;
    for (int row = current; row < rows; row++)
    {
        if (cmp_double(temp, matrix[row][current]))
        {
            temp = matrix[row][current];
            *max_rows = row;
        }
    }
    for (int row = current; row < rows; row++)
    {
        if (cmp_double(temp, matrix[current][row]))
        {
            temp = matrix[current][row];
            *max_rows = current;
            *max_columns = row;
        }
    }
}


/**
* \brief основная функция рещения СЛАУ
* \details в этой функции происходят различные операции
* в итоге дающие решение СЛАУ
* \param matrix матрица для обработки
* \param res_matrix матрица, в которую записывается результат
* \param rows количесво строк
* \param columns количесво столбцов
*/

void method(double **matrix, double **res_matrix, const int rows, const int columns)
{
    int max_row, max_column;
    for (int current = 0; current < rows; current++)
    {
        // printf("matrix\n");
        // print_square(matrix, rows, columns);
        index_of_max((const double**)(matrix), current, rows, &max_row, &max_column);
        shift(matrix, max_row, max_column, current, rows);
        // printf("shift_func\n");
        // print_square(matrix, rows, columns);
        my_div(matrix, rows, columns, current);
        // printf("my_div_func\n");
        // print_square(matrix, rows, columns);
        if (current + 1 != rows)
        {
            sub(matrix, rows, columns, current + 1);
            // printf("sub_func\n");
            // print_square(matrix, rows, columns);
        }
        // printf("iter: %d, row: %d, column: %d\n", current + 1, max_row + 1, max_column + 1);
    }
    fin_res(matrix, res_matrix, rows, columns);
}

/**
* \brief эта функция переставляет строки/столбцы местами
* \details функция ставит строку/столбец таким образом, чтобы на диагонали
* оказался главный элемент
* \param matrix исходная матрица
* \param current текущий элемент
* \param rows количесво строк
* \param max_row, max_column переменные, в которых хранятся индексы максимального элемента
*/


void shift(double **matrix, const int max_row, const int max_column, const int current, const int rows)
{
    double temp_elem = 0.0;
    if (max_column == current)
    {
        double *temp_row = matrix[current];
        matrix[current] = matrix[max_row];
        matrix[max_row] = temp_row;
    }
    else
    {
        for (int row = current; row < rows; row++)
        {
            temp_elem = matrix[row][current];
            matrix[row][current] = matrix[row][max_column];
            matrix[row][max_column] = temp_elem;
        }
    }
}

/**
* \brief эта функция переставляет вычисляет количество ненулевых элемнтов
* \param matrix исходная матрица
* \param rows количесво строк
* \param columns количесво столбцов
*/

int not_null_elems(double **matrix, const int rows, const int columns)
{
    int count = 0;
    for (int temp_row = 0; temp_row < rows; temp_row++)
    {
        for (int temp_column = 0; temp_column < columns; temp_column++)
        {
            if (cmp_w_null(matrix[temp_row][temp_column]))
            {
                count++;
            }
        }
    }
    return count;
}



/**
* \brief эта функция приводит делит строку на значение элемента диагонали
* \param matrix исходная матрица
* \param rows количесво строк
* \param columns количесво столбцов
* \param current текущий элемент
*/



void my_div(double **matrix, const int rows, const int columns, const int current)
{
    double divider = matrix[current][current];
    for (int column = current; column < columns; column++)
    {
        matrix[current][column] /= divider;
    }
}

/**
* \brief эта функция производит вычитание
* \details функция вычитает первую строку из всех нижестоящих для получения нулей
* в текущем столбце под диагональю
* \param rows количесво строк
* \param columns количесво столбцов
* \param current текущий элемент
*/


void sub(double **matrix, const int rows, const int columns, int current)
{
    double factor = 0;
    for (int row = current; row < rows; row++)
    {
        factor = -matrix[row][current - 1];
        for (int column = current - 1; column < columns; column++)
        {
            matrix[row][column] += (factor * matrix[current - 1][column]);
        }
    }
}

/**
* \brief эта функция находит значения неизвестных по получившейся матрице
* \param matrix исходная матрица
* \param res_matrix полученная матрица
* \param rows количесво строк
* \param columns количесво столбцов
*/

void fin_res(double **matrix, double **res_matrix, const int rows, const int columns)
{
    int current = (int)(columns) - 2;
    int x_stage = 1;
    res_matrix[rows - 1][0] = matrix[rows - 1][columns - 1];
    for (int row = rows - 2; row >= 0; row--)
    {
        x_stage = 1;
        for (int column = columns - 2; column >= current; column--)
        {
            matrix[row][columns - 1] -= matrix[row][column] * matrix[rows - x_stage][columns - 1];
            x_stage++;
        }
        current--;
        res_matrix[row][0] = matrix[row][columns - 1];
//        printf("res: %f\n", res_matrix[row][0]);
    }
}

/**
* \brief эта функция производит сложение двух матриц
* \param matrix_first, matrix_second исходные матрицы
* \param rows количесво строк
* \param columns количесво столбцов
* \param positive_elements количество ненулевых элементов
*/

void addition(double **matrix_first, double **matrix_second, const int rows, const int columns, int *positive_elements)
{
    for (int row = 0; row < rows; row++)
    {
        for (int column = 0; column < columns; column++)
        {
            matrix_first[row][column] += matrix_second[row][column];
        }
    }
    *positive_elements = not_null_elems(matrix_first, rows, columns);
}

/**
* \brief эта функция производит перемножение двух матриц
* \param matrix_first, matrix_second исходные матрицы
* \param columns_first_rows_sec количесво строк второй, столбцов первой
* \param rows_first количесво строк первой
* \param columns_second количесво столбцов второй
* \param positive_elements количество ненулевых элементов
*/

double **multiplication(double **matrix_first, double **matrix_second, const int columns_first_rows_sec, const int rows_first, const int columns_second, int *positive_elements)
{
    double **result_matrix = allocate_memory(rows_first, columns_second);
    if (result_matrix)
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
        *positive_elements = not_null_elems(result_matrix, rows_first, columns_second);
    }
    return result_matrix;
}