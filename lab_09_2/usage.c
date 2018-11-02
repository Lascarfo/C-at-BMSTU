/**
 \file
*/

#include <stdio.h>


/**
* \brief функция выводит на экран краткие инструкции по использованию программы
*/

void usage(void)
{
    fprintf(stdout, "Please follow next input:\napp.exe in.txt out.txt –s search –r replace\n");
}
