/*
** EPITECH PROJECT, 2023
** get_path_leaf
** File description:
** get_path_leaf
*/

#include "antman.h"
#include "my_malloc.h"
#include <stdlib.h>

int is_left_or_right(node_t *node)
{
    if (node->parent->left == node) {
        return 0;
    } else {
        return 1;
    }
}

int *count_size_path_leaf(file_info_t *file_data, tree_data_t *tree)
{
    int *size_path = malloc_array(file_data->nb_diff_char);
    int count = 0;
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        node_t *current = tree->leaf_list[i];
        while (current->parent != NULL) {
            ++ count;
            current = current->parent;
        }
        size_path[i] = (count + 1);
    }
    return size_path;
}

char **get_all_leaf_path(file_info_t *file_data, tree_data_t *tree)
{
    int *size_path = count_size_path_leaf(file_data, tree);
    char **leaf_path = malloc_adv_board(file_data->nb_diff_char, size_path);
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        node_t *current = tree->leaf_list[i];
        int index = 0;
        if (current->type == LEAF) {
            leaf_path[i][index] = current->character;
            ++ index;
        }
        while (current->parent != NULL) {
            leaf_path[i][index] = is_left_or_right(current) == 0 ? '0' : '1';
            current = current->parent;
            ++ index;
        }
    }
    free_array(size_path);
    return leaf_path;
}
