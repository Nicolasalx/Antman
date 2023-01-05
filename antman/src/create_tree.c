/*
** EPITECH PROJECT, 2023
** create_tree
** File description:
** create_tree
*/

#include "antman.h"
#include <stdlib.h>

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

int count_nb_children(node_t *branch)
{
    int count = 0;
    if (branch->left != NULL) {
        ++ count;
    }
    if (branch->right != NULL) {
        ++ count;
    }
    return count;
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

node_t *create_tree(file_info_t *file_data)
{
    node_t *head_tree = create_all_leaf(file_data);

    while (head_tree != NULL && head_tree->next != NULL) {
        node_t *lower_1 = head_tree;
        node_t *lower_2 = head_tree->next;
        node_t *new_branch = create_branch(lower_1, lower_2);
        remove_node(&head_tree, lower_1);
        remove_node(&head_tree, lower_2);
        insert_node(&head_tree, new_branch,
        find_index_between(&head_tree, new_branch->value));
    }

    return head_tree;
}
