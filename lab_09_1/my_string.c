#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 \file
 */


 /**
 * \brief эта функция считает количество символов с условием
 * \details на вход поступает два массива символов; первый –– строка, в которой ищем, второй –– строка, с которой сравниваем.
 * Предназначение функции –– найти первое вхождение любого символа из массива deps в массив symbols и вернуть количество предшедствующих
 * символов.
 */

int my_strcspn(const char *symbols, const char *deps)
{
    int size = 0;
    const char *deps_temp = deps;
    while (*symbols != '\0')
    {
        while (*deps_temp != '\0')
        {
            if (*symbols == *deps_temp)
            {
                return size;
            }
            deps_temp++;
        }
        deps_temp = deps;
        symbols++;
        size++;
    }
    return size;
}

/**
* \brief эта функция производит копирование переданной с параметром длины
* \details на вход поступает массив символов и количество символов, которое нужно
* скопировать в новый массив. Память под новый массив выделяется динамически.
* Если переданная длина больше длины строки, то копируется вся строка, если меньше,
* то строка обрезается. При возникновении ошибки функция возвращает NULL.
*/

char *my_strndup(const char *symbols, size_t len)
{
    if (symbols == NULL)
    {
        return NULL;
    }
    char *drop = NULL;
    int temp_len = 0;
    temp_len = full_len(symbols);
    if (temp_len < len || len != 0)
    {
        len = temp_len;
    }
    drop = malloc(len + 1);
    if (drop)
    {
        sym_copy(drop, symbols, len);
    }
    return drop;
}


char *sym_copy(char *line, const char *symbols, size_t len)
{
    if (len == 0)
    {
        *line = '\0';
        return line;
    }
    while (len != 0)
    {
        *line = *symbols;
        line++;
        symbols++;
        len--;
        // printf("iter %zu\n", len);
        // printf("line %c\n", *line);
    }
    *line = '\0';
    return line;
}


int full_len(const char *symbols)
{
    int len = 0;
    while (*symbols != '\0')
    {
        symbols++;
        len++;
    }
    return len;
}
