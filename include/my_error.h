/*
** EPITECH PROJECT, 2022
** my_error
** File description:
** my_error
*/

#ifndef MY_ERROR
    #define MY_ERROR

    #define ERROR -1
    #define TOO_MUCH_OR_MISSING_ARG 1
    #define INVALID_OPTION 2
    #define INVALID_FILE 3
    #define OPTION_NOT_CORRESPONDING_TO_FILE 4
    #define MALLOC_ERROR 5
    #define READ_ERROR 6

int error_manager(int error_detected);
void print_error(int error);

#endif /* !MY_ERROR */
