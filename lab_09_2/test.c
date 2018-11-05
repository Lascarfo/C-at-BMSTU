
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_getline.h"
#include "str_replace.h"
#include "const.h"


/**
 \file
 */


 /**
 * \brief строковый компаратор
 * \details сравнивает две строки, поступившие на вход
 */

const bool cmp_strings(const char *first, const char *second)
{
    while (*second != '\0' && *first != '\0')
    {
        printf("132\n");
        if (*first != *second)
        {
            return false;
        }
        first++;
        second++;
    }
    return true;
}

/**
* \brief основная функция программы test.c
* \details функция выполняет модульное тестирование
*/

int main(void)
{
    FILE *file = fopen("test.txt", "r");
    if (!file)
    {
        return ERR_FILE;
    }
    {
        printf("tests for my_getline\n\n");
        printf("1 test: ");
        char *line = NULL;
        size_t size_of_buffer = 0;
        int len = my_getline(&line, &size_of_buffer, file);
        if (len == ERR_MEMORY)
        {
            return ERR_FILE;
        }
        const char expect[] = {'f', 'i', 'r', 's', 't', '\0'};
        if (cmp_strings(expect, line))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
        free(line);
    }
    {
        printf("2 test: ");
        char *line = NULL;
        size_t size_of_buffer = 0;
        int len = my_getline(&line, &size_of_buffer, file);
        if (len == ERR_MEMORY)
        {
            return ERR_FILE;
        }
        const char expect[] = {'s', 'e', 'c', 'o', 'n', 'd', '\0'};
        if (cmp_strings(expect, line))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
        free(line);
    }
    {
        printf("3 test: ");
        char *line = NULL;
        size_t size_of_buffer = 0;
        int len = my_getline(&line, &size_of_buffer, file);
        if (len == ERR_MEMORY)
        {
            return ERR_FILE;
        }
        const char expect[] = "third";
        if (cmp_strings(expect, line))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
        free(line);
    }
    {
        printf("4 test: ");
        char *line = NULL;
        size_t size_of_buffer = 0;
        int len = my_getline(&line, &size_of_buffer, file);
        if (len == ERR_MEMORY)
        {
            return ERR_FILE;
        }
        const char expect[] = "fourth";
        if (cmp_strings(expect, line))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    fclose(file);
    /*
    {
        printf("\ntests for str_replace\n\n");
        printf("1 test: ");
        const char *string = "AAA";
        const char *check = "B";
        char *result = NULL;
        result = str_replace(string, "AAA", "B");
        if (result == NULL)
        {
            return ERR_MEMORY;
        }
        printf("result %s\n", result);
        printf("check %s\n", check);

        // if (cmp_strings(result, check))
        // {
        //     printf("passed\n");
        // }
        // else
        // {
        //     printf("not passed\n");
        // }
        free(result);

    }
    */ 
    return 0;
}
