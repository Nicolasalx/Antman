/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "antman.h"
#include "my_string.h"
#include "my_malloc.h"

int main(int argc, char **argv)
{
    if (check_arg_validity(argc, argv) != 0)
        return 84;

    file_info_t file_data;
    analyse_file_content(argv[1], &file_data);
    if (error_manager(0) != 0)
        return 84;
    my_sort(file_data.occur_char, file_data.character, file_data.nb_diff_char);

    //tree_t *tree =
    create_tree(&file_data);

    free_str(file_data.character);
    free_array(file_data.occur_char);
    return 0;
}
