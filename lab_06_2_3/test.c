#include "field.h"
#include "minimum.h"
#include "const.h"
#define ARR 100


void field_t(void)
{
    FILE *file;
    int arr[ARR];
    char a1[] = "correct";
    char a2[] = "not correct";
    file = fopen("test_1.txt", "r");
    printf("first test for test_1.txt (8 7 6 9 8 3 6 2 7) are %s\n", (field(file, arr) == OK) ? a1 : a2);
    fclose(file);
    file = fopen("test_2.txt", "r");
    printf("second test for test_2.txt (asd)  are %s\n", (field(file, arr) == OK) ? a2 : a1);
    fclose(file);
    file = fopen("test_3.txt", "r");
    printf("third test for test_3.txt (> 100 numbers) are %s\n", (field(file, arr) == OK) ? a2 : a1);
    fclose(file);
}



void minimum_t(void)
{
    // тесты невозможны, так как number инициализируется в теле функции по просьбе преподователя.
}


int main(void)
{
    field_t();
    minimum_t();
    return OK;
}
