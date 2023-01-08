/*
** EPITECH PROJECT, 2023
** free_all_data
** File description:
** free_all_data
*/

#include "giantman.h"
#include "my_malloc.h"

void free_all_data(file_t *file_data)
{
    free_str(file_data->content);
}
