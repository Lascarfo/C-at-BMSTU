#ifndef _IO_H_
#define _IO_H_

#include "const.h"


typedef struct discipline dis_t;

struct discipline
{
    int complete;
    int amount;
    char name[10];
    char type[5];
    int priority;
};

node_t *read_data(FILE *in);
dis_t *scan_current(FILE *in);
int scan_all(node_t **head, FILE *in);
void print_data(node_t *head);

#endif
