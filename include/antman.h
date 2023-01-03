/*
** EPITECH PROJECT, 2022
** antman
** File description:
** antman
*/

#ifndef ANTMAN
    #define ANTMAN

    #include "my_error.h"

    #define ASCII_RANGE 256

typedef struct file_info_t {
    int nb_diff_char;
    char *character;
    int *occur_char;
} file_info_t;


int check_arg_validity(int argc, char **argv);
void analyse_file_content(char *filepath, file_info_t *file_content);
void my_sort(int *array, char *str, int size_array);

#endif /* !ANTMAN */
