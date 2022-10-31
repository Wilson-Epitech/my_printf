##
## MY_PRINTF PROJECT, 2022
## makefile
## File description:
## makefile
##

CC = gcc

SRC = my_printf_pointers.c

OBJ =   $(SRC:.c=.o)

NAME =  test

all:    $(NAME)

$(NAME):        $(OBJ)
	cd lib/my && make && make clean
	$(CC) -o $(NAME) $(OBJ) -L lib/my -lmy

clean:
	$(RM) *.o
	$(RM) ./test
	$(RM) *~


fclean: clean
	rm $(NAME)

re: clean all

.PHONY: re fclean clean all
