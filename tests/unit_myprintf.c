/*
** MY_PRINTF PROJECT, 2022
** B-CPE-101 my_printf
** File description:
** Tests for my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my.h"

int my_printf(const char *, ...);

void redirect_all_std (void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (my_printf, simple_error, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %k", 69), 12);
    cr_assert_stdout_eq_str("hello world ");
}

Test (my_printf, simple, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world"), 11);
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, simple_i, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %i", 69), 14);
    cr_assert_stdout_eq_str("hello world 69");
}

Test (my_printf, simple_i_neg, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %i", -69), 15);
    cr_assert_stdout_eq_str("hello world -69");
}

Test (my_printf, simple_i_min, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %i", -2147483647), 23);
    cr_assert_stdout_eq_str("hello world -2147483647");
}

Test (my_printf, simple_d, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %d", 69), 14);
    cr_assert_stdout_eq_str("hello world 69");
}

Test (my_printf, simple_d_neg, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %d", -69), 15);
    cr_assert_stdout_eq_str("hello world -69");
}

Test (my_printf, simple_d_min, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %d", -2147483647), 23);
    cr_assert_stdout_eq_str("hello world -2147483647");
}

Test (my_printf, simple_s, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello%s", " world"), 11);
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, simple_c, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello worl%c", 'd'), 11);
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, simple_percent, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %%"), 13);
    cr_assert_stdout_eq_str("hello world %");
}

Test (my_printf, simple_b, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %b", 123), 19);
    cr_assert_stdout_eq_str("hello world 1111011");
}

Test (my_printf, simple_b_max, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %b", 2147483647), 43);
    cr_assert_stdout_eq_str("hello world 1111111111111111111111111111111");
}

Test (my_printf, simple_o, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %o", 63432), 18);
    cr_assert_stdout_eq_str("hello world 173710");
}

Test (my_printf, simple_o_max, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %o", 2147483647), 23);
    cr_assert_stdout_eq_str("hello world 17777777777");
}

Test (my_printf, simple_u, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %u", 6436), 16);
    cr_assert_stdout_eq_str("hello world 6436");
}

Test (my_printf, simple_u_max, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %u", 2147483647), 22);
    cr_assert_stdout_eq_str("hello world 2147483647");
}

Test (my_printf, simple_x, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %x", 69951), 17);
    cr_assert_stdout_eq_str("hello world 1113f");
}

Test (my_printf, simple_x_max, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %x", 2147483647), 20);
    cr_assert_stdout_eq_str("hello world 7fffffff");
}

Test (my_printf, simple_X, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %X", 703710), 17);
    cr_assert_stdout_eq_str("hello world ABCDE");
}

Test (my_printf, simple_X_max, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %X", 2147483647), 20);
    cr_assert_stdout_eq_str("hello world 7FFFFFFF");
}

Test (my_printf, simple_e, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %e", -119.0), 24);
    cr_assert_stdout_eq_str("hello world -1.190000e+02");
}

Test (my_printf, simple_e_long, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %e", -119000000000.000001435678), 24);
    cr_assert_stdout_eq_str("hello world -1.190000e+11");
}

Test (my_printf, simple_e_extra_long, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %e", 119.01435678), 23);
    cr_assert_stdout_eq_str("hello world 1.190144e+02");
}

Test (my_printf, simple_e_max, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %e", 2147483647.0), 23);
    cr_assert_stdout_eq_str("hello world 2.147484e+09");
}

Test (my_printf, simple_e_min, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %e", -2147483647.0), 24);
    cr_assert_stdout_eq_str("hello world -2.147484e+09");
}

Test (my_printf, simple_E, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %E", 0.0473), 23);
    cr_assert_stdout_eq_str("hello world 4.730000E-02");
}

Test (my_printf, simple_E_complex, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %E", 0.000000000001234), 23);
    cr_assert_stdout_eq_str("hello world 1.234000E-12");
}

Test (my_printf, simple_E_ultra_long, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %E", 0.0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001234), 24);
    cr_assert_stdout_eq_str("hello world 1.234000E-112");
}

Test (my_printf, simple_E_round, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %E", 123456789.0), 23);
    cr_assert_stdout_eq_str("hello world 1.234568e+08");
}

Test (my_printf, simple_p, .init=redirect_all_std, .timeout=1.0)
{
    int b = 100;
    int *a = &b;
    cr_assert(my_printf("hello world %p", &a) < 240);
}

Test (my_printf, simple_f, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %f", -119.05), 23);
    cr_assert_stdout_eq_str("hello world -119.050000");
}

Test (my_printf, simple_F, .init=redirect_all_std, .timeout=1.0)
{
    cr_assert_eq(my_printf("hello world %F", 0.04738951), 20);
    cr_assert_stdout_eq_str("hello world 0.047390");
}

Test (my_printf, simple_n, .init=redirect_all_std, .timeout=1.0)
{
    int b = 5;
    int *n = &b;
    cr_assert_eq(my_printf("hello%n world", n), 11);
    cr_assert_eq(*n, 5);
    cr_assert_stdout_eq_str("hello world");
}
