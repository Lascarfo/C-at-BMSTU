#ifndef _SORT_H_
#define _SORT_H_

void swap (void *left, void *right, size_t size);
int cmp_int(const void *left, const void *right);
void sort(void *base, void *base_end, size_t size, int(*cmp_int)(const void*, const void*));

#endif
