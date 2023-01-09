/*
** EPITECH PROJECT, 2023
** recover_tree_from_file
** File description:
** recover_tree_from_file
*/

#include "giantman.h"
#include "my_number.h"
#include "my_malloc.h"
#include <stdio.h>

int count_nb_leaf(file_t *file_data)
{
    int nb_leaf = 0;
    for (int i = 0; i < (file_data->size_file - 3); ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            return nb_leaf;
        }
        ++ nb_leaf;
        for (; i < file_data->size_file &&
            file_data->content[i] != '|'; ++i) {
        }
    }
    return nb_leaf;
}

void count_size_leaf_path(file_t *file_data, tree_t *tree_data)
{
    tree_data->nb_leaf = count_nb_leaf(file_data);
    int *size_leaf = malloc_array(tree_data->nb_leaf);
    int index_leaf = 0;
    for (int i = 0; i < (file_data->size_file - 3); ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            break;
        }
        ++ size_leaf[index_leaf];
        for (; i < file_data->size_file &&
            file_data->content[i] != '|'; ++i) {
            ++ size_leaf[index_leaf];
        }
        ++ index_leaf;
    }
    tree_data->leaf_list = malloc_adv_board(tree_data->nb_leaf, size_leaf);
    free_array(size_leaf);
}

void recover_tree_from_file(file_t *file_data, tree_t *tree_data)
{
    count_size_leaf_path(file_data, tree_data);
    int index_leaf = 0;
    for (int i = 0; i < (file_data->size_file - 3); ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            tree_data->nb_bit_to_skip = my_get_nb(&file_data->content[i + 2]);
            tree_data->begining_encoded_file = i + 3;
            return;
        }
        tree_data->leaf_list[index_leaf][0] = file_data->content[i];
        ++ i;
        for (int j = 1; i < file_data->size_file &&
            file_data->content[i] != '|'; ++i) {
            tree_data->leaf_list[index_leaf][j] = file_data->content[i];
            ++ j;
        }
        ++ index_leaf;
    }
}
