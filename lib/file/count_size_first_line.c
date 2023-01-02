/*
** EPITECH PROJECT, 2022
** count_size_first_line
** File description:
** count_size_first_line
*/

int count_size_first_line(char *str)
{
    int i = 0;
    while (str[i] != '\n' && str[i] != '\0') {
        ++i;
    }
    return i;
}
