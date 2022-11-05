/*
** MY_PRINTF PROJECT, 2022
** plus.c
** File description:
** fonction +
*/

#include "../../includes/my.h"

int plus(int nb)
{
    if (nb >= 0) {
        my_putchar('+');
        my_put_nbr(nb);
    }  else
        my_put_nbr(nb);
}
