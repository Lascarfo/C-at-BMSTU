
/**
 * \author Яроцкий Даниил
 * \brief это основная функция программы
 * \details программа может выполнить три операции:
 * 1. просуммировать две матрицы
 * 2. перемножить две матрицы
 * 3. найти решение СЛАУ методом Гаусса с максимальным элементом по строке и столбцу
*/

#include <stdio.h>
#include <string.h>

#include "calculatings.h"
#include "io.h"


/*!
 * \file
 * \fn int main(int argc, char* argv[])
 *  \brief main function
 *  \param argc an integer
 *  \param argv an array of chars.
 *  \exception symbols in file must been int
 *  \return code of error
 */


int main(int argc, char **argv)
{
    int rc = OK;
    if ((argc == 5) && (strcmp(argv[1], "a") == 0))
    {
        rc = addition_main(argv[2], argv[3], argv[4]);
        // printf("rc_a %d\n", rc);
    }
    else if ((argc == 5) && (strcmp(argv[1], "m") == 0))
    {
        rc = multiplication_main(argv[2], argv[3], argv[4]);
        // printf("rc_m %d\n", rc);
    }
    else if ((argc == 4) && (strcmp(argv[1], "o")) == 0)
    {
        rc = gauss(argv[2], argv[3]);
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
