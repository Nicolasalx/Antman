/*
** EPITECH PROJECT, 2022
** texture
** File description:
** texture
*/

#include "my_graphical.h"

sfIntRect get_texture_size(sfTexture *texture)
{
    sfIntRect rect;
    rect.left = 0;
    rect.top = 0;
    rect.width = sfTexture_getSize(texture).x;
    rect.height = sfTexture_getSize(texture).y;
    return rect;
}
