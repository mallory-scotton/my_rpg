/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** vec2
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Vec2f operation structures
///
/// \param lerp         Linear interpolation between two vec2f
/// \param angle        Calculate the angle between two vec2f
/// \param subtract     Subtract two vec2f
/// \param multiply     Multiply two vec2f
/// \param add          Add two vec2f
/// \param divide       Divide two vec2f
/// \param distance     Calculate the distance between two vec2f
/// \param equal        Is two vec2f equal
/// \param dot          Dot product of two vec2f
/// \param min          The minimum of two vec2f
/// \param max          The maximum of two vec2f
///
///////////////////////////////////////////////////////////////////////////////
global_vec2_t Vec2 = {
    &vec2f_lerp,
    &vec2f_angle,
    &vec2f_subtract,
    &vec2f_multiply,
    &vec2f_add,
    &vec2f_divide,
    &vec2f_distance,
    &vec2f_equal,
    &vec2f_dot,
    &vec2f_min,
    &vec2f_max,
    &vec2f_end
};
