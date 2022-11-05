/*
** MY_PRINTF PROJECT, 2022
** flags.h
** File description:
** pointers flags
*/

#ifndef FLAGS_H_
    #define FLAGS_H_
typedef struct {
    char c;
    int (*ptr)(const char *format, va_list list, int i);
} structure_t;
#endif
