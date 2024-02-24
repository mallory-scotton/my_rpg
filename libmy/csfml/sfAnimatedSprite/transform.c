/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** transform
*/

#include "rpg.h"

void ansprite_move(ansprite_t *s, vec2f offset)
{
    sfSprite_move(s->sprite, offset);
}

void ansprite_rotate(ansprite_t *s, float angle)
{
    sfSprite_rotate(s->sprite, angle);
}

void ansprite_scale(ansprite_t *s, vec2f factors)
{
    sfSprite_scale(s->sprite, factors);
}
