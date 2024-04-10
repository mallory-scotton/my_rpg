/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** add
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "moon.h"

///////////////////////////////////////////////////////////////////////////////
v2f_t add2f(v2f_t a, v2f_t b)
{
    return ((v2f_t){a.x + b.x, a.y + b.y});
}

///////////////////////////////////////////////////////////////////////////////
v2i_t add2i(v2i_t a, v2i_t b)
{
    return ((v2i_t){a.x + b.x, a.y + b.y});
}

///////////////////////////////////////////////////////////////////////////////
v2u_t add2u(v2u_t a, v2u_t b)
{
    return ((v2u_t){a.x + b.x, a.y + b.y});
}

///////////////////////////////////////////////////////////////////////////////
v3f_t add3f(v3f_t a, v3f_t b)
{
    return ((v3f_t){a.x + b.x, a.y + b.y, a.z + b.z});
}
