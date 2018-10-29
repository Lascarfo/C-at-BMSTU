#ifndef _IO_H_
#define _IO_H_

int read_params(FILE *file, int *rows, int *columns);
int read_matrix(FILE *file, double **matrix, const int rows, const int columns);

#endif
