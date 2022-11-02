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
    int (*ptr)(va_list list);
} structure_t;
#endif
