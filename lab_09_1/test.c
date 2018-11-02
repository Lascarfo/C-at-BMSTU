
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_string.h"


/**
 \file
 */


 /**
 * \brief строковый компаратор
 * \details сравнивает две строки, поступившие на вход
 */

const bool cmp_strings(const char *first, const char *second)
{
    int count = 0;
    while (second[count] != '\0' && first[count] != '\0')
    {
        if (first[count] != second[count])
        {
            return false;
        }
        count++;
    }
    return true;
}

/**
* \brief основная функция программы test.c
* \details функция выполняет модульное тестирование
*/

int main(void)
{
    {
        printf("tests for my_strcspn\n\n");
        const char first[] = "3.141592653589793238";
        const char second[] = "";
        const int res = strcspn(first, second);
        const int size = my_strcspn(first, second);
        if (res == size)
        {
            printf("test 1 passed\n");
        }
        else
        {
            printf("test 1 not passed\n");
        }
    }
    {
        const char first[] = "3.141592653589793238";
        const char second[] = "1";
        const int res = strcspn(first, second);
        const int size = my_strcspn(first, second);
        if (res == size)
        {
            printf("test 2 passed\n");
        }
        else
        {
            printf("test 2 not passed\n");
        }
    }
    {
        const char first[] = "3.141592653589793238";
        const char second[] = "3";
        const int res = strcspn(first, second);
        const int size = my_strcspn(first, second);
        if (res == size)
        {
            printf("test 3 passed\n");
        }
        else
        {
            printf("test 3 not passed\n");
        }
    }
    {
        printf("\ntests for my_strndup\n\n");
        bool flag = false;
        char *mind = NULL;
        char *not_mind = NULL;
        const char first[] = "3.141592653589793238";
        const int barrier = 4;
        mind = my_strndup(first, barrier);
        not_mind = strndup(first, barrier);
        // printf("my_strndup: %s\n", mind);
        // printf("strndup: %s\n", not_mind);
        flag = cmp_strings(mind, not_mind);
        if (flag)
        {
            printf("test 1 passed\n");
        }
        else
        {
            printf("test 1 not passed\n");
        }
    }
    {
        bool flag = false;
        char *mind = NULL;
        char *not_mind = NULL;
        const char first[] = "3.141592653589793238";
        const int barrier = 2;
        mind = my_strndup(first, barrier);
        not_mind = strndup(first, barrier);
        flag = cmp_strings(mind, not_mind);
        if (flag)
        {
            printf("test 2 passed\n");
        }
        else
        {
            printf("test 2 not passed\n");
        }
    }
    {
        bool flag = false;
        char *mind = NULL;
        char *not_mind = NULL;
        const char first[] = "3.141592653589793238";
        const int barrier = 0;
        mind = my_strndup(first, barrier);
        not_mind = strndup(first, barrier);
        flag = cmp_strings(mind, not_mind);
        if (flag)
        {
            printf("test 3 passed\n");
        }
        else
        {
            printf("test 3 not passed\n");
        }
    }
    {
        bool flag = false;
        char *mind = NULL;
        char *not_mind = NULL;
        const char first[] = "3.141592653589793238";
        const int barrier = -1;
        mind = my_strndup(first, barrier);
        not_mind = strndup(first, barrier);
        flag = cmp_strings(mind, not_mind);
        if (flag)
        {
            printf("test 4 passed\n");
        }
        else
        {
            printf("test 4 not passed\n");
        }
    }
    return 0;
}
