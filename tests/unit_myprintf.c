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
    my_printf("hello world %k", 69);
    cr_assert_stdout_eq_str("hello world ");
}

Test (my_printf, simple, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, simple_i, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %i", 69);
    cr_assert_stdout_eq_str("hello world 69");
}

Test (my_printf, simple_i_neg, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %i", -69);
    cr_assert_stdout_eq_str("hello world -69");
}

Test (my_printf, simple_i_min, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %i", -2147483647);
    cr_assert_stdout_eq_str("hello world -2147483647");
}

Test (my_printf, simple_d, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %d", 69);
    cr_assert_stdout_eq_str("hello world 69");
}

Test (my_printf, simple_d_neg, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %d", -69);
    cr_assert_stdout_eq_str("hello world -69");
}

Test (my_printf, simple_d_min, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %d", -2147483647);
    cr_assert_stdout_eq_str("hello world -2147483647");
}

Test (my_printf, simple_s, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello%s", " world");
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, simple_c, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello worl%c", 'd');
    cr_assert_stdout_eq_str("hello world");
}

Test (my_printf, simple_percent, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %%");
    cr_assert_stdout_eq_str("hello world %");
}

Test (my_printf, simple_b, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %b", 123);
    cr_assert_stdout_eq_str("hello world 1111011");
}

Test (my_printf, simple_b_max, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %b", 2147483647);
    cr_assert_stdout_eq_str("hello world 1111111111111111111111111111111");
}

Test (my_printf, simple_o, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %o", 63432);
    cr_assert_stdout_eq_str("hello world 173710");
}

Test (my_printf, simple_o_max, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %o", 2147483647);
    cr_assert_stdout_eq_str("hello world 17777777777");
}

Test (my_printf, simple_u, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %u", 6436);
    cr_assert_stdout_eq_str("hello world 6436");
}

Test (my_printf, simple_u_max, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %u", 2147483647);
    cr_assert_stdout_eq_str("hello world 2147483647");
}

Test (my_printf, simple_x, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %x", 69951);
    cr_assert_stdout_eq_str("hello world 1113f");
}

Test (my_printf, simple_x_max, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %x", 2147483647);
    cr_assert_stdout_eq_str("hello world 7fffffff");
}

Test (my_printf, simple_X, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %X", 703710);
    cr_assert_stdout_eq_str("hello world ABCDE");
}

Test (my_printf, simple_X_max, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %X", 2147483647);
    cr_assert_stdout_eq_str("hello world 7FFFFFFF");
}

Test (my_printf, simple_e, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %e", -119.0);
    cr_assert_stdout_eq_str("hello world -1.190000e+02");
}

Test (my_printf, simple_e_long, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %e", -119000000000.000001435678);
    cr_assert_stdout_eq_str("hello world -1.190000e+11");
}

Test (my_printf, simple_e_extra_long, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %e", 119.01435678);
    cr_assert_stdout_eq_str("hello world 1.190144e+02");
}

Test (my_printf, simple_e_max, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %e", 2147483647.0);
    cr_assert_stdout_eq_str("hello world 2.147484e+09");
}

Test (my_printf, simple_e_min, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %e", -2147483647.0);
    cr_assert_stdout_eq_str("hello world -2.147484e+09");
}

Test (my_printf, simple_E, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %E", 0.0473);
    cr_assert_stdout_eq_str("hello world 4.730000E-02");
}

Test (my_printf, simple_E_complex, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %E", 0.000000000001234);
    cr_assert_stdout_eq_str("hello world 1.234000E-12");
}

Test (my_printf, simple_p, .init=redirect_all_std, .timeout=1.0)
{
    int b = 100;
    int *a = &b;
    cr_assert(my_printf("hello world %p", &a) < 240);
}

Test (my_printf, simple_f, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %f", -119.05);
    cr_assert_stdout_eq_str("hello world -119.050000");
}

Test (my_printf, simple_F, .init=redirect_all_std, .timeout=1.0)
{
    my_printf("hello world %F", 0.04738951);
    cr_assert_stdout_eq_str("hello world 0.047390");
}

Test (my_printf, simple_n, .init=redirect_all_std, .timeout=1.0)
{
    int b = 5;
    int *n = &b;
    my_printf("hello%n world", n);
    cr_assert_stdout_eq_str("hello world");
}

Test (check_u_flag, check_stdout, .init=redirect_all_std)
{
    unsigned int u = 3147483650;
    int count_my = 0;
    int count_p = 55;
    count_my = my_printf("Test of 'u' flag : %u (my_putnbr_unsigned_int)\n", u);
    cr_assert_stdout_eq_str("Test of 'u' flag : 3147483650 (my_putnbr_unsigned_int)\n"); 
}

Test (check_b_flag, check_stdout, .init=redirect_all_std)
{
    unsigned int b = 51;
    int count_my = 0;
    int count_p = 49;
    count_my = my_printf("Test of 'b' flag : 51 = %b (base10 to base2)\n", b);
    cr_assert_stdout_eq_str("Test of 'b' flag : 51 = 110011 (base10 to base2)\n");
}

Test (check_s_flag, check_stdout, .init=redirect_all_std)
{
    int count_my = 0;
    int count_p = 18;
    count_my = my_printf("Je m'appelle %s.", "Axel");
    cr_assert_stdout_eq_str("Je m'appelle Axel.");
}

Test (check_i_flag, check_stdout, .init=redirect_all_std)
{
    int nb = 457;
    int count_my = 0;
    int count_p = 20;
    count_my = my_printf("J'ai %i (%d) ans !", nb, nb);
    cr_assert_stdout_eq_str("J'ai 457 (457) ans !");
}

Test (check_d_flag, check_stdout, .init=redirect_all_std)
{
    int nb = 12;
    int count_my = 0;
    int count_p = 29;
    count_my = my_printf("%d et %d sont le même nombre", nb, nb);
    cr_assert_stdout_eq_str("12 et 12 sont le même nombre");
}

Test (check_c_flag, check_stdout, .init=redirect_all_std)
{
    int count_my = 0;
    int count_p = 20;
    count_my = my_printf("Test of 'c' flag : %c", 'c');
    cr_assert_stdout_eq_str("Test of 'c' flag : c");
}

Test (check_o_flag, check_stdout, .init=redirect_all_std)
{
    unsigned int o = 3147483650;
    int count_my = 0;
    int count_p = 49;
    count_my = my_printf("Test of 'o' flag : %o (base10 to base8)\n", o);
    cr_assert_stdout_eq_str("Test of 'o' flag : 27346545002 (base10 to base8)\n");
}

Test (check_s_maj_flag, check_stdout, .init=redirect_all_std)
{
    char str[5] = "toto";
    str[1] = 6;
    my_printf("Test of 'S' flag : %S (show octal value of non-printable char)\n", str);
}

Test (check_x_flag, check_stdout, .init=redirect_all_std)
{
    int count_my = 0;
    int count_p = 26;
    count_my = my_printf("29 = %x (base10 to base16)", 29);
    cr_assert_stdout_eq_str("29 = 1d (base10 to base16)");
}



