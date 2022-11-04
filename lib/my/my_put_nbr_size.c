/*
** MY_PRINTF PROJECT, 2022
** my_put_nbr
** File description:
** my_put_nbr_size
*/

#include <stdarg.h>

int func_count(const char *format, int i);

int my_put_nbr_size(const char *format, va_list list, int i)
{
    int *tmp = 0;
    int nb = func_count(format, i);

    tmp = va_arg(list, int*);
    *tmp = nb;
    return 0;
}
