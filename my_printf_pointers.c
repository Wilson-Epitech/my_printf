/*
** MY_PRINTF PROJECT, 2022
** my_printf_pointers.c
** File description:
** my_printf_pointers
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include "flags.h"

void my_putchar(char c);
int my_strcpy(char * dest, char const * src);
int my_strlen(char const *str);

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    
    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            call_flags(format, i, list);
            i++;
        } else
            my_putchar(format[i]);
        i++;
    }
    va_end(list);
}

int main(void)
{
    int nb = 876;
    // char str[8];                                                             
    int nombre = 2147448;
    int *ptr;
    //   char str[] = "hello\t";                                                

    char str [5];

    my_strcpy (str, "toto");
    str[1] = 127;
    my_printf ("%S\n", str);

    my_printf("%S\n", str);

    my_printf("%p\n", &ptr);
    printf("%p\n", &ptr);

    my_printf("%b\n", nombre);
    printf("%b\n", nombre);
    my_printf("%X\n", nombre);
    printf("%X\n", nombre);
    my_printf("%x\n", nombre);
    printf("%x\n", nombre);
    my_printf("%o\n", nombre);
    printf("%o\n", nombre);
    my_printf("%u\n", nombre);
    printf("%u\n", nombre);
    my_strcpy(str, "world");
    my_printf("Hello %s\n", str);
    my_printf("If you multiplie %d by %d,the result is %i. \n", nb, 2, nb * 2);
    my_strcpy(str, "Epitech");
    my_printf("The word %%%s%% has %i characters .\n", str ,my_strlen (str));

    my_printf("%+d\n", nb);
     my_printf("%d\n", nb);

     // printf("%+d\n", nb);
     //printf("%d\n", nb);
}

