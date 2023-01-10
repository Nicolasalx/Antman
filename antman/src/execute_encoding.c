/*
** EPITECH PROJECT, 2023
** execute_encoding
** File description:
** execute_encoding
*/

#include "antman.h"
#include "my_string.h"

void execute_encoding(file_info_t *file_data, tree_data_t *tree)
{
    if (def_file_category(file_data) == SMALL_FILE ||
        file_data->nb_diff_char <= 1) {
        my_putstr(file_data->content);
    } else {
        create_tree(file_data, tree);
        char **leaf_path = get_all_leaf_path(file_data, tree);
        char *new_file_rep = change_file_content_rep(file_data, leaf_path);
        encode_tree(file_data);
        encode_str_to_byte(new_file_rep);
        free_tree_and_leaf(tree, file_data, leaf_path, new_file_rep);
    }
}
