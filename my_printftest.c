/*
** MY_PRINTF PROJECT, 2022
** my_printftest.c
** File description:
** my_printftest
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_unsigned(unsigned int nb);
int my_put_nbr_octal(int nb);
unsigned long long my_put_nbr_hexa_adress(unsigned long long nb);
int my_put_nbr_hexa(unsigned int nb);
int my_put_nbr_hexa_maj(unsigned int nb);
int my_put_nbr_binary(unsigned int nb);
int my_putstr(char const *str);
int *my_strcpy(char * dest , char const * src);
void my_putchar(char c);
int non_printable_characters(char *str);
int format_plus(int nb);

/*
int case4(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
        case '+':
            format_plus(va_arg(list, int));
            break;
    }

    }
*/
int case3(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
    case 'x':
        my_put_nbr_hexa(va_arg(list, unsigned int));
        break;
    case 'X':
        my_put_nbr_hexa_maj(va_arg(list, unsigned int));
        break;
    case 'b':
        my_put_nbr_binary(va_arg(list, unsigned int));
        break;
    case 'p':
        my_putstr("0x");
        my_put_nbr_hexa_adress(va_arg(list, unsigned long long));
        break;
    case 'S':
        non_printable_characters(va_arg(list, char *));
        break;
    case 'o':
        my_put_nbr_octal(va_arg(list, int));
        break;
        /* case 'n':
           my_putstr(my_strlen(my_printf));
           break; */
    }
}

int case2(const char *format, int i, va_list list)
{
    switch (format[i + 1]) {
    case '+':
        if (i > 0) {
            //my_putchar('+');
            format_plus(i);
            case2(format, i + 1, list);
        }
        else
            case2(format, i + 1, list);
        break;
    case 's':
        my_putstr(va_arg(list, char *));
        break;
    case 'c':
        my_putchar((char) va_arg(list, int));
        break;
    case 'd':
        //printf("test %d\n", va_arg(list, int));
        my_put_nbr(va_arg(list, int));
        break;
    case 'i':
        my_put_nbr(va_arg(list, int));
        break;
    case '%':
        my_putchar('%');
        break;
    case 'u':
        my_put_nbr_unsigned(va_arg(list, unsigned int));
        break;
    }
}

int my_printf(const char *format, ...)
{
    va_list list;
    int i = 0;

    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {
            case2(format, i, list);
            case3(format, i, list);
            i++;
            if (format[i] == '+') {
                i++;
            }
        } else 
            my_putchar(format[i]);
        i++;
    }
    i++;;
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

    printf("%+d\n", nb);
    printf("%d\n", nb);
}
