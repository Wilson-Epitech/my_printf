/*
** MY_PRINTF PROJECT, 2022
** flags_%uxX.c
** File description:
** flags % u x X
*/

int my_put_nbr_unsigned(unsigned int nb);
void my_putchar(char c);
int my_put_nbr_hexa(unsigned int nb);
int my_put_nbr_hexa_maj(unsigned int nb);

int flag_percent(const char *format, int i, va_list list)
{
    my_putchar('%');
}

int flag_u(const char *format, int i, va_list list)
{
    my_put_nbr_unsigned(va_arg(list, unsigned int));
}

int flag_x(const char *format, int i, va_list list)
{
    my_put_nbr_hexa(va_arg(list, unsigned int));
}

int flag_X(const char *format, int i, va_list list)
{
    my_put_nbr_hexa_maj(va_arg(list, unsigned int));
}

