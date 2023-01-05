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

node_t *ini_list(void)
{
    node_t *head = malloc(sizeof(node_t *));
    head = NULL;
    return head;
}

node_t *create_node(void)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->next = NULL;
    return new_node;
}

void append_node(node_t **head, char character, int value, int type)
{
    node_t *new_node = malloc(sizeof(node_t));

    new_node->character = character;
    new_node->value = value;
    new_node->type = type;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
        return;
    }
    node_t *current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
}

void insert_node(node_t **head, node_t *node, int index)
{
    node_t *current = *head;
    if (*head == NULL) {
        *head = node;
        return;
    }
    if (index == 0) {
        node->next = *head;
        *head = node;
    } else {
        for (int i = 0; i < (index - 1) && current->next != NULL; ++i) {
            current = current->next;
        }
        node->next = current->next;
        current->next = node;
    }
}

node_t *remove_node(node_t **head, node_t *node)
{
    node_t *current = *head;
    if (*head == NULL) {
        return node;
    }
    if (*head == node) {
        *head = node->next;
    } else {
        while (current->next != node && current->next != NULL) {
            current = current->next;
        }
        current->next = node->next;
    }
    node->next = NULL;
    return node;
}

/*void delete_list(node_t **head)
{
    if (head == NULL) {
        return;
    }
    if (head != NULL) {
        node_t *aSupprimer = head;
        head = head;
        free(aSupprimer);
    }
}*/

/*void display_list(node_t **head)
{
    if (head == NULL) {
        return;
    }

    node_t *current = head;

    while (current != NULL)
    {
        my_putstr(my_nb_to_str(current->value));
        my_putstr(" -> ");
        current = current->next;
    }
    my_putstr("NULL\n");
}*/
