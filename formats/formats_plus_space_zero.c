/*
** MY_PRINTF PROJECT, 2022
** formats_plus_space_zero.c
** File description:
** formats + - espace 0
*/

#include "../includes/my.h"
#include "../includes/func_flags.h"

int format_plus(va_list list)
{
    int temp = va_arg(list, int);

    plus(temp);
}
