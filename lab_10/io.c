#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#include "io.h"




node_t *read_data(FILE *in)
{
    node_t *head = NULL;
    int rc = 0;
    rc = scan_all(&head, in);
    return head;
}



dis_t *scan_current(FILE *in)
{
    dis_t *current = malloc(sizeof(dis_t));
    if (current)
    {
        if (fscanf(in, "%d %d %s %s %d", &(current->complete), &(current->amount), \
        (current->name), (current->type), &(current->priority)) == 5)
        {
            return current;
        }
        else
        {
            free(current);
            return NULL;
        }
    }
    else
    {
        return NULL;
    }
}

int scan_all(node_t **head, FILE *in)
{
    node_t *tmp = NULL;
    node_t *cache = NULL;
    dis_t *current = NULL;
    bool flag = false;
    while ((current = scan_current(in)) != NULL)
    {
        if (flag)
        {
            tmp = tmp->next;
            tmp = malloc(sizeof(node_t));
            if (!tmp)
            {
                free(current);
                return ERR_MEMORY;
            }
            cache->next = tmp;
        }
        else
        {
            tmp = malloc(sizeof(node_t));
            if (!tmp)
            {
                return ERR_MEMORY;
            }
            *head = tmp;
        }
        flag = true;
        tmp->data = current;
        cache = tmp;
        // printf("%p\n", (void*)(tmp));
    }
    if (tmp)
    {
        tmp->next = NULL;
    }
    return OK;
}


void print_data(node_t *head)
{
    dis_t *current = NULL;
    while (head != NULL)
    {
        current = head->data;
        printf("complete: %d amount: %d discipline: %-8s type: %-5s priority: %d\n",current->complete,\
        current->amount, current->name, current->type, current->priority);
        head = head->next;
    }
}
