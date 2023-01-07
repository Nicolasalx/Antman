/*
** EPITECH PROJECT, 2022
** main
** File description:
** main
*/

#include "antman.h"
#include "my_string.h"
#include "my_number.h"

int main(int argc, char **argv)
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

    if (def_file_category(&file_data) == SMALL_FILE ||
        file_data.nb_diff_char <= 1) {
        my_putstr("Petit fichier\n");
    } else {
        create_tree(&file_data, &tree);
        char **leaf_path = get_all_leaf_path(&file_data, &tree);
        char *new_file_rep = change_file_content_rep(&file_data, leaf_path);
        encode_tree(leaf_path);
        encode_str_to_byte(new_file_rep);
        free_tree_and_leaf(&tree, &file_data, leaf_path, new_file_rep);
    }

    my_putstr("\n");
    free_all_data(&file_data);
    return 0;
}
