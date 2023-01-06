/*
** EPITECH PROJECT, 2023
** free_tree
** File description:
** free_tree
*/

#include "antman.h"
#include "my_malloc.h"
#include <stdlib.h>

void free_tree_and_leaf(tree_data_t *tree, file_info_t *file_data,
    char **leaf_path, char *new_file_rep)
{
    if (tree->head_tree == NULL) {
        return;
    }
    free(tree->leaf_list);
    free_str(new_file_rep);
    free_board(leaf_path, file_data->nb_diff_char);
}
