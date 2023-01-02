/*
** EPITECH PROJECT, 2022
** music
** File description:
** music
*/

#include "my_graphical.h"

void create_music(music_t *music_dt)
{
    (*music_dt).music = sfMusic_createFromFile((*music_dt).path);
    if ((*music_dt).music == 0) {
        return;
    }
}

void play_music(music_t *music_dt)
{
    sfMusic_play((*music_dt).music);
}

void destroy_music(music_t music_dt)
{
    sfMusic_destroy(music_dt.music);
}
