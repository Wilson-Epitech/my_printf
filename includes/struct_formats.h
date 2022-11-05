/*
** MY_PRINTF PROJECT, 2022
** struct_formats.h
** File description:
** structure for formats
*/

#ifndef FORMATS_H_
    #define FORMATS_H_
typedef struct {
    char format;
    int (*ptr) (va_list list);
} structure_u;
#endif
