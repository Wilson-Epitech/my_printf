/*
** MY_PRINTF PROJECT, 2022
** my_ptrs_on_functions.c
** File description:
** Pointeurs sur fonction
*/

#include <unistd.h>

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_put_nbr(int nb)
{
    if (nb < 0) {
            my_putchar('-');
            nb = nb * (- 1);
        }
    if (nb >= 0 && nb <= 9){
        my_putchar(nb + '0');
    }
    if (nb > 9) {
        my_put_nbr(nb / 10);
        my_putchar((nb % 10) + '0');
    }
    return 0;
}

int main(void)
{
    void (*ptr_my_putchar)(char) = &my_putchar;
    int (*ptr_my_put_nbr)(int) = &my_put_nbr;
    
    ptr_my_putchar('z');
    ptr_my_putchar('\n');
    ptr_my_put_nbr(766);
    ptr_my_putchar('\n');
    return (0);
}
