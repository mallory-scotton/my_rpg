/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** operation
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Adds two vectors component-wise.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The result of adding vectors a and b component-wise.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_add(vec2f a, vec2f b)
{
    return (VEC2(a.x + b.x, a.y + b.y));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Multiplies a vector by a scalar.
///
/// \param v    The vector to be multiplied.
/// \param s    The scalar value.
///
/// \return The result of multiplying vector v by scalar s.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_multiply(vec2f v, float s)
{
    return (VEC2(v.x * s, v.y * s));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Subtracts one vector from another.
///
/// \param a    The vector to subtract from.
/// \param b    The vector to subtract.
///
/// \return The result of subtracting vector b from vector a.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_subtract(vec2f a, vec2f b)
{
    return (VEC2(a.x - b.x, a.y - b.y));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Divides a vector by a scalar.
///
/// \param v    The vector to be divided.
/// \param s    The scalar value.
///
/// \return The result of dividing vector v by scalar s.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_divide(vec2f v, float s)
{
    float invs;

    if (s == 0.0f)
        return (VEC2(0.0f, 0.0f));
    invs = 1.0f / s;
    return (VEC2(v.x * invs, v.y * invs));
}
