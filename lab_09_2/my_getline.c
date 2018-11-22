
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
*/

int my_getline(char **lineptr, size_t *n, FILE *stream)
{
    if (feof(stream) || lineptr == NULL)
    {
        return ERR_MEMORY;
    }
    int sym_count = 0, full_count = 0;
    char cache[BUFFER];
    if (*lineptr)
    {
        while (feof(stream) == 0 && *(*lineptr + full_count - 1) != '\n')
        {
            if (fgets(cache, BUFFER, stream) != NULL)
            {
                sym_count = str_len(cache);
                if (*n >= sym_count && full_count == 0)
                {
                    sym_copy(*lineptr, cache, sym_count);
                }
                else if (*n < sym_count && full_count == 0)
                {
                    *n += BUFFER;
                    *lineptr = realloc(*lineptr, *n);
                    sym_copy(*lineptr, cache, sym_count);
                }
                else
                {
                    sym_copy(*lineptr + full_count, cache, sym_count);
                }
                full_count += sym_count;
                if (sym_count != BUFFER - 1)
                {
                    return full_count;
                }
                *n += BUFFER;
                *lineptr = realloc(*lineptr, *n);
            }
        }
    }
    else
    {
        *lineptr = malloc(BUFFER);
        if (*lineptr)
        {
            while (feof(stream) == 0 && *(*lineptr + full_count - 1) != '\n')
            {
                if (fgets(cache, BUFFER, stream) != NULL)
                {
                    sym_count = str_len(cache);
                    sym_copy(*lineptr + full_count, cache, sym_count);
                    full_count += sym_count;
                    if (sym_count != BUFFER - 1)
                    {
                        return full_count;
                    }
                    *n += BUFFER;
                    *lineptr = realloc(*lineptr, *n);
                }
            }
        }
        else
        {
            full_count = ERR_MEMORY;
        }
    }
    return full_count;
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


// bool end_of_line(const char *line, const int sym_count)
// {
//     for (int symbol = 0; symbol < sym_count; symbol++)
//     {
//         if (*line == '\0' || symbol == sym_count - 1)
//         {
//             return true;
//         }
//         line++;
//     }
//     return false;
// }
