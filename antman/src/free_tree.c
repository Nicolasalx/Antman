/*
** EPITECH PROJECT, 2023
** free_tree
** File description:
** free_tree
*/

#include "antman.h"
#include "my_string.h"
#include <stdlib.h>

void free_tree(tree_data_t *tree)
{
    if (tree->head_tree == NULL) {
        return;
    }
    free(tree->leaf_list);
}
