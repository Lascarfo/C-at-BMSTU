
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
    if (!stream)
    {
        return ERR_FILE;
    }
    if (lineptr == NULL)
    {
        return ERR_MEMORY;
    }
    int sym_count = 0, len = 0;
    *lineptr = malloc(BUFFER);
    *n = BUFFER;
    char tmp[BUFFER];
    if (*lineptr)
    {
        while (feof(stream) == 0 || *(*lineptr + len - 1) != '\n')
        {
            if (fgets(tmp, BUFFER, stream) != NULL)
            {
                sym_count = str_len(tmp);
                sym_copy(*lineptr + len, tmp, sym_count);
                len += sym_count;
                if (end_of_line(*lineptr, len))
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



void sym_copy(char *line, const char *symbols, size_t len)
{
    if (len == 0)
    {
        *line = '\0';
    }
    while (len != 0)
    {
        *line = *symbols;
        printf("iter %zu\n", len);
        printf("line %c\n", *line);
        line++;
        symbols++;
        len--;
    }
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
