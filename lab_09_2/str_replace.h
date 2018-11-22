#ifndef _STR_REPLACE_H_
#define _STR_REPLACE_H_

#include <stdbool.h>

char *str_replace(const char *source, const char *search, const char *replace);
int str_len(const char *source);
int entries_count(const char *source, const char *search, const int len_search);
void feel_func(char *line, const char *source, const char *search, const char *replace, const int len_search);
bool substring(const char *line, const char *subline, const int len_search);

#endif
