#include <stdio.h>
#include <string.h>


#include "io.h"
#include "memory.h"
#include "const.h"
#include "calculatings.h"
#include "usage.h"



int main(int argc, char **argv)
{
    int rc = OK;
    if (argc == 3 && ((strcmp(argv[2], "s") == 0) || (strcmp(argv[2], "e") == 0)))
    {
        FILE *file;
        file = fopen(argv[1], "r");
        if (file)
        {
            int columns = 0, rows = 0;
            double **matrix = NULL;
            if (read_params(file, &rows, &columns) == OK)
            {
                matrix = allocate_matrix(rows, columns);
                if (matrix != NULL)
                {
                    if (read_matrix(file, matrix, rows, columns) == OK)
                    {
                        if (strcmp(argv[2], "s") == 0)
                        {
                            sort_matrix(matrix, rows, columns);
                            print_matrix(matrix, rows, columns);
                        }
                        else
                        {
                            unsigned int count = 0;
                            for (int row = 0; row < rows; row++)
                            {
                                count += unique_elems(matrix[row], columns);
                            }
                            printf("unqie elements in matrix: %d\n", count);
                        }
                    }
                    else
                    {
                        rc = ERR_MATRIX;
                    }
                    free_mem(matrix, rows);
                }
                else
                {
                    rc = ERR_MEMORY;
                }
            }
            else
            {
                rc = ERR_MATRIX;
            }
            fclose(file);
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
        rc = ERR_FILE;
    }
    return rc;
}
