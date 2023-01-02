/*
** EPITECH PROJECT, 2022
** min_value
** File description:
** min_value
*/

int min_value(int *array, int size_array)
{
    int min_value = 0;
    if (size_array > 0) {
        min_value = array[0];
    }
    for (int i = 0; i < size_array; ++i) {
        if (array[i] < min_value) {
            min_value = array[i];
        }
    }
    return min_value;
}
