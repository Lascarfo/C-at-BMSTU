#ifndef _CALCULATINGS_H_
#define _CALCULATINGS_H_

#include <stdbool.h>

bool cmpr_rows(double *row1, double *row2, const int columns);
void sort_matrix(double **matrix, const int rows, const int columns);
unsigned int unique_elems(double *row, int columns);
int cmp_double(double left, double right);

#endif
