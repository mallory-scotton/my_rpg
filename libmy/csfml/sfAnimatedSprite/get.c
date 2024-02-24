/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** get
*/

#include "rpg.h"

vec2f ansprite_get_position(const ansprite_t *s)
{
    return (sfSprite_getPosition(s->sprite));
}

float ansprite_get_rotation(const ansprite_t *s)
{
    return (sfSprite_getRotation(s->sprite));
}

vec2f ansprite_get_scale(const ansprite_t *s)
{
    return (sfSprite_getScale(s->sprite));
}

vec2f ansprite_get_origin(const ansprite_t *s)
{
    return (sfSprite_getOrigin(s->sprite));
}
