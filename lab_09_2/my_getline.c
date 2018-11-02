
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
    int sym_count = 0;
    *lineptr = malloc(BUFFER);
    if (*lineptr)
    {
        while(feof(stream) == 0)
        {
            if (fgets(*lineptr + sym_count, BUFFER, stream) != NULL)
            {
                sym_count = str_len(*lineptr);
                if (end_of_line(*lineptr, sym_count))
                {
                    return sym_count;
                }
                *n += BUFFER;
                *lineptr = realloc(*lineptr, *n);
            }
        }
    }
    else
    {
        sym_count = ERR_MEMORY;
    }
    return sym_count;
}

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
