##
## EPITECH PROJECT, 2022
## My_hunter
## File description:
## My_hunter
##

NAME_ZIP = antman

NAME_DEZIP = giantman

CC = gcc

RM = rm -f

CFLAGS = -W -Wall -Wextra -I ./include

SRC_ZIP = 	src/antman/antman.c

SRC_DEZIP = src/giantman/giantman.c

SRC_LIB = 	lib/my/my_putchar.c	\
			lib/my/my_putstr.c	\
			lib/my/my_strlen.c

OBJ_ZIP = $(SRC_ZIP:.c=.o)

OBJ_DEZIP = $(SRC_DEZIP:.c=.o)

OBJ_LIB = $(SRC_LIB:.c=.o)

all:
	$(CC) -o $(NAME_ZIP) $(SRC_ZIP) $(SRC_LIB) $(CFLAGS)
	$(CC) -o $(NAME_DEZIP) $(SRC_DEZIP) $(SRC_LIB) $(CFLAGS)
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(OBJ)

re: fclean all

.PHONY: all clean fclean re
