#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>


#include "const.h"
#include "my_snprintf.h"


/**
* \brief функция подсчета длины числа
* \details подсчёт длины исходного десятичного числа в восьмиричном представлении
* \param number число на вход
*/

int len_dec_to_oct(unsigned int number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 8;
        count++;
    }
    return count;
}


/**
* \brief функция подсчета длины числа
* \details подсчёт длины исходного десятичного числа в шестнадцатиричном представлении
* \param number число на вход
*/

int len_dec_to_hex(unsigned short int number)
{
    int count = 0;
    while (number != 0)
    {
        number /= 16;
        count++;
    }
    return count;
}


/**
* \brief функция - конвертор
* \details конвертирует исходное десятичное число в шестандцатиричное
* \param buffer строка для записи полученного числа
* \param number число на вход
*/

void dec_to_hex(char *buffer, int n, int len, unsigned short int number)
{
    unsigned short temp = 0;
    int *cache = malloc(len + 1);
    if (cache)
    {
        *(cache + len) = '\0';
        len--;
        while (number != 0)
        {
            temp = number % 16;
            *(cache + len) = temp + ((temp < 10) ? '0' : 'A' - 10);
            number /= 16;
            len--;
        }
        *(cache + len) = '\0';
        for (int i = 0; i < n; i++)
        {
            *(buffer + i) = *(cache + i);
        }
        if (n != len)
        {
            *(buffer + n) = '\0';
        }
        free(cache);
    }
    else
    {

        return;
    }

}

/**
* \brief функция - конвертор
* \details конвертирует исходное десятичное число в восьмиричное
* \param buffer строка для записи полученного числа
* \param number число на вход
*/

void dec_to_oct(char *buffer, int n, int len, unsigned int number)
{
    unsigned short cache = 0;
    *(buffer + len) = '\0';
    len--;
    while (number != 0)
    {
        cache = number % 8;
        *(buffer + len) = cache + '0';
        number /= 8;
        len--;
    }
}

/**
* \brief функция вычисляет длину строки
* \param symbols входная строка
*/

int full_len(const char *symbols)
{
    if (symbols == NULL)
    {
        return 0;
    }
    int len = 0;
    while (*symbols != '\0')
    {
        symbols++;
        len++;
    }
    return len;
}


/**
* \brief строковый компаратор
* \details сравнивает две строки, поступившие на вход
* \param first первая строка
* \param second вторая строка
*/

const bool cmp_n_strings(const char *first, const char *second, const int len)
{
    int count = 0;
    while (count < len)
    {
        if (first[count] != second[count])
        {
            return false;
        }
        count++;
    }
    return true;
}


/**
* \brief функция подсчитывает необходимый размер буфера, для хранения строки
* \details конвертирует исходное десятичное число в шестандцатиричное
* \param format исходная строка
* \param args сгенерированный список параметров
*/

int calculate_size(const char *format, va_list args)
{
    int size = 0;
    int length;
    char *temp = NULL;
    size += full_len(format);
    length = size;
    for(int i = 0; i < length; i++)
    {
        if (format[i] == '%')
        {
            size--;
            if (cmp_n_strings(format + i + 1, "s", 1))
            {
                size--;
                temp = va_arg(args, char *);
                size += full_len(temp);
            }
            else if (cmp_n_strings(format + i + 1, "hX", 2))
            {
                size -= 2;
                unsigned short int number = va_arg(args, int);
                int len_hX = len_dec_to_hex(number);
                size += len_hX;
            }
            else if (cmp_n_strings(format + i + 1, "o", 1))
            {
                size--;
                unsigned short int number = va_arg(args, int);
                int len_o = len_dec_to_oct(number);
                size += len_o;
            }
        }
    }
    return size;
}


/**
* \brief собственный прототип функции snprintf
* \details производит запись строки в указанный буфер, размер буффера передается
в качестве параметра
* \param string выделенная строка
* \param n размер выходной строки
* \param format исходная строка
*/

int my_snprintf(char *string, size_t n, const char *format, ...)
{
    va_list args;
    int size = 0;
    int length = full_len(format);
    if (string == NULL)
    {
        return ERR_SN;
    }
    if (length == 0)
    {
        return 0;
    }
    va_start(args, format);
    size = calculate_size(format, args);
    if (n == 0 || string == NULL)
    {
        va_end(args);
        return size;
    }
    va_end(args);
    va_start(args, format);
    write_string(string, format, n, args);
    va_end(args);
    return size;
}

/**
* \brief основная функция, выполняющая запись в строку
* \param string выделенная строка
* \param n размер выходной строки
* \param format исходная строка
*/

void write_string(char *string, const char *format, size_t n, va_list args)
{
    int length = full_len(format);
    int counter = 0;
    for(int i = 0; i < length && counter < n; i++)
    {
        if (format[i] == '%')
        {
            if (cmp_n_strings(format + i + 1, "s", 1))
            {
                i++;
                char *temp = va_arg(args, char *);
                int len = full_len(temp);
                if (len > n - counter - 1)
                {
                    sym_copy(string + counter, temp, n - counter);
                    counter += n - counter - 1;
                }
                else
                {
                    sym_copy(string + counter, temp, len);
                    counter += len;
                }
            }
            else if (cmp_n_strings(format + i + 1, "hX", 2))
            {
                i += 2;
                unsigned short int number = va_arg(args, int);
                int len_hX = len_dec_to_hex(number);
                if (len_hX > n - counter - 1)
                {
                    char *buffer = malloc(n - counter);
                    if (buffer)
                    {
                        dec_to_hex(buffer, n - counter - 1, len_hX, number);
                        sym_copy(string + counter, buffer, full_len(buffer));
                        counter += full_len(buffer);
                        free(buffer);
                    }
                    counter += n - counter - 1;
                }
                else
                {
                    char *buffer = malloc(len_hX + 1);
                    if (buffer)
                    {
                        dec_to_hex(buffer, len_hX, len_hX, number);
                        sym_copy(string + counter, buffer, full_len(buffer));
                        counter += full_len(buffer);
                        free(buffer);
                    }
                }
            }
            else if (cmp_n_strings(format + i + 1, "o", 1))
            {
                i++;
                unsigned int number = va_arg(args, int);
                int len_o = len_dec_to_oct(number);
                if (len_o > n - counter - 1)
                {
                    counter += n - counter - 1;
                }
                else
                {
                    char *buffer = malloc(len_o + 1);
                    if (buffer)
                    {
                        dec_to_oct(buffer, len_o, number);
                        sym_copy(string + counter, buffer, full_len(buffer));
                        counter += full_len(buffer);
                        free(buffer);
                    }
                }
            }
        }
        else
        {
            *(string + counter) = format[i];
            counter++;
        }
    }
    *(string + counter) = '\0';
}


/**
* \brief функция, выполняющая посимвольное копирование
* \param line строка, в которую нужно скопировать
* \param symbols строка из которой нужно скопировать
* \param len длина строки
*/

char *sym_copy(char *line, const char *symbols, size_t len)
{
    if (len == 0)
    {
        *line = '\0';
        return line;
    }
    while (len != 0)
    {
        *line = *symbols;
        line++;
        symbols++;
        len--;
        // printf("iter %zu\n", len);
        // printf("line %c\n", *line);
    }
    *line = '\0';
    return line;
}
