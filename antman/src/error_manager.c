/*
** EPITECH PROJECT, 2022
** error_manager
** File description:
** error_manager
*/

#include <unistd.h>
#include "my_error.h"

int error_manager(int error_detected)
{
    static int error = 0;
    if (error_detected != 0) {
        error = error_detected;
    }
    return error;
}

void print_error(int error)
{
    switch (error) {
    case ERROR:
        write(2, "error\n", 6);
        break;
    case TOO_MUCH_OR_MISSING_ARG:
        write(2, "Too much or missing arguments\n", 30);
        break;
    case INVALID_OPTION:
        write(2, "Invalid option\n", 15);
        break;
    case INVALID_FILE:
        write(2, "Invalid file\n", 13);
        break;
    case OPTION_NOT_CORRESPONDING_TO_FILE:
        write(2, "Option not corresponding to the file\n", 37);
        break;
    default:
        write(2, "Unnamed error\n", 14);
        break;
    }
}
