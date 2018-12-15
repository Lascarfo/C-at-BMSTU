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

int form_func(FILE *file, int group)
{
    node_t *head = NULL;
    head = read_all(head, file);
    head = elimination(head, group);
    print_node(head);
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
    node_t *temp = NULL;
    while(head != NULL)
    {
        free_names(head);
        temp = head->next;
        free(head);
        head = temp;
    }
}

node_t *elimination(node_t *head, int group)
{
    node_t *current = head;
    node_t *next_e = head->next;
    node_t *temp;
    node_t *temp_head = head;
    while (next_e != NULL)
    {
        if (next_e->group == group)
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
            insert_first(&head, temp, temp_head);
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

void insert_first(node_t **head, node_t *elem, node_t *before)
{
    if (head == NULL || *head == NULL)
    {
        return;
    }
    node_t *next_temp = (*head)->next;
    node_t *temp = *head;
    *head = elem;
    (*head)->next = temp;
    temp->next = next_temp;
}
