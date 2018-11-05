#ifndef _STRING_F_
#define _STRING_F_

#include <stdio.h>

int my_strcspn(const char *symbols, const char *deps);
char *my_strndup(const char *symbols, size_t len);
int full_len(const char *symbols);
char *sym_copy(char *line, const char *symbols, size_t len);

#endif
