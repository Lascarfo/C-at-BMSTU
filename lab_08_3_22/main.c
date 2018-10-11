#include <stdio.h>
#include <string.h>

#include "calculatings.h"

int main(int argc, char **argv)
{
    int rc = OK;
    if ((argc == 5) && ((strcmp(argv[1], "a") || (strcmp(argv[1], "m")))))
    {
        rc = arithmetic(argv);
    }
    else if ((argc == 4) && (strcmp(argv[1], "o")) == 0)
    {

    }
    else if ((argc == 2) && (strcmp(argv[1], "h")) == 0)
    {
        usage();
    }
    else
    {
        usage();
        rc = ERR_INPUT;
    }
    return rc;
}
