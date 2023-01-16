/*
** EPITECH PROJECT, 2023
** analyze_file_content
** File description:
** analyze_file_content
*/

#include "giantman.h"
#include "my_string.h"
#include "my_file.h"

int determine_algo(file_t *file_data)
{
    int count_underscore = 0;
    int count_verticalbar = 0;
    int count_digit = 0;
    if (file_data->size_file < 9)
        return ALGO_SMALL_FILE;
    for (int i = 0; i < (file_data->size_file - 1) &&
        count_underscore == 0; ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            count_underscore = 1;
        }
        (file_data->content[i] == '|') ? ++ count_verticalbar : ++ count_digit;
    }
    if (count_underscore == 1 && count_verticalbar >= 2 && count_digit >= 2)
        return ALGO_BIG_FILE;
    return ALGO_SMALL_FILE;
}

void analyze_file_content(char *filepath, file_t *file_data)
{
    int file = open_file(filepath);
    if (file == -1 || is_a_dir(filepath) == 1 ||
        my_filelen(filepath) > FILE_SIZE_LIMIT) {
        print_error(error_manager(INVALID_FILE));
        return;
    }
    file_data->size_file = my_filelen(filepath);
    file_data->content = my_file_to_str(filepath, file);
    if (error_manager(0) != 0) {
        return;
    }
    file_data->encoding_algo = determine_algo(file_data);
}
