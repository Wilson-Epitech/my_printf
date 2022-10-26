/*
** MY_PRINTF PROJECT, 2022
** day04
** File description:
** task03
*/

int my_strlen(char const *str)
{
    int i = 0;
    while (str[i] != '\0') {
        i = i + 1;
    }
    return (i);
}
