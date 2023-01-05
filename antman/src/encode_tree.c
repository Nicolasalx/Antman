/*
** EPITECH PROJECT, 2023
** encode_tree
** File description:
** encode_tree
*/

#include "antman.h"
#include "my_string.h"
#include <stdlib.h>

int is_left_or_right(node_t *node) {
    if (node->parent->left == node) {
        return 0;
    } else {
        return 1;
    }
}

void encode_tree(node_t **leaf_list, file_info_t *file_data)
{
    for (int i = 0; i < file_data->nb_diff_char; ++i) {
        node_t *current = leaf_list[i];
        if (current->type == LEAF) {
            write(1, &current->character, 1);
        }
        while (current->parent != NULL) {
            is_left_or_right(current) == 0 ? my_putstr("0") : my_putstr("1");
            current = current->parent;
        }
        my_putstr("|");
    }
    my_putstr("\n");
}
