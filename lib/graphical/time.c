/*
** EPITECH PROJECT, 2022
** time
** File description:
** time
*/

#include "my_graphical.h"

int get_time(sfClock *clock)
{
    sfTime time;
    time = sfClock_getElapsedTime(clock);
    return time.microseconds / 1000;
}
