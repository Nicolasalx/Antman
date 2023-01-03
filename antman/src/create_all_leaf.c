/*
** EPITECH PROJECT, 2023
** create_all_leaf
** File description:
** create_all_leaf
*/

#include "antman.h"
#include <stdlib.h>

node_t *create_leaf(void)
{
    node_t *new_leaf = malloc(sizeof(node_t));
    new_leaf->left = NULL;
    new_leaf->right = NULL;
    new_leaf->parent = NULL;
    new_leaf->type = LEAF;
    return new_leaf;
}

node_t **create_all_leaf(file_info_t *file_data)
{
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        create_leaf();
        file_data->character[i];
        file_data->occur_char[i];
    }
    return leaf_list;
}
