/*
** MY_PRINTF PROJECT, 2022
** my.h lib
** File description:
** my.h lib
*/

#ifndef MY_H
    #define MY_H
    #include <stdarg.h>
int my_strlen(char const *str);
int my_put_nbr(int nb);
int my_put_nbr_float(float nb);
int my_put_nbr_unsigned(unsigned int nb);
int my_put_nbr_octal(unsigned int nb);
unsigned long long my_put_nbr_hexa_adress(unsigned long long nb);
int my_put_nbr_hexa(unsigned int nb);
int my_put_nbr_hexa_maj(unsigned int nb);
int my_put_nbr_binary(unsigned int nb);
int my_put_nbr_size(const char *format, va_list list, int i);
int my_putstr(char const *str);
int *my_strcpy(char * dest , char const * src);
void my_putchar(char c);
int func_count(const char *format, int i);
int non_printable_characters(char *str);
int plus(int nb);
#endif
