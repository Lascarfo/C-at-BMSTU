#ifndef _LIB_H_
#define _LIB_H_

#include <stdio.h>

#define OK 0
#define ERR_MEMORY -1
#define ERR_ARRAY -2
#define ERR_FILE -3
#define ERR_EMPTY -4
#define ERR_PRINT -5
#define ERR_PARAM -6

#define N 50

const int *count_pos(const int *arr, const int *arr_end);
void copy_arr(const int *arr, int *arr_s, int *arr_s_end);
int key(const int *arr, const int *arr_end, int *arr_n, int *arr_n_end);
void calculate(const int *arr, const int *arr_end, int *len);
int count_n(FILE *file);
int read_array(FILE *file, int *arr, int *arr_end);
int read(FILE *file, int **arr, int **arr_end);
int save(FILE *file, const int *arr, const int *arr_end);
void print(const int *arr, const int *arr_end);
void print_double(const double *arr, const double *arr_end);
void print_char(const char *arr, const char *arr_end);
void swap(void *left, void *right, size_t size);
int cmp_int(const void *left, const void *right);
int cmp_char(const void *left, const void *right);
int cmp_double(const void *left, const void *right);
void mysort(void *base, size_t nitems, size_t size, int(*cmp_int)(const void*, const void*));
void usage(void);


#endif
