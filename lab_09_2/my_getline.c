
/**
 \file
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

#include "my_getline.h"
#include "str_replace.h"
#include "string.h"
#include "const.h"


/**
* \brief функция считывает строку из выделенного потока
* \param lineptr, указатель на указатель на строку, в которую попадет финальная строка
* \param n размер буфера
* \param stream файл, из которого происходит считывание
*/

int my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (!stream)
    {
        return ERR_FILE;
    }
    if (lineptr == NULL)
    {
        return ERR_MEMORY;
    }
    if (feof(stream))
    {
        return 0;
    }
    int full_count = 0;
    if (*lineptr)
    {
        full_count = prepared_line(lineptr, n, stream);
    }
    else
    {
        full_count = not_prepared_line(lineptr, n, stream);
    }
    return full_count;
}


/**
* \brief функция производит считывание для строки с буфером, выделенным пользователем
* \param lineptr, указатель на указатель на строку, в которую попадет финальная строка
* \param n размер буфера
* \param stream файл, из которого происходит считывание
*/

int prepared_line(char **lineptr, size_t *n, FILE *stream)
{
    char cache[BUFFER];
    int sym_count = 0, full_count = 0, buff_count = 0;
    while (!end_of_line(*lineptr, full_count))
    {
        if (fgets(cache, BUFFER, stream) != NULL)
        {
            sym_count = str_len(cache);
            buff_count += sym_count;
            if (*n >= buff_count)
            {
                sym_copy(*lineptr + full_count, cache, sym_count);
            }
            else if (*n < buff_count)
            {
                *n += BUFFER;
                char *tmp = realloc(*lineptr, *n);
                if (tmp)
                {
                    *lineptr = tmp;
                }
                else
                {
                    free(*lineptr);
                    return ERR_MEMORY;
                }
                sym_copy(*lineptr + full_count, cache, sym_count);
            }
            full_count += sym_count;
            if (end_of_line(*lineptr, full_count))
            {
                return full_count;
            }
        }
        else
        {
            return full_count;
        }
    }
    return full_count;
}

/**
* \brief функция производит считывание для строки с невыделенным буфером
* \param lineptr, указатель на указатель на строку, в которую попадет финальная строка
* \param n размер буфера
* \param stream файл, из которого происходит считывание
*/

int not_prepared_line(char **lineptr, size_t *n, FILE *stream)
{
    int sym_count = 0, full_count = 0;
    char cache[BUFFER];
    *lineptr = malloc(BUFFER);
    *n = BUFFER;
    if (*lineptr)
    {
        while (!end_of_line(*lineptr, full_count))
        {
            if (fgets(cache, BUFFER, stream) != NULL)
            {
                sym_count = str_len(cache);
                sym_copy(*lineptr + full_count, cache, sym_count);
                full_count += sym_count;
                if (end_of_line(*lineptr, full_count))
                {
                    return full_count;
                }
                *n += BUFFER;
                char *tmp = realloc(*lineptr, *n);
                if (tmp)
                {
                    *lineptr = tmp;
                }
                else
                {
                    free(*lineptr);
                    return ERR_MEMORY;
                }
            }
            else
            {
                return full_count;
            }
        }
    }
    else
    {
        full_count = ERR_MEMORY;
    }
    return full_count;
}

/**
* \brief функция производит посимвольное копирование из буффера в конечную строку
* \param line конечная строка
* \param symbols буффер
* \param len размер строки в буффере
*/

void sym_copy(char *line, const char *symbols, size_t len)
{
    if (len == 0)
    {
        *line = '\0';
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
}



/**
* \brief функция определяет наличие детерменирующего нуля в конце строки
* \param line конечная строка
* \sym_count длина строки
*/

bool end_of_line(const char *line, const int sym_count)
{
    for (int symbol = 0; symbol < sym_count; symbol++)
    {
        if (*line == '\0' || symbol == sym_count - 1)
        {
            return true;
        }
        line++;
    }
    return false;
}
