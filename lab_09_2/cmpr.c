#include "cmpr.h"


/**
* \brief строковый компаратор
* \details сравнивает две строки, поступившие на вход
* \param first первая строка
* \param second вторая строка
*/

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
