/*
** MY_PRINTF PROJECT, 2022
** my_printf
** File description:
** my_printf
*/

#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <unistd.h>

int my_put_nbr(int nb);
int my_putstr(char const *str);
int *my_strcpy(char * dest , char const * src);
int my_putchar(char c);

int case2(const char *format, int i, va_list list)
{
}

int mini_printf(const char *format, ...)
{
    va_list list;
    int i = 0;
    va_start(list, format);
    while (format[i] != '\0') {
        if (format[i] == '%') {	   
            switch (format[i + 1]) {
            case 's':
                my_putstr(va_arg(list, char *));
                break;
            case 'c':
                my_putchar((char) va_arg(list, int));
                break;
            case 'd':
                my_put_nbr(va_arg(list, int ));
                break;
            case 'i':
                my_put_nbr(va_arg(list, int ));
                break;
            case '%':
                my_putchar('%');
                break;
            }
            i++;
        } else
	    my_putchar(format[i]);
        i ++;
	}
    i++;
    va_end(list);
}

/*
int main(void)
{
    char str [5];
    my_strcpy(str, "toto");
    str [1] = 6;
    my_printf("%S\n",str);
}
*/
int main(void)
{
    int nb = 21;
    char str[8];

    my_strcpy(str, "world");
    mini_printf("Hello %s\n", str);
    mini_printf("If you multiplie %d by %d,the result is %i. \n",
                nb, 2, nb * 2);
    my_strcpy(str, "Epitech");
    mini_printf("The word %%%s%% has %i characters .\n", str ,my_strlen (str));
}
