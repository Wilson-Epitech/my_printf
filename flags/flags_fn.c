/*
** MY_PRINTF PROJECT, 2022
** flag f
** File description:
** flag f
*/

#include <stdarg.h>
#include "../includes/my.h"
#include "../includes/func_flags.h"

int flag_f(const char *format, va_list list, int i)
{
    double temp_f = va_arg(list, double);
    my_put_nbr_float(temp_f);
}

int flag_n(const char *format, va_list list, int i)
{
    my_put_nbr_size(format, list, i);
}
