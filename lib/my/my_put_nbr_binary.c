/*
** MY_PRINTF PROJECT, 2022
** my_put_nbr_binary.c
** File description:
** my_put_nbr_binary
*/

void my_putchar(char c);

int my_put_nbr_binary(unsigned int nb)
{
    if (nb < 0) {
            my_putchar('-');
            nb = nb * (- 1);
    }
    if (nb >= 0 && nb <= 1){
        my_putchar(nb + '0');
    }
    if (nb > 1) {
        my_put_nbr_binary(nb / 2);
        my_putchar((nb % 2) + '0');
    }
    return 0;
}
