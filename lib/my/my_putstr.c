/*
** MY_PRINTF PROJECT, 2022
** day04
** File description:
** task02
*/

int my_putchar(char c);

int my_putstr(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}
