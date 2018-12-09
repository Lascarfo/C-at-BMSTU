#ifndef _LIST_H_
#define _LIST_H_

int execution(FILE *in);
void *pop_back(node_t **head);
void insert(node_t **head, node_t *elem, node_t *before);

#endif
