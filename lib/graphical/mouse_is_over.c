/*
** EPITECH PROJECT, 2022
** mouse_is_over
** File description:
** mouse_is_over
*/

#include "my_graphical.h"

int mouse_is_over_sprite(sprite_t sprite_dt, sfVector2i mouse)
{
    if (sprite_dt.pos.x < mouse.x &&
        mouse.x < sfSprite_getGlobalBounds(sprite_dt.sprite).width +
        sprite_dt.pos.x && sprite_dt.pos.y < mouse.y &&
        mouse.y < sfSprite_getGlobalBounds(sprite_dt.sprite).height +
        sprite_dt.pos.y) {
            return 1;
    } else {
        return 0;
    }
}

int mouse_is_over_anim_sprite(anim_sprite_t anim_sprite, sfVector2i mouse)
{
    if (anim_sprite.pos.x < mouse.x &&
        mouse.x < sfSprite_getGlobalBounds(anim_sprite.sprite).width +
        anim_sprite.pos.x &&
        anim_sprite.pos.y < mouse.y &&
        mouse.y < sfSprite_getGlobalBounds(anim_sprite.sprite).height +
        anim_sprite.pos.y) {
            return 1;
    } else {
        return 0;
    }
}
