/*
** MY_PRINTF PROJECT, 2022
** func_flags.h
** File description:
** func flags.h
*/

#ifndef FUNC_FLAGS_H
    #define FUNC_FLAGS_H

int flag_b(va_list list);
int flag_p(va_list list);
int flag_smaj(va_list list);
int flag_o(va_list list);
int flag_s(va_list list);
int flag_c(va_list list);
int flag_d(va_list list);
int flag_i(va_list list);
int flag_percent(va_list list);
int flag_u(va_list list);
int flag_x(va_list list);
int flag_xmaj(va_list list);
int structure_call_flags(const char *format, va_list list, int i);

#endif //FUNC_FLAGS.H
