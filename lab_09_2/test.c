
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "my_getline.h"
#include "str_replace.h"


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
        printf("tests for my_getline\n\n");
        
    }
    {
        printf("\ntests for str_replace\n\n");
    }
    return 0;
}
