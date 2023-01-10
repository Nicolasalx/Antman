/*
** EPITECH PROJECT, 2023
** recreate_tree
** File description:
** recreate_tree
*/

#include "giantman.h"
#include <stdlib.h>

void create_all_leaf(file_t *file_data, tree_t *tree)
{
    tree->head = ini_list();
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        printf("%c -> %d\n", file_data->character[i], file_data->occur_char[i]);
        append_node(&tree->head, file_data->character[i],
        file_data->occur_char[i], LEAF);
    }
}

int find_index_between(node_t **head, int value)
{
    if (*head == NULL) {
        return 0;
    }

    int i = 0;
    node_t *current = *head;
    for (; current->value < value; ++i) {
        if (current->next == NULL) {
            return (i + 1);
        }
        current = current->next;
    }
    return i;
}

node_t *create_branch(node_t *left_node, node_t *right_node)
{
    node_t *new_branch = malloc(sizeof(node_t));
    new_branch->type = BRANCH;
    new_branch->value = left_node->value + right_node->value;
    new_branch->left = left_node;
    new_branch->right = right_node;
    new_branch->next = NULL;
    return new_branch;
}

void recreate_tree(file_t *file_data, tree_t *tree)
{
    create_all_leaf(file_data, tree);

    while (tree->head != NULL && tree->head->next != NULL) {
        node_t *lower_1 = tree->head;
        node_t *lower_2 = tree->head->next;
        node_t *new_branch = create_branch(lower_1, lower_2);
        remove_node(&tree->head, lower_1);
        remove_node(&tree->head, lower_2);
        insert_node(&tree->head, new_branch,
        find_index_between(&tree->head, new_branch->value));
    }
}
