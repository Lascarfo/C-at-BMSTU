
/**
 * \author Яроцкий Даниил
 * \brief это основная функция программы
 * \details программа считывает числа с файла, и сортирует по алгоритму модифицированного пузырька,
 *  учитывая условие фильтрации.
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

#include "lib.h"


/*!
 * \file
 * \fn int main(int argc, char* argv[])
 *  \brief main function
 *  \param argc an integer
 *  \param argv an array of chars.
 *  \exception symbols in file must been int
 *  \return code of error
 */


int main(int argc, char *argv[])
{
    int rc = OK;
    FILE *file_in;
    FILE *file_out;
    if (((argc == 3) || ((argc == 4) && (strcmp(argv[3], "f")) == 0)))
    {
        file_in = fopen(argv[1], "r");
        if (file_in)
        {
            file_out = fopen(argv[2], "w");
            if (file_out)
            {
                if (argc == 4)
                {
                    int *arr = NULL, *arr_end = NULL;
                    int *arr_s = NULL, *arr_s_end = NULL, len = 0;
                    rc = read(file_in, &arr, &arr_end);
                    if (rc == OK)
                    {
                        calculate(arr, arr_end, &len);
                        if (len > 0)
                        {
                            arr_s = malloc(len * sizeof (int));
                            if (arr_s)
                            {
                                arr_s_end = arr_s + len;
                                rc = key(arr, arr_end, arr_s, arr_s_end);  // вызов функции - фильтра
                            }
                            else
                            {
                                rc = ERR_MEMORY;
                            }
                        }
                        if (rc == OK)
                        {
                            mysort((arr_s), (arr_s_end - arr_s), sizeof(int), cmp_int);
                            save(file_out, arr_s, arr_s_end);
                        }
                        free(arr_s);
                        free(arr);
                    }
                }
                else
                {
                    int *arr_s = NULL, *arr_s_end = NULL;
                    rc = read(file_in, &arr_s, &arr_s_end);
                    if (rc == OK)
                    {
                        mysort((arr_s), (arr_s_end - arr_s), sizeof(int), cmp_int);
                        save(file_out, arr_s, arr_s_end);
                        free(arr_s);
                    }
                }
                fclose(file_out);
            }
            else
            {
                fprintf(stdout, "Problems with open file main_out.txt\n");
                usage();
                rc = ERR_FILE;
            }
            fclose(file_in);
        }
        else
        {
            fprintf(stdout, "Problems with open file main_in.txt\n");
            usage();
            rc = ERR_FILE;
        }
    }
    else
    {
        usage();
        return ERR_EMPTY;
    }
    return rc;
}
