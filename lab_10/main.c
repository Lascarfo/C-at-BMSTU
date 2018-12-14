

/*
реализуемые функции:
pop_back — возвращает указатель на данные из элемента, который расположен в "хвосте" списка
insert — вставляет элемент перед указанным элементом списка
reverse — обращает список используя 3 указателя на соседние элементы списка
sorted_insert — получает упорядоченный список, и элемент, который нужно вставить в этот список, чтобы не нарушить его упорядоченности
*/




#include <stdio.h>
#include <stdlib.h>

#include "const.h"
#include "io.h"
#include "list.h"
#include "usage.h"



int main(int argc, char **argv)
{
    int rc = OK;
    FILE *in;
    if (argc == 2)
    {
        in = fopen(argv[1], "r");
        if (in)
        {
            execution(in);
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
        rc = ERR_IN;
    }
    return rc;
}
