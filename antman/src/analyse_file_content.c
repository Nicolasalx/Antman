/*
** EPITECH PROJECT, 2023
** analyse_file_content
** File description:
** analyse_file_content
*/

#include "antman.h"
#include "my_file.h"
#include "my_string.h"
#include "my_malloc.h"

void fill_file_data(char *buff, file_info_t *file_data)
{
    int j = 0;
    file_data->character = malloc_str(ASCII_RANGE);
    file_data->occur_char = malloc_array(ASCII_RANGE);
    ini_str_to_zero(file_data->character, ASCII_RANGE);
    for (int i = 0; buff[i] != '\0' && (j + 1) < ASCII_RANGE; ++i) {
        if (is_in_str(buff[i], file_data->character) == 0) {
            file_data->character[j] = buff[i];
            file_data->occur_char[j] = count_occur(buff, buff[i]);
            ++ j;
        }
    }
    file_data->nb_diff_char = j;
    file_data->content = buff;
}

void analyse_file_content(char *filepath, file_info_t *file_data)
{
    int file = open_file(filepath);
    if (file == -1 || is_a_dir(filepath) == 1 ||
        my_filelen(filepath) > FILE_SIZE_LIMIT) {
        print_error(error_manager(INVALID_FILE));
        return;
    }
    char *buff = my_file_to_str(filepath, file);
    if (error_manager(0) != 0) {
        return;
    }
    fill_file_data(buff, file_data);
}
