#ifndef _LIST_H_
#define _LIST_H_

#include <stdbool.h>

typedef struct discipline dis_t;

struct discipline
{
    int complete;
    int amount;
    char name[10];
    char type[5];
    int priority;
};

int execution(FILE *in);
void *pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);
node_t *reverse(node_t *head);
bool cmp_int(const void *first, const void *second);
node_t* sort(node_t *head, bool (*comparator)(const void *, const void *));
void sorted_insert(node_t **head, node_t *element, \
    bool (*comparator)(const void *, const void *));

#endif
