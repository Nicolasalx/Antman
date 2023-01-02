/*
** EPITECH PROJECT, 2022
** max_value
** File description:
** max_value
*/

int max_value(int *array, int size_array)
{
    int max_value = 0;
    if (size_array > 0) {
        max_value = array[0];
    }
    for (int i = 0; i < size_array; ++i) {
        if (array[i] > max_value) {
            max_value = array[i];
        }
    }
    return max_value;
}
