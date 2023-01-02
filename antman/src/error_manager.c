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
    default:
        write(2, "Unnamed error\n", 14);
        break;
    }
}
