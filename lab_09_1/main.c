#include <stdio.h>
#include <stdlib.h>
#include "my_string.h"


int main(void)
{
    const char str[] = "3.14159265358979323846264338327950288";
    const char rej[] = "";
    size_t size = my_strcspn(str, rej);
    printf("my_strcspn: %zu\n", size);

    char *drop = NULL;
    drop = my_strndup(str, 4);
    printf("my_strndup: %s\n", drop);



    return 0;
}
