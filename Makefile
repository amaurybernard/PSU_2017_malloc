##
## EPITECH PROJECT, 2018
## malloc
## File description:
## make
##

SRC		=		malloc.c

OBJ		=		$(SRC:.c=.o)

NAME	= 		libmy_malloc.so

CFLAGS	=		-Wall -Wextra -Werror

CC		=		gcc

RM		= 		rm -f

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -shared $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean re

.PHONY: all clean fclean re