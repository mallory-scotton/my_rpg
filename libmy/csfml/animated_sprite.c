/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** sfAnimatedSprite
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Global instance of the `global_ansprite_t` structure.
///
/// This variable is an instance of the `global_ansprite_t` structure and is
/// intended to be used as a global accessor to `ansprite_t` functionality.
///
///////////////////////////////////////////////////////////////////////////////
global_ansprite_t Sprite = {
    &ansprite_create,
    &ansprite_destroy,
    &ansprite_move,
    &ansprite_rotate,
    &ansprite_scale,
    {
        &ansprite_get_position,
        &ansprite_get_rotation,
        &ansprite_get_scale,
        &ansprite_get_origin,
        &ansprite_get_animations,
        &ansprite_get_current_animation
    },
    {
        &ansprite_set_position,
        &ansprite_set_rotation,
        &ansprite_set_scale,
        &ansprite_set_origin,
        &ansprite_set_current_animation
    },
    &ansprite_draw
};
