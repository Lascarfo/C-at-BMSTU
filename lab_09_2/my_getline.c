#include "my_getline.h"
#include "string.h"
#include "const.h"

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
                sym_count = full_len(*lineptr);
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
