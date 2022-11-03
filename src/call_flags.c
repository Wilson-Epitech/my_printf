/*
** MY_PRINTF PROJECT, 2022
** callflags
** File description:
** call_flags.c
*/

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../includes/struct_flags.h"
#include "../includes/func_flags.h"

structure_t call_flags[] = {
    {'s', &flag_s},
    {'c', &flag_c},
    {'d', &flag_d},
    {'i', &flag_i},
    {'%', &flag_percent},
    {'u', &flag_u},
    {'x', &flag_x},
    {'X', &flag_xmaj},
    {'b', &flag_b},
    {'p', &flag_p},
    {'S', &flag_smaj},
    {'o', &flag_o},
    {'\0', NULL}
};

int structure_call_flags(const char *format,  va_list list, int i)
{
    for (int y = 0; call_flags[y].c != '\0'; y++) {
        if (format[i + 1] == call_flags[y].c) {
            call_flags[y].ptr(list);
        }
    }
}
