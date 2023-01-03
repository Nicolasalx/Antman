/*
** EPITECH PROJECT, 2023
** func_linked_list.c
** File description:
** func_linked_list
*/

#include <stdlib.h>
#include "antman.h"

list_t *ini_list(void)
{
    list_t *list = malloc(sizeof(*list));
    node_t *new_node = malloc(sizeof(*new_node));

    if (list == NULL || new_node == NULL) {
        exit(84);
    }
    new_node->value = 0;
    new_node->next = NULL;
    list->head = new_node;
    return list;
}

void insert(list_t *list, int new_value)
{
    node_t *new_node = malloc(sizeof(*new_node));
    if (list == NULL || new_node == NULL) {
        exit(84);
    }
    new_node->value = new_value;
    new_node->next = list->head;
    list->head = new_node;
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
        exit(84);
    }

    node_t *current = list->head;

    while (current != NULL)
    {
        printf("%d -> ", current->value);
        current = current->next;
    }
    printf("NULL\n");
}

void fill_list(int array[], int size_array, list_t *list)
{
    char str[3];
    for (int x = 0; x < size_array; ++x) {
        sprintf(str, "%d", array[x]);
        insertion(list, atoi(str));
    }
}
