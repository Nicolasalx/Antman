/*
** EPITECH PROJECT, 2023
** func_linked_list
** File description:
** func_linked_list
*/

#include <stdlib.h>
#include "antman.h"
#include "my_string.h"
#include "my_number.h"

list_t *ini_list(void)
{
    list_t *list = malloc(sizeof(list_t));
    list->head = NULL;
    return list;
}

void append_list(list_t *list, char character, int value)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->character = character;
    new_node->value = value;
    new_node->next = NULL;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }
    node_t *current = list->head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void delete_list(list_t *list)
{
    if (list == NULL) {
        exit(84);
    }
    if (list->head != NULL) {
        node_t *aSupprimer = list->head;
        list->head = list->head->next;
        free(aSupprimer);
    }
}

void display_list(list_t *list)
{
    if (list == NULL) {
        return;
    }

    node_t *current = list->head;

    while (current != NULL)
    {
        my_putstr(my_nb_to_str(current->value));
        my_putstr(" -> ");
        current = current->next;
    }
    my_putstr("NULL\n");
}
