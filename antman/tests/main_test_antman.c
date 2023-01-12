/*
** EPITECH PROJECT, 2022
** main_test_antman
** File description:
** copy_of_main_for_test
*/

#include "antman.h"
#include "my_string.h"
#include "my_number.h"

int main_test_antman(int argc, char **argv)
{
    file_info_t file_data;
    tree_data_t tree;
    if (check_arg_validity(argc, argv) != 0)
        return 84;
    if (is_file_not_empty(argv[1]) == IS_EMPTY) {
        my_putstr("\n");
        return 0;
    }

    analyse_file_content(argv[1], &file_data);
    if (error_manager(0) != 0)
        return 84;
    my_sort(file_data.occur_char, file_data.character, file_data.nb_diff_char);

    execute_encoding(&file_data, &tree);

    my_putstr("\n");
    free_all_data(&file_data);
    return 0;
}
