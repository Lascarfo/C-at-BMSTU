
/**
 \file
*/

#include "str_replace.h"
#include "my_getline.h"


/**
* \brief функция, выполняющая замену
* \details эта функция выполняет замену в поданой строке source
* строки search на строку replace
*/

char *str_replace(const char *source, const char *search, const char *replace)
{
    char *line = NULL;
    const int source_len = str_len(source);
    const int search_len = str_len(search);
    const int replace_len = str_len(replace);
    const int entries = entries_count(source, search, search_len);
    line = malloc(source_len + entries * (replace_len - search_len) + 1);
    if (line)
    {
        feel_func(line, source, search, replace, search_len);
//        printf("string: %s\n", line);
    }

    return line;
}

/**
* \brief функция считает длину строки
*/

int str_len(const char *source)
{
    int len = 0;
    while (*source != '\0')
    {
        len++;
        source++;
    }
    return len;
}


/**
* \brief функция считает количество вхождений seach в source
*/

int entries_count(const char *source, const char *search, const int len_search)
{
    int count = 0;
    const char *temp = search;
    while (*source != '\0')
    {
        if (*source == *search)
        {
            while (*search == *source)
            {
                search++;
                source++;
            }
            if ((search - temp) == len_search)
            {
                count++;
            }
            search = temp;
        }
        else
        {
            source++;
        }
    }
    return count;
}


/**
* \brief функция, выполняющая заполнение строки
* \details эта функция заполняет строку line, заменяя search на replace в ходе
* выполнения цикла
*/

void feel_func(char *line, const char *source, const char* search, const char* replace, const int len_search)
{
    const char *temp_search = search;
    const char *temp_replace = replace;
    const char *temp_source = source;
    while (*source != '\0')
    {
        if (*source == *search)
        {
            temp_source = source;
            while (*search == *source && *source != '\0')
            {
                search++;
                source++;
            }
            source = temp_source;
            if ((search - temp_search) == len_search)
            {
                while (*replace != '\0')
                {
                    *line = *replace;
                    line++;
                    replace++;
                }
				source += len_search;
                replace = temp_replace;
            }
            else
            {
                *line = *source;
                line++;
                source++;
            }
			search = temp_search;
        }
        else
        {
            *line = *source;
            line++;
            source++;
        }
    }
    *line = '\0';
}
