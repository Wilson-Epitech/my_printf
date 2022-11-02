/*
** MY_PRINTF PROJECT, 2022
** my_put_nbr_octal.c
** File description:
** my_put_nbr_octal
*/

void my_putchar(char c);

int my_put_nbr_octal(int nb)
{
    if (nb < 0) {
            my_putchar('-');
            nb = nb * (- 1);
    }
    if (nb >= 0 && nb <= 7){
        my_putchar(nb + '0');
    }
    if (nb > 7) {
        my_put_nbr_octal(nb / 8);
        my_putchar((nb % 8) + '0');
    }
    return 0;
}
