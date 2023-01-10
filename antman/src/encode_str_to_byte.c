/*
** EPITECH PROJECT, 2023
** encode_str_to_byte
** File description:
** encode_str_to_byte
*/

#include "antman.h"
#include "my_string.h"
#include "my_number.h"
#include <stdlib.h>
#include <unistd.h>

void set_all_byte_to_zero(unsigned char *str, int size_str)
{
    for (int i = 0; i < size_str; ++i) {
        set_all_bit_to_zero(&str[i]);
    }
}

void fill_str_with_bit(char *str, int size_str, unsigned char *encoded_str)
{
//    write(1, "\n\n", 2);
//    write(1, str, size_str);
//    write(1, "\n\n", 2);
    int index_bit = 0;
    int index_byte = 0;
    for (int i = 0; i < size_str; ++i) {
        if (str[i] == '0') {
            set_bit_to_zero(&encoded_str[index_byte], index_bit);
        } else {
            set_bit_to_one(&encoded_str[index_byte], index_bit);
        }
        ++ index_bit;
        if (index_bit > 7) {
            ++ index_byte;
            index_bit = 0;
        }
    }
}

void encode_str_to_byte(char *str)
{
    int size_str = my_strlen(str);
    int size_encoded_str = size_str / 8;
    int nb_extra_bit = size_str - (size_encoded_str * 8);
    my_putstr(my_nb_to_str(nb_extra_bit));
    unsigned char *encoded_str;
    if (nb_extra_bit != 0) {
        ++ size_encoded_str;
    }
    encoded_str = malloc(sizeof(unsigned char) * (size_encoded_str));
    set_all_byte_to_zero(encoded_str, size_encoded_str);
    fill_str_with_bit(str, size_str, encoded_str);
    write(1, encoded_str, size_encoded_str);
    free(encoded_str);
}
