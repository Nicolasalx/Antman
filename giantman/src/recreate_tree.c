/*
** EPITECH PROJECT, 2023
** recreate_tree
** File description:
** recreate_tree
*/

#include "giantman.h"
#include <stdlib.h>

node_t *create_and_fill_leaf(char c)
{
    node_t *new_leaf = malloc(sizeof(node_t));
    new_leaf->left = NULL;
    new_leaf->right = NULL;
    new_leaf->character = c;
    return new_leaf;
}

void link_leaf_left(node_t **leaf, node_t *parent)
{
    if (parent->left == NULL) {
        parent->left = *leaf;
    } else {
        free(*leaf);
        *leaf = parent->left;
    }
}

void link_leaf_right(node_t **leaf, node_t *parent)
{
    if (parent->right == NULL) {
        parent->right = *leaf;
    } else {
        free(*leaf);
        *leaf = parent->right;
    }
}

void recreate_all_leaf(tree_t *tree, int i_leaf, int j_bit, node_t *parent)
{
    if (tree->leaf_list[i_leaf][j_bit] == '\0')
        return;
    node_t *new_leaf = create_and_fill_leaf(tree->leaf_list[i_leaf][0]);

    if (tree->leaf_list[i_leaf][j_bit] == '0') {
        link_leaf_left(&new_leaf, parent);
    } else {
        link_leaf_right(&new_leaf, parent);
    }
    recreate_all_leaf(tree, i_leaf, j_bit + 1, new_leaf);
}

void recreate_tree(tree_t *tree)
{
    tree->head = create_node();
    tree->head->left = NULL;
    tree->head->right = NULL;

    for (int i = 0; tree->leaf_list[i] != NULL; ++i) {
        recreate_all_leaf(tree, i, 1, tree->head);
    }
}
