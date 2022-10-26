/*
** MY_PRINTF PROJECT, 2022
** my_put_nbr_hexa.c
** File description:
** my_put_nbr_hexa
*/

int my_putchar(char c);

int my_put_nbr_hexa(int nb)
{
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + '0');
    }
    if (nb >= 10 && nb <= 15) {
        my_putchar(nb + 'a' - 10);
    }
    if (nb > 15) {
        my_put_nbr_hexa(nb / 16);
        my_put_nbr_hexa(nb % 16);
    }
    return 0;
}
