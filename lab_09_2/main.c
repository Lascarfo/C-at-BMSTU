
/**
 \file
*/

#include <stdio.h>

#include "usage.h"
#include "const.h"

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
            int size_of_buffer = 0;
            int len = my_getline(&line, &size_of_buffer, in);
            if (len != ERR_MEMORY)
            {
                
            }
            else
            {
                rc = ERR_MEMORY;
            }
            free(line);
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
