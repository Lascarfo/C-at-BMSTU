#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>

typedef struct node node_t;

struct node
{
    char *sec;
    char *name;
    int year;
    int group;
    node_t *next;
};

int list_func(FILE *file);
void free_names(node_t *current);
void free_list(node_t *head);
node_t *elimination(node_t *head, int group);

#endif
