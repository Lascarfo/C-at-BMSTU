#ifndef _IO_H_
#define _IO_H_

#include <stdio.h>


int arithmetic(char **argv);
int read_matrix(FILE *in, double ***matrix, int *rows, int *columns, int *positive_elements);
void read_params(FILE *in, int *rows, int *columns, int *positive_elements);
int read_elems(FILE *in, const int rows, const int columns, const int positive_elements, double **matrix);
void save(FILE *out, double **matrix, const int rows, const int columns, const int positive_elements);
void print_matrix(double **matrix, const int rows, const int columns, const int positive_elements);

#endif
