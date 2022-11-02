/*
** MY_PRINTF PROJECT, 2022
** flags_bpsmajo.c
** File description:
** flags b p S o
*/

#include "../includes/my.h"
#include <stdarg.h>

int flag_b(va_list list)
{
    my_put_nbr_binary(va_arg(list, unsigned int));
}

int flag_p(va_list list)
{
    my_putstr("0x");
    my_put_nbr_hexa_adress(va_arg(list, unsigned long long));
}

int flag_smaj(va_list list)
{
    non_printable_characters(va_arg(list, char *));
}

int flag_o(va_list list)
{
    my_put_nbr_octal(va_arg(list, int));
}
