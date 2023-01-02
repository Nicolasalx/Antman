/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "antman.h"
#include "my_string.h"
#include "my_malloc.h"
#include <stdio.h>

int main(int argc, char **argv)
{
    if (check_arg_validity(argc, argv) != 0)
        return 84;

    file_info_t file_content;
    file_content.character = malloc_str(ASCII_RANGE);
    file_content.occur_char = malloc_array(ASCII_RANGE);
    analyse_file_content(argv[1], &file_content);
    if (error_manager(0) != 0)
        return 84;

    for (int i = 0; i < file_content.nb_diff_char; ++i) {
        printf("Il y a %d fois le char '%c'\n",
        file_content.occur_char[i], file_content.character[i]);
    }

    free_str(file_content.character);
    free_array(file_content.occur_char);
    return 0;
}
