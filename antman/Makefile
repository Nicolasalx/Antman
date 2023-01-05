##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC			=	src/main.c \
				src/error_manager.c \
				src/check_arg_validity.c \
				src/analyse_file_content.c \
				src/my_sort.c \
				src/create_all_leaf.c \
				src/create_tree.c \
				src/func_linked_list.c	\
				src/def_file_category.c \
				src/free_all_data.c \
				src/encode_tree.c \
				src/free_tree.c

CFLAGS		=	-W -Wall -Wextra -I ../include

NAME		=	antman

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
