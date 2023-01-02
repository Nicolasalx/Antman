/*
** EPITECH PROJECT, 2022
** sprite
** File description:
** sprite
*/

#include "my_graphical.h"

sprite_t create_sprite(sprite_t sprite_dt)
{
    sprite_dt.texture = sfTexture_createFromFile(sprite_dt.path, NULL);
    if (sprite_dt.texture == 0) {
        return sprite_dt;
    }
    sprite_dt.rect = get_texture_size(sprite_dt.texture);

    sprite_dt.sprite = sfSprite_create();
    sfSprite_setTexture(sprite_dt.sprite, sprite_dt.texture, sfTrue);
    sfSprite_setPosition(sprite_dt.sprite, sprite_dt.pos);
    sfSprite_setTextureRect(sprite_dt.sprite, sprite_dt.rect);
    sfSprite_setScale(sprite_dt.sprite, sprite_dt.scale);
    return sprite_dt;
}

void display_sprite(sprite_t sprite_dt, sfRenderWindow* window)
{
    sfSprite_setPosition(sprite_dt.sprite, sprite_dt.pos);
    sfSprite_setTextureRect(sprite_dt.sprite, sprite_dt.rect);
    sfSprite_setScale(sprite_dt.sprite, sprite_dt.scale);
    sfRenderWindow_drawSprite(window, sprite_dt.sprite, NULL);
}

void destroy_sprite(sprite_t sprite_dt)
{
    sfTexture_destroy(sprite_dt.texture);
    sfSprite_destroy(sprite_dt.sprite);
}
