/*
** EPITECH PROJECT, 2023
** func_linked_list
** File description:
** func_linked_list
*/

#include "giantman.h"
#include <stdlib.h>

node_t *create_node(void)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    return new_node;
}
