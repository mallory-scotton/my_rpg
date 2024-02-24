/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** anim
*/

#include "rpg.h"

void ansprite_set_current_animation(ansprite_t *s, cstring name)
{
    for (uint i = 0; i < s->animationCount; i++) {
        if (!CMP(s->animations[i]->name, name))
            continue;
        sfSprite_setTexture(s->sprite, s->animations[i]->texture, true);
        s->currentAnimation = i;
        s->start = Time->currentTime;
        s->currentFrame = 0;
        break;
    }
}

animation_t **ansprite_get_animations(const ansprite_t *s)
{
    return (s->animations);
}

animation_t *ansprite_get_current_animation(const ansprite_t *s)
{
    return (s->animations[s->currentAnimation]);
}
