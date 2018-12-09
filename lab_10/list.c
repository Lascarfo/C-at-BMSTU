

#include <stdlib.h>
#include <stdio.h>

#include "const.h"
#include "list.h"
#include "io.h"


int execution(FILE *in)
{
    node_t *head = NULL;
    head = read_data(in);
    pop_back(&head);


    // printf("CACHE %s\n", cache->name);
    // printf("HEAD %p\n", (void*)(head));


    return OK;
}


void *pop_back(node_t **head)
{
    if (head == NULL || *head == NULL)
    {
        return NULL;
    }
    void *c_data = NULL;
    node_t *next_temp = (*head)->next;
    if (next_temp == NULL)
    {
        c_data = (*head)->data;
        free(*head);
        *head = NULL;
        return c_data;
    }
    node_t *temp = *head;
    while (next_temp->next != NULL)
    {
        temp = temp->next;
        next_temp = next_temp->next;
    }
    if (temp)
    {
        c_data = next_temp->data;
        temp->next = NULL;
        free(next_temp);
        return c_data;
    }
    return c_data;
}

 void insert(node_t **head, node_t *elem, node_t *before)
 {
     if (head == NULL || *head == NULL)
     {
         return;
     }
     node_t *next_temp = (*head)->next;
     node_t *temp = *head;
     if (next_temp == NULL)
     {
         *head = elem;
         next_temp = temp;
     }
     else
     {
         while (next_temp->next != NULL)
         {
             temp = temp->next;
             next_temp = next_temp->next;
             if (next_temp == before)
             {
                 break;
             }
         }

     }
 }
