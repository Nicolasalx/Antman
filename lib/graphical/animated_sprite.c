/*
** EPITECH PROJECT, 2022
** animated_sprite
** File description:
** animated_sprite
*/

#include "my_graphical.h"

anim_sprite_t create_anim_sprite(anim_sprite_t anim_sprite)
{
    anim_sprite.texture = sfTexture_createFromFile(anim_sprite.path, NULL);
    if (anim_sprite.texture == 0) {
        return anim_sprite;
    }

    anim_sprite.rect = get_texture_size(anim_sprite.texture);
    anim_sprite.rect.width =
        sfTexture_getSize(anim_sprite.texture).x / anim_sprite.nb_frame;

    anim_sprite.sprite = sfSprite_create();
    sfSprite_setTexture(anim_sprite.sprite, anim_sprite.texture, sfTrue);
    sfSprite_setPosition(anim_sprite.sprite, anim_sprite.pos);
    sfSprite_setTextureRect(anim_sprite.sprite, anim_sprite.rect);
    sfSprite_setScale(anim_sprite.sprite, anim_sprite.scale);
    anim_sprite.clock = sfClock_create();
    return anim_sprite;
}

void play_animation(anim_sprite_t *anim_sprite)
{
    if (get_time((*anim_sprite).clock) >= 1000 / (*anim_sprite).frame_rate) {
        sfClock_restart((*anim_sprite).clock);
        (*anim_sprite).rect.left += (*anim_sprite).rect.width;
        if ((*anim_sprite).rect.left >=
            (*anim_sprite).rect.height * (*anim_sprite).nb_frame) {
            (*anim_sprite).rect.left = 0;
        }
    }
}

void display_anim_sprite(anim_sprite_t anim_sprite, sfRenderWindow* window)
{
    sfSprite_setPosition(anim_sprite.sprite, anim_sprite.pos);
    sfSprite_setTextureRect(anim_sprite.sprite, anim_sprite.rect);
    sfSprite_setScale(anim_sprite.sprite, anim_sprite.scale);
    sfRenderWindow_drawSprite(window, anim_sprite.sprite, NULL);
}

void destroy_anim_sprite(anim_sprite_t anim_sprite)
{
    sfTexture_destroy(anim_sprite.texture);
    sfSprite_destroy(anim_sprite.sprite);
    sfClock_destroy(anim_sprite.clock);
}
