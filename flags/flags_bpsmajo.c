/*
** MY_PRINTF PROJECT, 2022
** flags_bpsmajo.c
** File description:
** flags b p S o
*/

#include "../includes/my.h"
#include <stdarg.h>
#include <stddef.h>

int flag_b(const char *format, va_list list, int i)
{
    int temp_b = va_arg(list, unsigned int);
    my_put_nbr_binary(temp_b);
}

int flag_p(const char *format, va_list list, int i)
{
    unsigned long long temp_p = va_arg(list, unsigned long long);
    int *ptr = (int*)temp_p;
    if (ptr == NULL) {
        my_putstr("(nil)");
        return (5);
    }
    my_putstr("0x");
    my_put_nbr_hexa_adress(temp_p);
}

int flag_smaj(const char *format, va_list list, int i)
{
    char *temp_smaj = va_arg(list, char *);
    non_printable_characters(temp_smaj);
}

int flag_o(const char *format, va_list list, int i)
{
    int temp_o = va_arg(list, unsigned int);
    my_put_nbr_octal(temp_o);
}
