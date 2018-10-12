#include <stdio.h>
#include <string.h>

#include "calculatings.h"
#include "io.h"

int main(int argc, char **argv)
{
    int rc = OK;
    if ((argc == 5) && ((strcmp(argv[1], "a") == 0 || (strcmp(argv[1], "m")) == 0)))
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
