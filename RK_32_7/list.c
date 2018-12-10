#include <stdio.h>

#include "list.h"
#include "const.h"
#include "io.h"

int list_func(FILE *file)
{
    node_t *head = NULL;
    head = read_all(head, file);
    print_node(head);
    free_list(head);
    return OK;
}

void free_names(node_t *current)
{
    if (current->sec != NULL)
    {
        free(current->sec);
    }
    if (current->name != NULL)
    {
        free(current->name);
    }
}

void free_list(node_t *head)
{
    while(head != NULL)
    {
        free_names(head);
        head = head->next;
        free(head);
    }
}

node_t *elimination(node_t *head, int group)
{
    node_t *temp1 = head;
    while(head != NULL|| head->group != group)
    {
        head = head->next;
    }
    if (head == NULL)
    {
        return temp1;
    }
    return NULL;
}
