/*
** MY_PRINTF PROJECT, 2022
** flags_bpSo.c
** File description:
** flags b p S o
*/

int my_putstr(char const *str);
int my_put_nbr_binary(unsigned int nb);
unsigned long long my_put_nbr_hexa_adress(unsigned long long nb);
int non_printable_characters(char *str);
int my_put_nbr_octal(int nb);

int flag_b(const char *format, int i, va_list list)
{
    my_put_nbr_binary(va_arg(list, unsigned int));
}

int flag_p(const char *format, int i, va_list list)
{
    my_putstr("0x");
    my_put_nbr_hexa_adress(va_arg(list, unsigned long long));
}

int flag_S(const char *format, int i, va_list list)
{
    non_printable_characters(va_arg(list, char *));
}

int flag_o(const char *format, int i, va_list list)
{
    my_put_nbr_octal(va_arg(list, int));
}
