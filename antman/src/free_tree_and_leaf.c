/*
** EPITECH PROJECT, 2023
** free_tree
** File description:
** free_tree
*/

#include "antman.h"
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

void free_tree_and_leaf(tree_data_t *tree, file_info_t *file_data,
    char **leaf_path, char *new_file_rep)
{
    free(tree->leaf_list);
    free_str(new_file_rep);
    free_board(leaf_path, file_data->nb_diff_char);
    free_tree(tree->head_tree);
}
