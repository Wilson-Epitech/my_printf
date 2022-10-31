/*
** MY_PRINTF PROJECT, 2022
** flags_scdi.c
** File description:
** flags scdi
*/

int my_putstr(char const *str);
void my_putchar(char c);

int flag_s(const char *format, int i, va_list list)
{
    my_putstr(va_arg(list, char *));
}

int flag_c(const char *format, int i, va_list list)
{
    my_putchar(va_arg(list, int));
}

int flag_d(const char *format, int i, va_list list)
{
    my_put_nbr(va_arg(list, int));
}

int flag_i(const char *format, int i, va_list list)
{
    my_put_nbr(va_arg(list, int));
}

