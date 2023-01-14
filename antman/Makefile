##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

MAIN		=	src/main.c
MAINTEST	=	../tests/tests_antman/main_test_antman.c

SRC			=	src/error_manager.c \
				src/check_arg_validity.c \
				src/analyse_file_content.c \
				src/my_sort.c \
				src/create_all_leaf.c \
				src/create_tree.c \
				src/func_linked_list.c	\
				src/def_file_category.c \
				src/free_all_data.c \
				src/encode_tree.c \
				src/free_tree_and_leaf.c \
				src/encode_file_with_tree.c \
				src/get_path_leaf.c \
				src/is_file_not_empty.c \
				src/encode_str_to_byte.c \
				src/func_bit_manipulation.c \
				src/execute_encoding.c

SRC_TESTS	=	../tests/tests_antman/test_antman.c

CFLAGS		=	-W -Wall -Wextra -I ../include

NAME		=	antman

SRCLIB		=	../lib/
LIBNAME		=	../lib/my_lib.a

OBJ			=	$(MAIN:.c=.o) $(SRC:.c=.o)

RUN_TEST	=	--coverage -lcriterion

NAME_TESTS	=	unit_tests

$(NAME): $(OBJ)
	cd $(SRCLIB) && $(MAKE)
	gcc -o $(NAME) $(OBJ) $(LIBNAME) $(CFLAGS)

all: $(NAME)

clean:
	cd $(SRCLIB) && $(MAKE) clean
	rm -f $(OBJ)
	rm -f *.gcno
	rm -f *.gcda

fclean: clean
	cd $(SRCLIB) && $(MAKE) fclean
	rm -f $(NAME)
	rm -f $(NAME_TESTS)

re: fclean all

unit_tests: fclean
	cd $(SRCLIB) && $(MAKE)
	gcc -o $(NAME_TESTS) $(SRC_TESTS) $(MAINTEST) $(SRC) $(LIBNAME) \
	$(CFLAGS) $(RUN_TEST)

tests_run: unit_tests
	./$(NAME_TESTS)

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean re unit_tests tests_run gcovr
