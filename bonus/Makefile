##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_ZIP		=	src/antman_bonus.c
SRC_UNZIP	=	src/giantman_bonus.c

CFLAGS		=	-W -Wall -Wextra -lz

NAME_ZIP	=	antman_bonus
NAME_UNZIP	=	giantman_bonus

OBJ_ZIP		=	$(SRC_ZIP:.c=.o)
OBJ_UNZIP	=	$(SRC_UNZIP:.c=.o)

all: $(NAME_ZIP) $(NAME_UNZIP)

$(NAME_ZIP): $(OBJ_ZIP)
	gcc -o $(NAME_ZIP) $(OBJ_ZIP) $(CFLAGS)

$(NAME_UNZIP): $(OBJ_UNZIP)
	gcc -o $(NAME_UNZIP) $(OBJ_UNZIP) $(CFLAGS)

clean:
	rm -f $(OBJ_ZIP)
	rm -f $(OBJ_UNZIP)

fclean: clean
	rm -f $(NAME_ZIP)
	rm -f $(NAME_UNZIP)

re: fclean all

.PHONY: all clean fclean re
