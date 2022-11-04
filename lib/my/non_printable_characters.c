/*
** MY_PRINTF PROJECT, 2022
** non_printable_characters.c
** File description:
** %S
*/

int my_putchar(char c);
int my_putstr(char const *str);
char *my_strcpy(char *dest, char const *src);
int my_put_nbr_octal(int nb);

int display0(char *str, int i)
{
    if (str[i] >= 8 && str[i] <= 64) {
        my_putchar('\\');
        my_putstr("0");
        my_put_nbr_octal(str[i]);
    }
    if (str[i] < 8) {
        my_putchar('\\');
        my_putstr("00");
        my_put_nbr_octal(str[i]);
    }
    if (str[i] > 64) {
        my_putchar('\\');
        my_put_nbr_octal(str[i]);
    }
}

int non_printable_characters(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        if (str[i] <= 32 || str[i] >= 127) {
            display0(str, i);
        } else {
            my_putchar(str[i]);
        }
        i++;
    }
}
