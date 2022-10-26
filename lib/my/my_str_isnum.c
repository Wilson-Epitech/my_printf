/*
** MY_PRINTF PROJECT, 2022
** my_isnum
** File description:
** func
*/

int my_str_isnum(char const *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        if (!(str[i] >= '0' && str[i] <= '9')) {
            return 0;
        }
        i++;
    }
    return 1;
}
