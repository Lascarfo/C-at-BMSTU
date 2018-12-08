/**
 \file
*/



#include "const.h"
#include "cmpr.h"
#include "execution.h"
#include "str_replace.h"
#include "my_getline.h"


/**
* \brief функция, для записи в файл
* \param out файл для записи
* \param source строка для записи
*/

void save(FILE *out, const char *source)
{
    fprintf(out, "%s", source);
}



/**
* \brief функция, которая выполняет обработку всего файла
* \param in файл для чтения
* \param out файл для записи
* \param argv массив символов, содержащий рабочие данные
*/


int execution(FILE *in, FILE *out, char **argv)
{
    int rc = OK;
    char *line_get = NULL;
    char *line_replace = NULL;
    size_t size_of_buffer = 0;
    ssize_t len = 0;
    bool run = true;
    while (run)
    {
        line_get = NULL;
        size_of_buffer = 0;
        len = my_getline(&line_get, &size_of_buffer, in);
        if (line_get)
        {
            if (len > 0)
            {
                line_replace = str_replace(line_get, argv[4], argv[6]);
                if (line_replace)
                {
                    save(out, line_replace);
                    free(line_replace);
                }
            }
            else
            {
                rc = ERR_MEMORY;
                run = false;
            }
            free(line_get);
        }
        else
        {
            rc = ERR_MEMORY;
            run = false;
        }
    }
    return rc;
}
