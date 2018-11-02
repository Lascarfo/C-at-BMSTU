#ifndef _STR_REPLACE_H_
#define _STR_REPLACE_H_

char *str_replace(const char *source, const char *search, const char *replace);
int str_len(const char *source);
int entries_count(const char *source, const char *search, const int len_search);
void feel_func(char *line, const char *source, const char* search, const char* replace, const int len_search);

#endif
