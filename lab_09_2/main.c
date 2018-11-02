
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
    while (second[count] != '\0' && first[count] != '\0')
    {
        if (first[count] != second[count])
        {
            return false;
        }
        count++;
    }
    return true;
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
            char *line = NULL;
            size_t size_of_buffer = 0;
            int len = my_getline(&line, &size_of_buffer, in);
            if (len != ERR_MEMORY)
            {
                line = str_replace(line, argv[4], argv[6]);
                out = fopen(argv[2], "w");
                if (out)
                {
                    save(out, line);
                    free(line);
                    fclose(out);
                }
                else
                {
                    free(line);
                    fclose(in);
                    rc = ERR_FILE;
                }
            }
            else
            {
                fclose(in);
                free(line);
                rc = ERR_MEMORY;
            }
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
