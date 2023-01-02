/*
** EPITECH PROJECT, 2022
** my_graphical
** File description:
** my_graphical
*/

#ifndef MY_GRAPHICAL
    #define MY_GRAPHICAL

    #include <SFML/Audio.h>
    #include <SFML/Graphics.h>
    #include <SFML/System.h>

    #include "my_error.h"

typedef struct sprite_data_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    char *path;
} sprite_t;

typedef struct animated_sprite_data_t {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfIntRect rect;
    sfVector2f scale;
    sfClock *clock;
    int nb_frame;
    int frame_rate;
    char *path;
} anim_sprite_t;

typedef struct music_data_t {
    sfMusic* music;
    char *path;
} music_t;

int get_time(sfClock *clock);

sprite_t create_sprite(sprite_t sprite_dt);
void display_sprite(sprite_t sprite_dt, sfRenderWindow* window);
void destroy_sprite(sprite_t sprite_dt);

anim_sprite_t create_anim_sprite(anim_sprite_t anim_sprite_dt);
void play_animation(anim_sprite_t *anim_sprite_dt);
void display_anim_sprite(anim_sprite_t anim_sprite_dt, sfRenderWindow* window);
void destroy_anim_sprite(anim_sprite_t anim_sprite_dt);

void create_music(music_t *music);
void play_music(music_t *music);
void destroy_music(music_t music);

int mouse_is_over_sprite(sprite_t sprite, sfVector2i mouse);
int mouse_is_over_anim_sprite(anim_sprite_t anim_sprite, sfVector2i mouse);

int rand_int(int min, int max);

sfIntRect get_texture_size(sfTexture *texture);

#endif /* !MY_GRAPHICAL */
