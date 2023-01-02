/*
** EPITECH PROJECT, 2023
** check_arg_validity
** File description:
** check_arg_validity
*/

#include "antman.h"
#include "my_number.h"

int check_arg_validity(int argc, char **argv)
{
    if (argc != 3) {
        print_error(error_manager(TOO_MUCH_OR_MISSING_ARG));
        return 84;
    }
    int option = my_get_nb(argv[2]);
    if (option < 1 || option > 3) {
        print_error(error_manager(INVALID_OPTION));
        return 84;
    }
    return 0;
}
