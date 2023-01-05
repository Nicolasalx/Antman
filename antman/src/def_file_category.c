/*
** EPITECH PROJECT, 2023
** def_file_category
** File description:
** def_file_category
*/

#include "antman.h"
#include "my_string.h"

int total_occur_char(file_info_t *file_data)
{
    int count = 0;
    for (int x = 0; x < file_data->nb_diff_char; ++x) {
        count += file_data->occur_char[x];
    }
    return count;
}

int def_file_category(file_info_t *file_data)
{
    int sum_occur = total_occur_char(file_data) / file_data->nb_diff_char;
    if (sum_occur > CAP_BIG_FILE) {
        return BIG_FILE;
    }
    return SMALL_FILE;
}
