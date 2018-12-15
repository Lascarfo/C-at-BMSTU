
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "io.h"
#include "const.h"


node_t *read_all(node_t *head, FILE *file)
{
    bool flag = true;
    node_t *current = NULL;
    node_t *tmp = NULL;
    while((current = read_current(file)) != NULL)
    {
        if (flag)
        {
            head = current;
            tmp = head;
            flag = false;
        }
        else
        {
            tmp->next = current;
            tmp = tmp->next;
        }
    }
    return head;
}

node_t *read_current(FILE *file)
{
    node_t *current = malloc(sizeof(node_t));
    if (current)
    {
        current->sec = read_string(file);
        current->name = read_string(file);
        current->year = read_int(file);
        current->group = read_int(file);
        current->next = NULL;
        if (current->sec == NULL || current->name == NULL)
        {
            free_names(current);
            free(current);
            return NULL;
        }
        else
        {
            return current;
        }
    }
    return NULL;
}

char *read_string(FILE *file)
{
    char str[70];
    if (fscanf(file, "%s", str) != 1)
    {
        return NULL;
    }
    int length = strlen(str);
    if (length > 0)
    {
        char *string = malloc(length * sizeof(char) + 1);
        if (string)
        {
            strcpy(string, str);
            return string;
        }
        else
        {
            return NULL;
        }
    }
    return NULL;
}

int read_int(FILE *file)
{
    int tmp = 0;
    if (fscanf(file, "%d", &tmp) != 1)
    {
        return 0;
    }
    return tmp;
}

void print_node(node_t *head)
{
    while(head != NULL)
    {
        printf("%s %s %d %d\n", head->sec, head->name, head->year, head->group);
        head = head->next;
    }
}
