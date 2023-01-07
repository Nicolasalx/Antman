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
    file_data->size_file = my_strlen(file_data->content);
    int count_underscore = 0;
    int count_zero_one_verticalbar = 0;
    if (file_data->size_file < 10)
        return ALGO_SMALL_FILE;
    for (int i = 0; i < (file_data->size_file - 1) &&
        count_underscore == 0; ++i) {
        if (file_data->content[i] == '_' && file_data->content[i + 1] == '_') {
            count_underscore = 1;
        }
        if (file_data->content[i] == '0' || file_data->content[i] == '1') {
            ++ count_zero_one_verticalbar;
        }
    }
    if (count_underscore == 1 && count_zero_one_verticalbar >= 4 &&
        (file_data->content[1] == '0' || file_data->content[1] == '1'))
        return ALGO_BIG_FILE;
    return ALGO_SMALL_FILE;
}

void analyze_file_content(char *filepath, file_t *file_data)
{
    int file = open_file(filepath);
    if (file == -1) {
        print_error(error_manager(INVALID_FILE));
        return;
    }
    file_data->content = my_file_to_str(filepath, file);
    file_data->encoding_algo = determine_algo(file_data);
}
