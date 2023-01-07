/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "giantman.h"
#include "my_string.h"

int main(int argc, char **argv)
{
    file_t file_data;
    tree_t tree_data;
    if (check_arg_validity(argc, argv) != 0)
        return 84;
    if (is_file_not_empty(argv[1]) == IS_EMPTY) {
        my_putstr("\n");
        return 0;
    }
    analyze_file_content(argv[1], &file_data);
    if (error_manager(0) != 0)
        return 84;

    if (file_data.encoding_algo == ALGO_SMALL_FILE) {

    } else {
        recover_tree_from_file(&file_data, &tree_data);
    }

    my_putstr("\n");
    return 0;
}
