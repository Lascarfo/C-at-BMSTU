#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#include "const.h"
#include "my_snprintf.h"





const bool cmp_strings(const char *first, const char *second)
{
    int count = 0;
    while (second[count] != '\0' || first[count] != '\0')
    {
        if (first[count] != second[count])
        {
            return false;
        }
        count++;
    }
    if (second[count] == '\0' && first[count] == '\0')
    {
        return true;
    }
    else
    {
        return false;
    }
    return false;
}



int main(void)
{
    printf("func my_snprintf testing:\n\n");
    printf("test for %%o:\n");                              // %o
    {
        int rc, my_rc;               // MAX
        char arr[UINT_MAX + 1];
        char my_arr[UINT_MAX + 1];
        char string[] = "%o";
        rc = snprintf(arr, UINT_MAX, string, UINT_MAX);
        my_rc = my_snprintf(my_arr, UINT_MAX, string, UINT_MAX);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 1: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // число превышающее диапазон UINT
        char arr[UINT_MAX + 1];
        char my_arr[UINT_MAX + 1];
        char string[] = "%o";
        rc = snprintf(arr, UINT_MAX, string, UINT_MAX + 1);
        my_rc = my_snprintf(my_arr, UINT_MAX, string, UINT_MAX + 1);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 2: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // 0
        char arr[1 + 1];
        char my_arr[1 + 1];
        char string[] = "%o";
        rc = snprintf(arr, 1, string, 0);
        my_rc = my_snprintf(my_arr, 1, string, 0);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 3: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // отрицательное число
        char arr[UINT_MAX + 1];
        char my_arr[UINT_MAX + 1];
        char string[] = "%o";
        rc = snprintf(arr, UINT_MAX, string, -1);
        my_rc = my_snprintf(my_arr, UINT_MAX, string, -1);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 4: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // буфер достаточной длины
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        char string[] = "%o";
        rc = snprintf(arr, LEN, string, 5);
        my_rc = my_snprintf(my_arr, LEN, string, 5);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 5: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // буфер нулевой длины
        char arr[0 + 1];
        char my_arr[0 + 1];
        char string[] = "%o";
        rc = snprintf(arr, 0, string, 5);
        my_rc = my_snprintf(my_arr, 0, string, 5);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 6: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // недостаточный буфер
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        char string[] = "%o";
        rc = snprintf(arr, LEN, string, 5);
        my_rc = my_snprintf(my_arr, LEN, string, 5);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 7: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }


    printf("\ntest for %%hX:\n");                   // %hX
    {
        int rc, my_rc;               // MAX
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        char string[] = "%hX";
        rc = snprintf(arr, LEN, string, SHRT_MAX);
        my_rc = my_snprintf(my_arr, LEN, string, SHRT_MAX);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 1: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // число превышающее диапазон SHRT
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        char string[] = "%hX";
        rc = snprintf(arr, LEN, string, SHRT_MAX + 1);
        my_rc = my_snprintf(my_arr, LEN, string, SHRT_MAX + 1);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 2: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // 0
        char arr[1 + 1];
        char my_arr[1 + 1];
        char string[] = "%hX";
        rc = snprintf(arr, 1, string, 0);
        my_rc = my_snprintf(my_arr, 1, string, 0);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 3: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // отрицательное число
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        char string[] = "%hX";
        rc = snprintf(arr, LEN, string, -1);
        my_rc = my_snprintf(my_arr, LEN, string, -1);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 4: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // буфер достаточной длины
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        char string[] = "%hX";
        rc = snprintf(arr, LEN, string, 5);
        my_rc = my_snprintf(my_arr, LEN, string, 5);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 5: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // буфер нулевой длины
        char arr[0 + 1];
        char my_arr[0 + 1];
        char string[] = "%hX";
        rc = snprintf(arr, 0, string, 5);
        my_rc = my_snprintf(my_arr, 0, string, 5);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 6: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // недостаточный буфер
        char arr[2 + 1];
        char my_arr[2 + 1];
        char string[] = "%hX";
        rc = snprintf(arr, 2, string, 4500);
        my_rc = my_snprintf(my_arr, 2, string, 4500);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 7: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }




    printf("\ntest for %%s:\n");
    {
        int rc, my_rc;               // буфер достаточной длины
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        char string[] = "%s";
        rc = snprintf(arr, LEN, string, "test");
        my_rc = my_snprintf(my_arr, LEN, string, 5);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 1: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // буфер нулевой длины
        char arr[0 + 1];
        char my_arr[0 + 1];
        char string[] = "%s";
        rc = snprintf(arr, 0, string, "test");
        my_rc = my_snprintf(my_arr, 0, string, "test");
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 2: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // недостаточный буфер
        char arr[2 + 1];
        char my_arr[2 + 1];
        char string[] = "%s";
        rc = snprintf(arr, 2, string, "test");
        my_rc = my_snprintf(my_arr, 2, string, "test");
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 3: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    {
        int rc, my_rc;               // пустая строка
        char arr[2 + 1];
        char my_arr[2 + 1];
        char string[] = "%s";
        rc = snprintf(arr, 2, string, "test");
        my_rc = my_snprintf(my_arr, 2, string, "test");
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 4: ");
        if ((rc == my_rc) && (cmp_strings(arr, my_arr)))
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    return 0;
}
