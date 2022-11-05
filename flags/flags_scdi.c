/*
** MY_PRINTF PROJECT, 2022
** flags_scdi.c
** File description:
** flags scdi
*/

#include "../includes/my.h"
#include <stdarg.h>

int flag_s(const char *format, va_list list, int i)
{
    char *temp_s = va_arg(list, char *);
    my_putstr(temp_s);
}

int flag_c(const char *format, va_list list, int i)
{
    int temp_c = va_arg(list, int);
    my_putchar(temp_c);
}

int flag_d(const char *format, va_list list, int i)
{
    int temp_d = va_arg(list, int);
    my_put_nbr(temp_d);
}

int flag_i(const char *format, va_list list, int i)
{
    int temp_i = va_arg(list, int);
    my_put_nbr(temp_i);

}
