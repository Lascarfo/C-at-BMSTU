
/**
 \file
*/

#include <stdio.h>
#include <stdlib.h>

#include "usage.h"
#include "const.h"
#include "cmpr.h"
#include "execution.h"
#include "my_getline.h"



/**
* \brief точка входа
* \details функция демонстрирует работу функций my_getline и str_replace
*/

int main(int argc, char *argv[])
{
    int rc = OK;
    FILE *in, *out;
    if (argc == 7 && (cmp_strings(argv[5], "-r")) && (cmp_strings(argv[3], "-s")))
    {
        in = fopen(argv[1], "r");
        if (in)
        {
            out = fopen(argv[2], "w");
            if (out)
            {
                rc = execution(in, out, (const char **)(argv));
                fclose(out);
            }
            else
            {
                usage();
                rc = ERR_FILE;
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
