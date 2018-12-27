
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
#include <dlfcn.h>


/*!
 * \file
 * \fn int main(int argc, char* argv[])
 *  \brief main function
 *  \param argc an integer
 *  \param argv an array of chars.
 *  \exception symbols in file must been int
 *  \return code of error
 */


 #define OK 0
 #define ERR_MEMORY -1
 #define ERR_ARRAY -2
 #define ERR_FILE -3
 #define ERR_EMPTY -4
 #define ERR_PRINT -5
 #define ERR_PARAM -6

 #define N 50


int main(int argc, char *argv[])
{
    int rc = OK;
    FILE *file_in;
    FILE *file_out;
    void *handle;
    int (*read)(FILE *file, int **arr, int **arr_end);
    void (*usage)(void);
    int (*save)(FILE *file, const int *arr, const int *arr_end);
    void (*calculate)(const int *arr, const int *arr_end, int *len);
    int (*key)(const int *arr, const int *arr_end, int *arr_n, int *arr_n_end);
    void (*mysort)(void *base, size_t nitems, size_t size, int(*cmp_int)(const void*, const void*));
    int (*cmp_int)(const void *left, const void *right);
    handle = dlopen("lib.so", RTLD_LAZY);  //RTLD_NOW
    if (!handle) {
        fputs (dlerror(), stderr);
        exit(-1);
    }
    read = (int (*)(FILE *, int **, int **))dlsym(handle, "read");
    usage = (void (*)(void))dlsym(handle, "usage");
    save = (int (*)(FILE *, const int *, const int *))dlsym(handle, "save");
    calculate = (void (*)(const int *, const int *, int *))dlsym(handle, "calculate");
    mysort = (void (*)(void *, size_t, size_t, int \
      (*)(const void *, const void *)))dlsym(handle, "mysort");
    cmp_int = (int (*)(const void *, const void *))dlsym(handle, "cmp_int");
    key = (int (*)(const int *, const int *, int *, int
      *))dlsym(handle, "key");
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
                    rc = (*read)(file_in, &arr, &arr_end);
                    if (rc == OK)
                    {
                        (*calculate)(arr, arr_end, &len);
                        if (len > 0)
                        {
                            arr_s = malloc(len * sizeof (int));
                            if (arr_s)
                            {
                                arr_s_end = arr_s + len;
                                rc = (*key)(arr, arr_end, arr_s, arr_s_end);  // вызов функции - фильтра
                            }
                            else
                            {
                                rc = ERR_MEMORY;
                            }
                        }
                        if (rc == OK)
                        {
                            (*mysort)((arr_s), (arr_s_end - arr_s), sizeof(int), (*cmp_int));
                            (*save)(file_out, arr_s, arr_s_end);
                        }
                        free(arr_s);
                        free(arr);
                    }
                }
                else
                {
                    int *arr_s = NULL, *arr_s_end = NULL;
                    rc = (*read)(file_in, &arr_s, &arr_s_end);
                    if (rc == OK)
                    {
                        (*mysort)((arr_s), (arr_s_end - arr_s), sizeof(int), (*cmp_int));
                        (*save)(file_out, arr_s, arr_s_end);
                        free(arr_s);
                    }
                }
                fclose(file_out);
            }
            else
            {
                fprintf(stdout, "Problems with open file main_out.txt\n");
                (*usage)();
                rc = ERR_FILE;
            }
            fclose(file_in);
        }
        else
        {
            fprintf(stdout, "Problems with open file main_in.txt\n");
            (*usage)();
            rc = ERR_FILE;
        }
    }
    else
    {
        (*usage)();
        return ERR_EMPTY;
    }
    dlclose("lib.so");
    return rc;
}
