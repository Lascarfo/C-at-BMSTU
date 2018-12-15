#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "usage.h"
#include "const.h"
#include "io.h"

int main(int argc, char **argv)
{
    int rc = OK;
    if (argc == 3)
    {
        FILE *file;
        file = fopen(argv[1], "r");
        if (file)
        {
            if (strcmp(argv[2], "list") == 0)
            {
                list_func(file);
            }
            else
            {
                rc = ERR_FILE;
                usage();
            }
            fclose(file);
        }
        else
        {
            rc = ERR_FILE;
            usage();
        }
    }
    else if (argc == 4)
    {
        FILE *file;
        file = fopen(argv[1], "r");
        if (file)
        {
            if (strcmp(argv[2], "form") == 0)
            {
                form_func(file, (atoi)(argv[3]));
            }
            else
            {
                rc = ERR_FILE;
                usage();
            }
            fclose(file);
        }
        else
        {
            rc = ERR_FILE;
            usage();
        }
    }
    else
    {
        rc = ERR_FILE;
        usage();
    }
    return rc;
}
