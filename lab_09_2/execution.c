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
*/

void save(FILE *out, const char *source)
{
    fprintf(out, "%s", source);
}



/**
* \brief функция, которая выполняет обработку всего файла
*/


int execution(FILE *in, FILE *out, const char **argv)
{
    int rc = OK;
    char *line_get = NULL;
    char *line_replace = NULL;
    size_t size_of_buffer = 0;
    int len = 0;
    bool run = true;
    while (run)
    {
        line_get = NULL;
        size_of_buffer = 0;
        len = my_getline(&line_get, &size_of_buffer, in);
        printf("len %d\n", len);
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
