##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Make stumper
##

SRC		=	./SRC/main.c	\
			./SRC/my_tool.c	\
			./SRC/solv_map.c	\
			./SRC/path_calc.c	\
			./SRC/my_tool2.c

OBJ 	= 	$(SRC:.c=.o)

NAME	=	solver

$(NAME) : $(OBJ)
		gcc -o $(NAME) $(OBJ) -lm
all:	$(NAME)

clean:
			rm -f $(OBJ)

fclean:	clean
			rm -f $(NAME)

re:		fclean all
