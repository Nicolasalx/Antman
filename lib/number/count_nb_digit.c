/*
** EPITECH PROJECT, 2022
** count_nb_digit
** File description:
** count_nb_digit (take sign in account, ex : -55 -> 3)
*/

int count_nb_digit(int nb)
{
    int count = 0;
    if (nb == 0) {
        return 1;
    }
    if (nb < 0) {
        if (nb == -2147483648) {
            nb += 1;
        }
        nb = -nb;
        ++ count;
    }
    while (nb > 0) {
        nb /= 10;
        ++ count;
    }
    return count;
}
