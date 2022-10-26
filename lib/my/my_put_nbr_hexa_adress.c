/*
** MY_PRINTF PROJECT, 2022
** my_put_nbr_hexa_adress.c
** File description:
** my_put_nbr_hexa_adress
*/

int my_putchar(char c);

unsigned long long my_put_nbr_hexa_adress(unsigned long long nb)
{
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + '0');
    }
    if (nb >= 10 && nb <= 15) {
        my_putchar(nb + 'a' - 10);
    }
    if (nb > 15) {
        my_put_nbr_hexa_adress(nb / 16);
        my_put_nbr_hexa_adress(nb % 16);
    }
    return 0;
}
