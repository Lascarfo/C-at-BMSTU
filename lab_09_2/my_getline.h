#ifndef _MY_GETLINE_
#define _MY_GETLINE_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int my_getline(char **lineptr, size_t *n, FILE *stream);
bool end_of_line(const char *line, const int sym_count, unsigned int *length);

#endif
