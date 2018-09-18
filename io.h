// io.h

#ifndef _IO_H_
#define _IO_H_
#include <stdio.h>

int count_n(FILE *file);
int read_array(FILE *file, int *arr, int *arr_end);
int read(FILE *file, int **arr, int **arr_end);
int save(FILE *file, const int *arr, const int *arr_end);
void print(const int *arr, const int *arr_end);

#endif
