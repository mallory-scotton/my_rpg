/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** set
*/

#include "rpg.h"

void ansprite_set_position(ansprite_t *s, vec2f pos)
{
    sfSprite_setPosition(s->sprite, pos);
}

void ansprite_set_rotation(ansprite_t *s, float rot)
{
    sfSprite_setRotation(s->sprite, rot);
}

void ansprite_set_scale(ansprite_t *s, vec2f scale)
{
    sfSprite_setScale(s->sprite, scale);
}

void ansprite_set_origin(ansprite_t *s, vec2f origin)
{
    sfSprite_setOrigin(s->sprite, origin);
}
