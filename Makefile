##
## MY_PRINTF PROJECT, 2022
## day10
## File description:
## task01 makefile
##

SRC =	func_count.c				\
	src/my_printf.c				\
	src/call_flags.c			\
	flags/flags_bpsmajo.c			\
	flags/flags_scdi.c			\
	flags/flags_percentuxxmaj.c		\
	flags/flags_fn.c			\
	lib/my/my_putchar.c			\
	lib/my/my_put_nbr.c			\
	lib/my/my_putstr.c			\
	lib/my/my_strlen.c			\
	lib/my/my_strcpy.c			\
	lib/my/my_put_nbr_unsigned.c		\
	lib/my/my_put_nbr_octal.c		\
	lib/my/my_put_nbr_hexa.c		\
	lib/my/my_put_nbr_float.c		\
	lib/my/my_put_nbr_hexa_maj.c		\
	lib/my/my_put_nbr_binary.c		\
	lib/my/my_put_nbr_hexa_adress.c		\
	lib/my/non_printable_characters.c	\
	lib/my/my_put_nbr_size.c		\

OBJ =	$(SRC:.c=.o)

NAME =	libmy.a

all:	$(NAME)

tests_run:
		gcc -o unit_tests $(SRC) tests/unit_myprintf.c --coverage -lcriterion
		./unit_tests
tests_clean:
		$(RM) unit_test*
		cd tests && $(RM) *~

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	$(RM) -f $(OBJ)
	$(RM) -f *~
	cd lib/my && $(RM) -f *.o && $(RM) -f *~
	cd flags && $(RM) -f *.o && $(RM) -f *~
	cd src && $(RM) -f *.o && $(RM) -f *~

fclean: clean
	rm -f $(NAME)
	rm -f $(NAME2)
	make tests_clean
	rm -f a.out*

re: fclean all
