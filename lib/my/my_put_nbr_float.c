/*
** MY_PRINTF PROJECT, 2022
** float
** File description:
** float
*/

void my_putchar(char c);
int my_put_nbr(int nb);

void my_put_nbr_float(float nb)
{
    int avant = (int)nb;
    my_put_nbr(avant);
    my_putchar('.');

    int apres = nb * 1000000 - avant * 1000000;
    my_put_nbr(apres);
}
