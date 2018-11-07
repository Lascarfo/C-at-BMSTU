
/**
 \file
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#include "usage.h"
#include "const.h"
#include "str_replace.h"
#include "my_getline.h"

void save(FILE *out, const char *source);

 /**
 * \brief строковый компаратор
 * \details сравнивает две строки, поступившие на вход
 */

const bool cmp_strings(const char *first, const char *second)
{
    int count = 0;
    while (second[count] != '\0' || first[count] != '\0')
    {
        if (first[count] != second[count])
        {
            return false;
        }
        count++;
    }
    if (second[count] == '\0' && first[count] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
}


/**
* \brief точка входа
* \details функция демонстрирует работу функций my_getline и str_replace
*/

int main(int argc, char *argv[])
{
    int rc = OK;
    FILE *in;
    FILE *out;
    if (argc == 7 && (strcmp(argv[5], "-r") == 0) && (strcmp(argv[3], "-s") == 0))
    {
        in = fopen(argv[1], "r");
        if (in)
        {
            char *line_get = NULL;
            size_t size_of_buffer = 0;
            int len = my_getline(&line_get, &size_of_buffer, in);
            if (line_get)
            {
                if (len != ERR_MEMORY)
                {
                    char *line_replace = NULL;
                    line_replace = str_replace(line_get, argv[4], argv[6]);
                    if (line_replace)
                    {
                        out = fopen(argv[2], "w");
                        if (out)
                        {
                            save(out, line_replace);
                            fclose(out);
                        }
                        else
                        {
                            rc = ERR_FILE;
                        }
                        free(line_replace);
                    }
                }
                else
                {
                    rc = ERR_MEMORY;
                }
                free(line_get);
            }
            fclose(in);
        }
        else
        {
            usage();
            rc = ERR_FILE;
        }
    }
    else
    {
        usage();
        rc = ERR_INPUT;
    }
    return rc;
}

/**
* \brief функция, для записи в файл
*/

void save(FILE *out, const char *source)
{
    fprintf(out, "%s\n", source);
}
