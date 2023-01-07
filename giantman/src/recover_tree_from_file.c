/*
** EPITECH PROJECT, 2023
** recover_tree_from_file
** File description:
** recover_tree_from_file
*/

#include "giantman.h"
#include "my_number.h"

void get_leaf_path(file_t *file_data, tree_t *tree_data)
{
    int index_leaf = 0;
    for (int i = 0; i < (file_data->size_file - 3); ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            tree_data->nb_bit_to_skip = my_get_nb(&file_data->content[i + 2]);
            return;
        }
        tree_data->leaf_list[index_leaf][0] = file_data->content[i];
        for (int j = 1; i < file_data->size_file &&
            file_data->content[i] != '|'; ++i) {
            tree_data->leaf_list[index_leaf][j] = file_data->content[i];
            ++ j;
        }
        ++ index_leaf;
    }
}

void recover_tree_from_file(file_t *file_data, tree_t *tree_data)
{
    int index_leaf = 0;
    for (int i = 0; i < (file_data->size_file - 3); ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            tree_data->nb_bit_to_skip = my_get_nb(&file_data->content[i + 2]);
            return;
        }
        tree_data->leaf_list[index_leaf][0] = file_data->content[i];
        for (int j = 1; i < file_data->size_file &&
            file_data->content[i] != '|'; ++i) {
            tree_data->leaf_list[index_leaf][j] = file_data->content[i];
            ++ j;
        }
        ++ index_leaf;
    }
}
