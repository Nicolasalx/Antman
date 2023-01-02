/*
** EPITECH PROJECT, 2022
** my_strcmp
** File description:
** my_strcmp
*/

#include "my_string.h"

int smallest_value(int val_1, int val_2)
{
    if (val_1 > val_2) {
        return val_2;
    } else {
        return val_1;
    }
}

int my_strcmp(char const *str1, char const *str2)
{
    int size_str1 = my_strlen(str1);
    int size_str2 = my_strlen(str2);
    int size_str = smallest_value(my_strlen(str1), my_strlen(str2));
    for (int i = 0; i < size_str; ++i) {
        if (str1[i] > str2[i]) {
            return 1;
        } if (str1[i] < str2[i]) {
            return -1;
        }
    }

    if (size_str1 == size_str2) {
        return 0;
    } if (size_str1 > size_str2) {
        return 1;
    } if (size_str1 < size_str2) {
        return -1;
    }
    return 84;
}
