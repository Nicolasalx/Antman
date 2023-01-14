##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

MAIN		=	src/main.c
MAINTEST	=	../tests/tests_giantman/main_test_giantman.c

SRC			=	src/error_manager.c \
				src/check_arg_validity.c \
				src/is_file_not_empty.c \
				src/analyze_file_content.c \
				src/recover_tree_from_file.c \
				src/execute_decoding.c \
				src/free_all_data.c \
				src/free_tree_data.c \
				src/func_linked_list.c \
				src/recreate_tree.c \
				src/func_bit_manipulation.c \
				src/print_decoded_file.c


SRC_TESTS	=	../tests/tests_giantman/test_giantman.c

CFLAGS		=	-W -Wall -Wextra -I ../include

NAME		=	giantman

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
