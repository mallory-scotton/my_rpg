/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** set
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the position of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param pos New position of the `ansprite_t`.
///
/// This function sets the position of the `ansprite_t` to the specified
/// coordinates.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_position(ansprite_t *s, vec2f pos)
{
    sfSprite_setPosition(s->sprite, pos);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the rotation of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param rot New rotation angle in degrees.
///
/// This function sets the rotation angle of the `ansprite_t` to the specified
/// angle in degrees.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_rotation(ansprite_t *s, float rot)
{
    sfSprite_setRotation(s->sprite, rot);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the scale of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param scale New scale factors for the `ansprite_t`.
///
/// This function sets the scale factors of the `ansprite_t` to the specified
/// values.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_scale(ansprite_t *s, vec2f scale)
{
    sfSprite_setScale(s->sprite, scale);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the origin of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param origin New origin point of the `ansprite_t`.
///
/// This function sets the origin point of the `ansprite_t` to the specified
/// coordinates.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_origin(ansprite_t *s, vec2f origin)
{
    sfSprite_setOrigin(s->sprite, origin);
}
