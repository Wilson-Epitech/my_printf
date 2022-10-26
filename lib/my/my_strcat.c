/*
** MY_PRINTF PROJECT, 2022
** day07
** File description:
** task02
*/

int my_strlen(char const *str);

char *my_strcat(char *dest, char const *src)
{
    int i = my_strlen(dest);
    int n = 0;

    while (src[n] != '\0') {
        dest[i] = src[n];
        i++;
        n++;
    }
    dest[i] = '\0';
    return dest;
}
