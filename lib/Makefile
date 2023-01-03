##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lib_Makefile
##

SRCFILE		=	file/count_nb_line.c \
				file/count_size_first_line.c \
				file/count_lines_size.c \
				file/my_file_to_str.c \
				file/my_filelen.c \
				file/my_open_file.c

SRCMALLOC	=	malloc/board.c \
				malloc/str.c \
				malloc/struct_str.c \
				malloc/my_str_to_board.c \
				malloc/array.c \
				malloc/my_str_to_word.c \
				malloc/adv_board.c \
				malloc/count_size_word.c

SRCNUMBER	=	number/my_get_nb.c \
				number/max_value.c \
				number/min_value.c \
				number/count_nb_digit.c \
				number/my_nb_to_str.c \
				number/my_swap.c

SRCSTRING	=	string/my_putstr.c \
				string/my_strcat.c \
				string/my_strcmp.c \
				string/my_strcpy.c \
				string/my_strlen.c \
				string/is_in_str.c \
				string/my_str_only_cont.c \
				string/my_str_cont_atleast.c \
				string/count_occur.c \
				string/count_nb_word.c \
				string/ini_str_to_zero.c \
				string/my_swap_char.c \
				string/my_revstr.c

SRC			=	$(SRCMALLOC) \
				$(SRCNUMBER) \
				$(SRCSTRING) \
				$(SRCFILE)

OBJ			=	$(SRC:.c=.o)

CFLAGS		=	-W -Wall -Wextra -I ../include

NAME		=	my_lib.a

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

all: $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
