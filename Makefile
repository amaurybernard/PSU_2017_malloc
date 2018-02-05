##
## EPITECH PROJECT, 2018
## malloc
## File description:
## make
##

SRC		=		malloc.c
SRC		+=		header.c
SRC		+=		header_free.c

SRC_TEST	=	test/test.c

OBJ_TEST	=	$(SRC_TEST:.c=.o)

OBJ		=		$(SRC:.c=.o)

NAME	= 		libmy_malloc.so

CFLAGS	=		-Wall -Wextra -Werror -fPIC

CC		=		gcc

RM		= 		rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

debug: CFLAGS = -Wall -Wextra -g -g3 -fsanitize=address -fPIC
debug: CC = clang -fsanitize=address
debug: re

test: $(OBJ) $(OBJ_TEST)
	$(CC) -fPIC $(OBJ) $(OBJ_TEST) -o test.out
	rm test/test.o

.PHONY: all clean fclean re
