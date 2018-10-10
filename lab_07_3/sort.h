#ifndef _SORT_H_
#define _SORT_H_

void swap(void *left, void *right, size_t size);
int cmp_int(const void *left, const void *right);
int cmp_char(const void *left, const void *right);
int cmp_double(const void *left, const void *right);
void mysort(void *base, size_t nitems, size_t size, int(*cmp_int)(const void*, const void*));

#endif
