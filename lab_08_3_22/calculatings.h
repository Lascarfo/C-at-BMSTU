#ifndef _CALCULATINGS_H_
#define _CALCULATINGS_H_

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "const.h"
#include "usage.h"

int gauss(char **argv);
int arithmetic(char **argv);
void addition(double **matrix_first, double **matrix_second, const int rows, const int columns, int *positive_elements);
double **multiplication(double **matrix_first, double **matrix_second, const int columns_first_rows_sec, const int rows_first, const int columns_second, int *positive_elements);
void zero_filling(double **matrix, const int rows, const int columns);
void method(double **matrix, double **res_matrix, const int rows, const int columns);
bool cmp_double(double left, double right);
void index_of_max(const double **matrix, const int current, const int rows, int *max_rows, int *max_columns);
void shift(double **matrix, const int max_row, const int max_column, const int current, const int rows);
void my_div(double **matrix, const int rows, const int columns, const int current);
void sub(double **matrix, const int rows, const int columns, int current);
void fin_res(double **matrix, double **res_matrix, const int rows, const int columns);
int not_null_elems(double **matrix, const int rows, const int columns);


#endif
