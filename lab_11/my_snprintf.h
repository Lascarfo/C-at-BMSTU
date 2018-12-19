#ifndef _MY_SNPRINTF_
#define _MY_SNPRINTF_

#include <stdbool.h>

int my_snprintf(char *string, size_t n, const char *format, ...);
int full_len(const char *symbols);
int calculate_size(const char *format, va_list args);
void dec_to_hex(char *buffer, int n, int len, unsigned short int number);
void dec_to_oct(char *buffer, int n, int len, unsigned int number);
int len_dec_to_hex(unsigned short int number);
int len_dec_to_oct(unsigned int number);
void write_string(char *string, const char *format, size_t n, va_list args);
char *sym_copy(char *line, const char *symbols, size_t len);
const bool cmp_n_strings(const char *first, const char *second, const int len);

#endif
