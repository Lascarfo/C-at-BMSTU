#ifndef _CALCULATINGS_H_
#define _CALCULATINGS_H_

#include <stdbool.h>
#include <ctype.h>
#include <stdlib.h>

#include "const.h"
#include "usage.h"

int addition(FILE *file_in_1, FILE *file_in_2);
int multiplication(FILE *file_in_1, FILE *file_in_2);
int char_to_int(char num);
bool counter_params(FILE *in);
double **allocate_memory(const int rows, const int columns);
void zero_filling(double **matrix, const int rows, const int columns);


#endif
