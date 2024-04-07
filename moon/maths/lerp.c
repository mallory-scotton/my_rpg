/*
** EPITECH PROJECT, 2024
** moon-engine
** File description:
** lerp
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "moon.h"

///////////////////////////////////////////////////////////////////////////////
int lerp(int start, int end, float t)
{
    return (start * (1 - t) + (end * t));
}

///////////////////////////////////////////////////////////////////////////////
float lerpf(float start, float end, float t)
{
    return (start * (1 - t) + (end * t));
}

///////////////////////////////////////////////////////////////////////////////
double lerpd(double start, double end, float t)
{
    return (start * (1 - t) + (end * t));
}
