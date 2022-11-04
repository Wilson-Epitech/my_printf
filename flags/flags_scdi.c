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
    my_putstr(va_arg(list, char *));
}

int flag_c(const char *format, va_list list, int i)
{
    my_putchar(va_arg(list, int));
}

int flag_d(const char *format, va_list list, int i)
{
    my_put_nbr(va_arg(list, int));
}

int flag_i(const char *format, va_list list, int i)
{
    my_put_nbr(va_arg(list, int));
}
