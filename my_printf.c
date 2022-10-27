/*
** MY_PRINTF PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_unsigned(unsigned int nb);
int my_put_nbr_octal(int nb);
unsigned long long my_put_nbr_hexa_adress(unsigned long long nb);
int my_put_nbr_hexa(unsigned nb);
int my_put_nbr_hexa_maj(unsigned nb);
int my_put_nbr_binary(unsigned int nb);
int my_putstr(char const *str);
int *my_strcpy(char * dest , char const * src);
int my_putchar(char c);
int non_printable_characters(char *str);

int case3(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
    case 'x':
        my_put_nbr_hexa(va_arg(list, unsigned int));
        break;
    case 'X':
        my_put_nbr_hexa_maj(va_arg(list, unsigned int));
        break;
    case 'b':
        my_put_nbr_binary(va_arg(list, unsigned int));
        break;
    case 'p':
        my_putstr("0x");
        my_put_nbr_hexa_adress(va_arg(list, unsigned long long));
        break;
    case 'S':
        non_printable_characters(va_arg(list, char *));
        break;
    case 'o':
        my_put_nbr_octal(va_arg(list, int));
    }
}

int case2(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'c':
        my_putchar((char) va_arg(list, int));
        break;
    case 'd':
        my_put_nbr(va_arg(list, int));
        break;
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    case '%':
        my_putchar('%');
        break;
    case 'u':
        my_put_nbr_unsigned(va_arg(list, unsigned int));
        break;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            case2(format, i, list);
            case3(format, i, list);
            i++;
        } else
            my_putchar(format[i]);
        i++;
    }
    i++;
    va_end(list);
}
