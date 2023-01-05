/*
** EPITECH PROJECT, 2023
** create_all_leaf
** File description:
** create_all_leaf
*/

#include "antman.h"
#include <stdlib.h>

void create_leaf_list(file_info_t *file_data, tree_data_t *tree)
{
    tree->leaf_list = malloc(sizeof(node_t *) * file_data->nb_diff_char);
    node_t *current = tree->head_tree;
    for (int i = (file_data->nb_diff_char - 1); current != NULL; --i) {
        tree->leaf_list[i] = current;
        current = current->next;
    }
}

void create_all_leaf(file_info_t *file_data, tree_data_t *tree)
{
    tree->head_tree = ini_list();
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        append_node(&tree->head_tree, file_data->character[i],
        file_data->occur_char[i], LEAF);
    }
    create_leaf_list(file_data, tree);
}
