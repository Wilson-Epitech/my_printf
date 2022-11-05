/*
** MY_PRINTF PROJECT, 2022
** func count
** File description:
** func count printf char
*/

int func_count(const char *format, int i)
{
    int count = 0;
    i = 0;

    while (format[i] != '\0') {
        if (format[i] == '%' && format[i + 1] == 'n') {
            return count;
        }
        count ++;
        i++;
    }
    return count;
}
