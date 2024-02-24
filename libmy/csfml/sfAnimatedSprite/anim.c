/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** anim
*/

///////////////////////////////////////////////////////////////////////////////
// Header
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the current animation of an `ansprite_t` by name.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param name Name of the animation to set as the current animation.
///
///////////////////////////////////////////////////////////////////////////////
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

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the array of animations associated with an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Pointer to the array of animations.
///
///////////////////////////////////////////////////////////////////////////////
animation_t **ansprite_get_animations(const ansprite_t *s)
{
    return (s->animations);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the currently playing animation of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Pointer to the currently playing animation.
///
///////////////////////////////////////////////////////////////////////////////
animation_t *ansprite_get_current_animation(const ansprite_t *s)
{
    return (s->animations[s->currentAnimation]);
}
