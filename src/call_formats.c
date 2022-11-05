/*
** MY_PRINTF PROJECT, 2022
** call_formats.c
** File description:
** call formats
*/

#include <stdarg.h>
#include <stdio.h>
#include "../includes/struct_formats.h"
#include "../includes/func_formats.h"

structure_u call_format[] = {
        {'+', &format_plus},
        {'\0', NULL}
};

int structure_call_formats(const char *format, va_list list, int *i)
{
    for (int j = 0; call_format[j].format != '\0' ; j++) {
        if ((format[*i + 1] == call_format[j].format && format[*i + 2] == 'd')
            || (format[*i + 1] == call_format[j].format
                && format[*i + 2] == 'i')) {
            call_format[j].ptr(list);
            (*i) += 2;
        }
        if ((format[*i + 1] == call_format[j].format && format[*i + 2] != 'd')
            || (format[*i + 1] == call_format[j].format
                && format[*i + 2] != 'i')){
            (*i)++;
            return (84);
        }
    }
}
