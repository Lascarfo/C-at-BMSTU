#ifndef _IO_H_
#define _IO_H_
#include <stdio.h>


int arithmetic(char **argv);
int read_matrix(FILE *in, double *matrix[]);
void read_params(FILE *in, int *rows, int *columns, int *positive_elements);
void print_matrix(double *matrix[]);

#endif
