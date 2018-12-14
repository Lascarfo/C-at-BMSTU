

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "const.h"
#include "list.h"
#include "io.h"



bool cmp_int(const void *first, const void *second)
{
    dis_t *num_1 = ((node_t *)(first))->data;
    dis_t *num_2 = ((node_t *)(second))->data;
    if (num_1->complete > num_2->complete)
    {
        return true;
    }
    else
    {
        return false;
    }

}


int execution(FILE *in)
{
    node_t *head = NULL;
    head = read_data(in);
    head = sort(head, cmp_int);
    // sorted_insert(&head, .., cmp_int);
    // head = reverse(head);
    // pop_back(&head);
    // insert(&head, temp1, temp2);
    print_data(head);

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
     bool flag = false;
     node_t *next_temp = (*head)->next;
     node_t *temp = *head;
     if (*head == before)
     {
         *head = elem;
         (*head)->next = temp;
         temp->next = next_temp;
     }
     else
     {
         while (next_temp->next != NULL)
         {
             if (next_temp == before)
             {
                 flag = true;
                 break;
             }
             temp = temp->next;
             next_temp = next_temp->next;
         }
         if (flag)
         {
             temp->next = elem;
             elem->next = next_temp;
         }
     }
 }


node_t *reverse(node_t *head)
{
    if (head == NULL)
    {
        return NULL;
    }
    node_t *curr = NULL, *next = NULL, *prev = NULL;
    curr = head;
    while(curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}



 node_t* sort(node_t *head, bool (*comparator)(const void *, const void *))
 {
     if (head == NULL)
     {
         return NULL;
     }
     node_t *current = head;
     node_t *next_e = head->next;
     node_t *temp;
     node_t *temp_head = head;
     while (next_e != NULL)
     {
         if ((*comparator)(current, next_e))
         {
             temp = next_e;
             if (next_e->next != NULL)
             {
                 current->next = next_e->next;
                 next_e = next_e->next;
                 next_e->next = next_e->next;
             }
             else
             {
                 current->next = NULL;
                 next_e = NULL;
             }
             while (!(*comparator)(temp_head, temp))
             {
                 temp_head = temp_head->next;
             }
             insert(&head, temp, temp_head);
             temp_head = head;
         }
         else
         {
             current = current->next;
             next_e = next_e->next;
         }
     }
     return head;
 }



void sorted_insert(node_t **head, node_t *element, \
    bool (*comparator)(const void *, const void *))
{
    if (head == NULL || *head == NULL || element == NULL)
    {
        return;
    }
    node_t *last = NULL;
    node_t *current = *head;
    while (current != NULL)
    {
        if ((*comparator)(current, element))
        {
            insert(head, element, current);
            return;
        }
        else
        {
            if (current->next == NULL)
            {
                last = current;
            }
            current = current->next;
        }
    }
    last->next = element;
    element->next = NULL;
}
