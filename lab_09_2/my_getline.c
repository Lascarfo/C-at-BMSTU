
/**
 \file
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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
        while(!feof(stream))
        {
            if (fgets(*lineptr + sym_count, BUFFER, stream) != NULL)
            {
                sym_count = str_len(*lineptr);
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
