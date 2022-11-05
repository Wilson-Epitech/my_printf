/*
** MY_PRINTF PROJECT, 2022
** func_flags.h
** File description:
** func flags.h
*/

#ifndef FUNC_FLAGS_H
    #define FUNC_FLAGS_H

int flag_b(const char *format, va_list list, int i);
int flag_p(const char *format, va_list list, int i);
int flag_smaj(const char *format, va_list list, int i);
int flag_o(const char *format, va_list list, int i);
int flag_s(const char *format, va_list list, int i);
int flag_c(const char *format, va_list list, int i);
int flag_d(const char *format, va_list list, int i);
int flag_i(const char *format, va_list list, int i);
int flag_percent(const char *format, va_list list, int i);
int flag_u(const char *format, va_list list, int i);
int flag_x(const char *format, va_list list, int i);
int flag_xmaj(const char *format, va_list list, int i);
int flag_f(const char *format, va_list list, int i);
int flag_n(const char *format, va_list list, int i);
int structure_call_flags(const char *format, va_list list, int i);

#endif //FUNC_FLAGS.H
