##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC			=	src/main.c \
				src/error_manager.c \
				src/check_arg_validity.c \
				src/is_file_not_empty.c \
				src/analyze_file_content.c \
				src/recover_tree_from_file.c

CFLAGS		=	-W -Wall -Wextra -I ../include

NAME		=	giantman

SRCLIB		=	../lib/
LIBNAME		=	../lib/my_lib.a

OBJ			=	$(SRC:.c=.o)

$(NAME): $(OBJ)
	cd $(SRCLIB) && $(MAKE)
	gcc -o $(NAME) $(OBJ) $(LIBNAME) $(CFLAGS)

all: $(NAME)

clean:
	cd $(SRCLIB) && $(MAKE) clean
	rm -f $(OBJ)

fclean: clean
	cd $(SRCLIB) && $(MAKE) fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
