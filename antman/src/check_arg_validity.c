/*
** EPITECH PROJECT, 2023
** check_arg_validity
** File description:
** check_arg_validity
*/

#include "antman.h"
#include "my_number.h"
#include <stdlib.h>
#include <stdio.h>
#include "my_string.h"

int check_file_extenstion(char *filepath, int option)
{
    int size = my_strlen(filepath); int mal = 0;
    for (int x = size; filepath[x] != '.' && x >= 0; --x)
        ++mal;
    --mal; int len = 0; len = size - mal; char *dest = malloc(mal + 1);
    int ctr = 0;
    for (int x = len; filepath[x] != '\0'; ++x) {
        dest[ctr] = filepath[x]; 
        ++ctr;
    } dest[ctr] = '\0';
    if (option == 1 && my_strcmp(dest, "lyr") == 0) {
        return TRUE;
    }
    if (option == 2 && my_strcmp(dest, "html") == 0) {
        return TRUE;
    }
    if (option == 3 && my_strcmp(dest, "ppm") == 0) {
        return TRUE;
    }
    free(dest); return FALSE;
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
    printf("Return : [%d]\n", check_file_extenstion(argv[1], option));
    return 0;
}
