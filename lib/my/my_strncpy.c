/*
** MY_PRINTF PROJECT, 2022
** day06
** File description:
** task02
*/

char *my_strncpy( char * dest , char const * src , int n )
{
    int i;

    i = 0;
    while (i != n) {
        dest[i] = src[i];
        i++;
    }
    return dest;
}
