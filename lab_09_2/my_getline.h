#ifndef _MY_GETLINE_
#define _MY_GETLINE_

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

int my_getline(char **lineptr, size_t *n, FILE *stream);
bool end_of_line(const char *line, const int sym_count);
char *sym_copy(char *line, const char *symbols, size_t len);

#endif
