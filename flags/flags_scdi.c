/*
** MY_PRINTF PROJECT, 2022
** flags_scdi.c
** File description:
** flags scdi
*/

#include "../includes/my.h"
#include <stdarg.h>

int flag_s(va_list list)
{
    my_putstr(va_arg(list, char *));
}

int flag_c(va_list list)
{
    my_putchar(va_arg(list, int));
}

int flag_d(va_list list)
{
    my_put_nbr(va_arg(list, int));
}

int flag_i(va_list list)
{
    my_put_nbr(va_arg(list, int));
}
