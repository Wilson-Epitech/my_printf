/*
** MY_PRINTF PROJECT, 2022
** flags.h
** File description:
** pointers flags
*/

/*
void (* ptr_my_putchar)(char) = &my_putchar;
int (* ptr_my_putstr)(char *) = &my_putstr;
int (* ptr_my_put_nbr)(int) = &my_put_nbr;
int (* ptr_my_put_nbr_hexa)(unsigned int) = &my_put_nbr_hexa;
int (* ptr_my_put_nbr_hexa_maj)(unsigned int) = &my_put_nbr_hexa_maj;
int (* ptr_my_put_nbr_binary)(unsigned int) = &my_put_nbr_binary;
int (* ptr_my_put_nbr_octal)(int) = &my_put_nbr_octal;
int (* ptr_non_printable_characters)(char *) = &non_printable_characters;
*/

#ifndef FLAGS_H_
    #include "my.h"
    #define FLAGS_H_
typedef struct structure {
    char c;
    int (*ptr)(va_list);
} structure_t;

structure_t call_flags[] = {
        {'s', &flag_s},
        {'c', &flag_c},
        {'d', &flag_d},
        {'i', &flag_percent},
        {'%', &flag_u},
        {'u', &flag_s},
        {'x', &flag_x},
        {'X', &flag_X},
        {'b', &flag_b},
        {'p', &flag_p},
        {'S', &flag_S},
        {'o', &flag_o},
        {'\0', NULL}
};

#endif
