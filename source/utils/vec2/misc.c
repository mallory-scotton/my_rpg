/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** misc
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the angle (in radians) between two vectors.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The angle between vectors a and b in radians.
///
///////////////////////////////////////////////////////////////////////////////
float vec2f_angle(vec2f a, vec2f b)
{
    float dot_product = vec2f_dot(a, b);
    float mag_product = sqrt(vec2f_dot(a, a) * vec2f_dot(b, b));

    return (acos(dot_product / mag_product));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the distance between two points.
///
/// \param a    The first point.
/// \param b    The second point.
///
/// \return The distance between points a and b.
///
///////////////////////////////////////////////////////////////////////////////
float vec2f_distance(vec2f a, vec2f b)
{
    float dx = b.x - a.x;
    float dy = b.y - a.y;

    return (sqrt(dx * dx + dy * dy));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the dot product of two vectors.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The dot product of vectors a and b.
///
///////////////////////////////////////////////////////////////////////////////
float vec2f_dot(vec2f a, vec2f b)
{
    return (a.x * b.x + a.y * b.y);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Linearly interpolates between two vectors.
///
/// \param a    The starting vector.
/// \param b    The ending vector.
/// \param t    Interpolation value [0, 1] for calculating the value.
///
/// \return The linear interpolation based on t for vectors a and b.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_lerp(vec2f a, vec2f b, float t)
{
    return (VEC2(a.x + (b.x - a.x) * t, a.y + (b.y - a.y) * t));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the end point of a vector from an origin.
///
/// \param origin The starting point of the vector.
/// \param direction The direction vector of the vector.
/// \param distance The distance from the origin to the end point.
///
/// \return The end point of the vector.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_end(vec2f origin, vec2f direction, float distance)
{
    vec2f normalized = vec2f_subtract(direction, origin);
    float length = sqrtf(SQUARE(normalized.x) + SQUARE(normalized.y));

    normalized = vec2f_divide(normalized, length);
    return (VEC2F(
        origin.x + normalized.x * distance,
        origin.y + normalized.y * distance
    ));
}
