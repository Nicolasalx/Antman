##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC			=	src/main.c \
				src/error_manager.c

CFLAGS		=	-W -Wall -Wextra -I ./include

NAME		=	a.out

LIBNAME		=	lib/my_lib.a

OBJ			=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	cd lib/ && $(MAKE)
	gcc -o $(NAME) $(SRC) $(LIBNAME) $(CFLAGS)

all: $(NAME)

clean:
	cd lib/ && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd lib/ && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
