/*
** MY_PRINTF PROJECT, 2022
** my_printf_pointers.c
** File description:
** my_printf_pointers
*/

#include <stdarg.h>
#include "../includes/func_formats.h"
#include "../includes/struct_formats.h"
#include "../includes/func_flags.h"
#include "../includes/struct_flags.h"
#include "../includes/my.h"

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            structure_call_formats(format, list, &i);
            structure_call_flags(format, list, i);
            i++;
        } else
            my_putchar(format[i]);
        i++;
    }
    va_end(list);
    return (0);
}
