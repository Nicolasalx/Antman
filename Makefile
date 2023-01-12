##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile
##

SRC_ZIP		=	antman
SRC_UNZIP	=	giantman

$(MAKE):
	cd $(SRC_ZIP) && $(MAKE)
	cd $(SRC_UNZIP) && $(MAKE)

all:
	cd $(SRC_ZIP) && $(MAKE) all
	cd $(SRC_UNZIP) && $(MAKE) all

clean:
	cd $(SRC_ZIP) && $(MAKE) clean
	cd $(SRC_UNZIP) && $(MAKE) clean

fclean:
	cd $(SRC_ZIP) && $(MAKE) fclean
	cd $(SRC_UNZIP) && $(MAKE) fclean

re: fclean all

unit_tests:
	cd $(SRC_ZIP) && $(MAKE) unit_tests
	cd $(SRC_UNZIP) && $(MAKE) unit_tests

tests_run: unit_tests
	cd $(SRC_ZIP) && $(MAKE) tests_run
	cd $(SRC_UNZIP) && $(MAKE) tests_run

gcovr:
	gcovr --exclude tests/
	gcovr --exclude tests/ --branches

.PHONY: all clean fclean re unit_tests tests_run gcovr
