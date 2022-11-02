/*
** MY_PRINTF PROJECT, 2022
** flags_percentuxxmaj.c
** File description:
** flags % u x X
*/

#include "../includes/my.h"
#include <stdarg.h>

int flag_percent(va_list list)
{
    my_putchar('%');
}

int flag_u(va_list list)
{
    my_put_nbr_unsigned(va_arg(list, unsigned int));
}

int flag_x(va_list list)
{
    my_put_nbr_hexa(va_arg(list, unsigned int));
}

int flag_xmaj(va_list list)
{
    my_put_nbr_hexa_maj(va_arg(list, unsigned int));
}
