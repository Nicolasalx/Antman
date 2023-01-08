/*
** EPITECH PROJECT, 2023
** B-CPE-110-PAR-1-1-antman-thibaud.cathala
** File description:
** free_tree_data
*/

#include "giantman.h"
#include "my_malloc.h"
#include <stdlib.h>

void free_tree(node_t *current)
{
    if (current == NULL) {
        return;
    }
    free_tree(current->left);
    free_tree(current->right);
    free(current);
}

void free_tree_data(tree_t *tree_data)
{
    free_board(tree_data->leaf_list, tree_data->nb_leaf);
    free_tree(tree_data->head);
}
