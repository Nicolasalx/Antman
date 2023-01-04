/*
** EPITECH PROJECT, 2023
** fill_list
** File description:
** fill_list
*/

#include "antman.h"

node_t *create_tree(file_info_t *file_data)
{
    node_t *head_leaf_list = create_all_leaf(file_data);

    return head_leaf_list;
}
