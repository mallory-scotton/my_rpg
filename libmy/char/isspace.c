/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** isspace
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a character is a whitespace character (tab, newline,
/// vertical tab, form feed, carriage return, or space).
///
/// \param c    The character to check
///
/// \return true if the character is a whitespace character, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool my_isspace(int c)
{
    return (c == '\t' || c == '\n' || c == '\v' || c == '\f' ||
        c == '\r' || c == ' ' ? true : false);
}
