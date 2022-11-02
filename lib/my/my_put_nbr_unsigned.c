/*
** MY_PRINTF PROJECT, 2022
** my_put_nbr_unsigned.c
** File description:
** my_put_nbr_unsigned
*/

void my_putchar(char c);

int my_put_nbr_unsigned(unsigned int nb)
{
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + '0');
    }
    if (nb > 9) {
        my_put_nbr_unsigned(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    return 0;
}
