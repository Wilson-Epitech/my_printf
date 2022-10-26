/*
** MY_PRINTF PROJECT, 2022
** day06
** File description:
** task3
*/

int my_strlen(char const *str);

char *my_evil_str(char *str)
{
    int start = 0;
    int end = my_strlen(str) - 1;
    char temp;
    while (start < end) {
        temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start = start + 1;
        end = end - 1;
    }
    return str;
}

char *my_revstr(char *str)
{
    int i;

    i = 0;
    while (str[i] != '\0') {
        str[i] = str[i];
        i--;
    }
    my_evil_str(str);
    return str;
}
