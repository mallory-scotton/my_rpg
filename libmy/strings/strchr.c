/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** strchr
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Locate the first occurrence of a character in a string.
///
/// \param p   Pointer to the null-terminated string to search.
/// \param ch  The character to search for.
///
/// \return A pointer to the first matching character in the string or NULL.
///
///////////////////////////////////////////////////////////////////////////////
string my_strchr(cstring p, int ch)
{
    char c = ch;

    for (;; ++p) {
        RETURN(*p == c, (string)p);
        RETURN(*p == '\0', NULL);
    }
}
