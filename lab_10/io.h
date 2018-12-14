#ifndef _IO_H_
#define _IO_H_

#include "const.h"
#include "list.h"



node_t *read_data(FILE *in);
dis_t *scan_current(FILE *in);
int scan_all(node_t **head, FILE *in);
void print_data(node_t *head);

#endif
