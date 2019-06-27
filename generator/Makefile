##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make bsq
##

SRC		=	./src/main.c     \
			./src/error_manager.c   \
			./src/my_putchar.c  \
			./src/my_putstr.c   \
			./src/my_put_nbr.c  \
			./src/build.c   \
			./src/table.c   \
			./src/neighbor.c    \
			./src/check.c   \
			./src/other_neighbor.c  \
			./src/take_them.c   \
			./src/check_left.c  \
			./src/check_right.c \
			./src/check_up.c    \
			./src/check_down.c

OBJ 	= 	$(SRC:.c=.o)

NAME	=	generator

CFLAGS  =   -Iinclude -g3

$(NAME) : $(OBJ)
		gcc -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean:	clean
		rm -f $(NAME)

re: fclean  all
