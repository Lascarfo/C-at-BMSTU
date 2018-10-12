#ifndef _CALCULATINGS_H_
#define _CALCULATINGS_H_

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

#include "const.h"
#include "usage.h"

void addition(double **matrix_first, double **matrix_second, const int rows, const int columns, int *positive_elements);
double **multiplication(double **matrix_first, double **matrix_second, const int columns_first_rows_sec, const int rows_first, const int columns_second, int *positive_elements);
int char_to_int(char num);
bool counter_params(FILE *in);
double **allocate_memory(const int rows, const int columns);
void zero_filling(double **matrix, const int rows, const int columns);
void free_mem(double **matrix, const int rows);

#endif
