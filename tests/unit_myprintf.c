/*
** MY_PRINTF PROJECT, 2022
** Unit test
** File description:
** Myprintf
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../includes/my.h"

int my_printf(char *str, ...);

void redirect_all_stdout(void)
{
    cr_redirect_stdout();
    cr_redirect_stderr();
}

Test (check_u_flag, check_stdout, .init=redirect_all_stdout)
{
    unsigned int u = 3147483650;
    int count_my = 0;
    int count_p = 55;
    count_my = my_printf("Test of 'u' flag : %u (my_putnbr_unsigned_int)\n", u);
    cr_assert_stdout_eq_str("Test of 'u' flag : 3147483650 (my_putnbr_unsigned_int)\n");
    cr_assert_eq(count_my, count_p);
}

Test (check_b_flag, check_stdout, .init=redirect_all_stdout)
{
    unsigned int b = 51;
    int count_my = 0;
    int count_p = 49;
    count_my = my_printf("Test of 'b' flag : 51 = %b (base10 to base2)\n", b);
    cr_assert_stdout_eq_str("Test of 'b' flag : 51 = 110011 (base10 to base2)\n");
    cr_assert_eq(count_my, count_p);
}

Test (check_p_flag, check_stdout, .init=redirect_all_stdout)
{
    int count_my = 0;
    int count_p = 32;
    char i = 7;
    char *p = &i;
    count_my = my_printf("Test of p flag : %p\n", p);
    cr_assert_eq(count_my, count_p);
}

Test (check_s_flag, check_stdout, .init=redirect_all_stdout)
{
    int count_my = 0;
    int count_p = 18;
    count_my = my_printf("Je m'appelle %s.", "Axel");
    cr_assert_stdout_eq_str("Je m'appelle Axel.");
    cr_assert_eq(count_my, count_p);
}

Test (check_i_flag, check_stdout, .init=redirect_all_stdout)
{
    int nb = 457;
    int count_my = 0;
    int count_p = 20;
    count_my = my_printf("J'ai %i (%d) ans !", nb, nb);
    cr_assert_stdout_eq_str("J'ai 457 (457) ans !");
    cr_assert_eq(count_my, count_p);
}

Test (check_d_flag, check_stdout, .init=redirect_all_stdout)
{
    int nb = 12;
    int count_my = 0;
    int count_p = 29;
    count_my = my_printf("%d et %d sont le même nombre", nb, nb);
    cr_assert_stdout_eq_str("12 et 12 sont le même nombre");
    cr_assert_eq(count_my, count_p);
}

Test (check_c_flag, check_stdout, .init=redirect_all_stdout)
{
    int count_my = 0;
    int count_p = 20;
    count_my = my_printf("Test of 'c' flag : %c", 'c');
    cr_assert_stdout_eq_str("Test of 'c' flag : c");
    cr_assert_eq(count_my, count_p);
}

Test (check_o_flag, check_stdout, .init=redirect_all_stdout)
{
    unsigned int o = 3147483650;
    int count_my = 0;
    int count_p = 49;
    count_my = my_printf("Test of 'o' flag : %o (base10 to base8)\n", o);
    cr_assert_stdout_eq_str("Test of 'o' flag : 27346545002 (base10 to base8)\n");
    cr_assert_eq(count_my, count_p);
}

Test (check_s_maj_flag, check_stdout, .init=redirect_all_stdout)
{
    char str[5] = "toto";
    str[1] = 6;
    my_printf("Test of 'S' flag : %S (show octal value of non-printable char)\n", str);
    cr_assert_stdout_eq_str("Test of 'S' flag : t\\006to (show octal value of non-printable char)\n");
}

Test (check_x_flag, check_stdout, .init=redirect_all_stdout)
{
    int count_my = 0;
    int count_p = 26;
    count_my = my_printf("29 = %x (base10 to base16)", 29);
    cr_assert_stdout_eq_str("29 = 1d (base10 to base16)");
    cr_assert_eq(count_my, count_p);
}

Test (check_x_maj_flag, check_stdout, .init=redirect_all_stdout)
{
    int count_my = 0;
    int count_p = 26;
    count_my = my_printf("29 = %X (base10 to base16)", 29);
    cr_assert_stdout_eq_str("29 = 1D (base10 to base16)");
    cr_assert_eq(count_my, count_p);
}

Test (check_percent_flag, check_stdout, .init=redirect_all_stdout)
{
    int count_my = 0;
    int count_p = 24;
    count_my = my_printf("Test of percent flag : %%%i%%%s", 5, "string");
    cr_assert_stdout_eq_str("Test of percent flag : %5%string");
}
