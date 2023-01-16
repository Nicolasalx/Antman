/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "giantman.h"
#include "my_string.h"
#include "my_malloc.h"

int main(int argc, char **argv)
{
    file_t file_data;
    tree_t tree_data;
    if (check_arg_validity(argc, argv) != 0)
        return 84;
    if (is_file_not_empty(argv[1]) == IS_EMPTY) {
        return 0;
    }
    analyze_file_content(argv[1], &file_data);
    if (error_manager(0) != 0)
        return 84;

    execute_decoding(&file_data, &tree_data);

    free_all_data(&file_data);
    return 0;
}
