/*
** EPITECH PROJECT, 2023
** free_all_data
** File description:
** free_all_data
*/

#include "antman.h"
#include "my_malloc.h"

void free_all_data(file_info_t *file_data)
{
    free_str(file_data->content);
    free_str(file_data->character);
    free_array(file_data->occur_char);
}
