/*
** EPITECH PROJECT, 2023
** func_linked_head
** File description:
** func_linked_head
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

void insert_node(node_t **head, int value, int type, int index)
{
    node_t *new_node = malloc(sizeof(node_t));
    new_node->value = value;
    new_node->type = type;
    new_node->next = NULL;

    node_t *current = *head;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    if (index == 0) {
        new_node->next = *head;
        *head = new_node;
    } else {
        for (int i = 0; i < (index - 1) && current->next != NULL; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
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
