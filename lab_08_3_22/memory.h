#ifndef _MEMORY_H_
#define _MEMORY_H_

double **allocate_memory(const int rows, const int columns);
void free_mem(double **matrix, const int rows);

#endif
