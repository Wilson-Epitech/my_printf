/*
** MY_PRINTF PROJECT, 2022
** my.h
** File description:
** my.h
*/

#ifndef MY_H_
    #define MY_H_
int flag_s(const char *format, int i, va_list list);
int flag_c(const char *format, int i, va_list list);
int flag_d(const char *format, int i, va_list list);
int flag_percent(const char *format, int i, va_list list);
int flag_u(const char *format, int i, va_list list);
int flag_s(const char *format, int i, va_list list);
int flag_x(const char *format, int i, va_list list);
int flag_X(const char *format, int i, va_list list);
int flag_b(const char *format, int i, va_list list);
int flag_p(const char *format, int i, va_list list);
int flag_S(const char *format, int i, va_list list);
int flag_o(const char *format, int i, va_list list);
#endif //MY.H
