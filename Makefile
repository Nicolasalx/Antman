##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_ZIP		=	antman
SRC_UNZIP	=	giantman

NAME_ZIP		=	antman
NAME_UNZIP		=	giantman

$(NAME):
	cd $(SRC_ZIP) && $(MAKE)
	cd $(SRC_UNZIP) && $(MAKE)

all:
	cd $(SRC_ZIP) && $(MAKE) all
	cd $(SRC_UNZIP) && $(MAKE) all

clean:
	cd $(SRC_ZIP) && $(MAKE) clean
	cd $(SRC_UNZIP) && $(MAKE) clean

fclean: clean
	cd $(SRC_ZIP) && $(MAKE) fclean
	cd $(SRC_UNZIP) && $(MAKE) fclean

re: fclean all

.PHONY: all clean fclean re
