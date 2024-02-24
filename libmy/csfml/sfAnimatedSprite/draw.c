/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** draw
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_draw(ansprite_t *s)
{
    animation_t *a = s->animations[s->currentAnimation];
    ulong ems = (Time->currentTime) - (s->start);
    recti mask = {0, 0, a->frameSize.x, a->frameSize.y};

    s->currentFrame = (uint)(ems / s->frameRate) % a->maxFrame;
    mask.left = (s->currentFrame % a->gridSize.x) * a->frameSize.x;
    mask.top = (s->currentFrame / a->gridSize.x) * a->frameSize.y;
    sfSprite_setTextureRect(s->sprite, mask);
    sfRenderWindow_drawSprite(Win->self, s->sprite, NULL);
}
