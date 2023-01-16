/*
** EPITECH PROJECT, 2023
** check_arg_validity
** File description:
** check_arg_validity
*/

#include "antman.h"
#include "my_number.h"
#include "my_string.h"

int check_file_extenstion(char *filepath, int option)
{
    char file_ext[6];
    ini_str_to_zero(file_ext, 6);
    int index_ext = 0;
    for (int i = (my_strlen(filepath) - 1); i >= 0 && filepath[i] != '.'; --i) {
        file_ext[index_ext] = filepath[i];
        ++index_ext;
        if (index_ext > 5) {
            return FALSE;
        }
    }
    my_revstr(file_ext);
    if (option == 1 && my_strcmp(file_ext, "lyr") == 0)
        return TRUE;
    if (option == 2 && my_strcmp(file_ext, "html") == 0)
        return TRUE;
    if (option == 3 && my_strcmp(file_ext, "ppm") == 0)
        return TRUE;
    return FALSE;
}

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
    if (check_file_extenstion(argv[1], option) != TRUE) {
        print_error(error_manager(OPTION_NOT_CORRESPONDING_TO_FILE));
        return 84;
    }
    return 0;
}
