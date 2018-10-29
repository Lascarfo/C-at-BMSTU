#include "str_replace.h"
#include "my_getline.h"


void part_changer(char *line, const char *serach, const char *replace)
{
    //на доработке
}

void str_copy(char *line, char *source)
{
    while (*source != '\0')
    {
        *line = *source;
        line++;
        source++;
    }
    *line = *source;
}

char *str_replace(const char *source, const char *serach, const char *replace)
{
    char *line = NULL;
    int len = full_len(source);
    const int replace_len =  full_len(replace);
    line = malloc(len + 1);
    if (line)
    {
        str_copy(line, source);
        int current = 0;
        while (source[current] != '\0')
        {
            if (source[current] == search[0])
            {
                if (part_changer(&line[current], search, replace))
                {
                    current += replace_len;
                }
                else
                {
                    current++;
                }
            }
            else
            {
                current++
            }
        }
    }
    return line;
}
