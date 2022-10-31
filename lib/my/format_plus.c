/*
** MY_PRINTF PROJECT, 2022
** format_plus.c
** File description:
** format +
*/

int my_putchar(char c);
int my_put_nbr(int nb);

int format_plus(int nb)
{
    if (nb >= 0) {
        my_putchar('+');
    }
}
