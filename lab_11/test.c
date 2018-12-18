#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

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
    printf("test for %%o:\n");
    {
        int rc, my_rc;
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        rc = snprintf(arr, LEN, "%o", 11);
        my_rc = my_snprintf(my_arr, LEN, "%o", 11);
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
        int rc, my_rc;
        char arr[LEN + 1] = {'\0'};
        char my_arr[LEN + 1];
        rc = 2;
        my_rc = my_snprintf(my_arr, 2, "%o", 10);
        printf("test 2: ");
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
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
        int rc, my_rc;
        char arr[4];
        char my_arr[4];
        rc = snprintf(arr, 4, "%o", 11);
        my_rc = my_snprintf(my_arr, 4, "%o", 11);
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
        int rc, my_rc;
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        rc = snprintf(arr, LEN, "oct_num: %o", 11);
        my_rc = my_snprintf(my_arr, LEN, "oct_num: %o", 11);
        printf("test 4: ");
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        if (rc == my_rc)
        {
            printf("passed\n");
        }
        else
        {
            printf("not passed\n");
        }
    }
    printf("\ntest for %%hX:\n");
    {
        int rc, my_rc;
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        unsigned short num = 11;
        rc = snprintf(arr, LEN, "%hX", num);
        my_rc = my_snprintf(my_arr, LEN, "%hX", num);
        printf("test 1: ");
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
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
        int rc, my_rc;
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        unsigned short num = 25601;
        rc = snprintf(arr, 3, "%hX", num);
        my_rc = my_snprintf(my_arr, 3, "%hX", num);
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 2: ");
        if (rc == my_rc)
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
        int rc, my_rc;
        char arr[LEN + 1];
        char my_arr[LEN + 1];
        rc = snprintf(arr, 3, "%s", "String");
        my_rc = my_snprintf(my_arr, 3, "%s", "String");
        // printf("\n%s\n", arr);
        // printf("%s\n", my_arr);
        // printf("%d\n", rc);
        // printf("%d\n", my_rc);
        printf("test 2: ");
        if (rc == my_rc)
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
