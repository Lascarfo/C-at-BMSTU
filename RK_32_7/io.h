#ifndef _IO_H_
#define _IO_H_

#include <stdlib.h>

#include "list.h"

node_t *read_all(node_t *head, FILE *file);
node_t *read_current(FILE *file);
char *read_string(FILE *file);
int read_int(FILE *file);
void print_node(node_t *head);

#endif
