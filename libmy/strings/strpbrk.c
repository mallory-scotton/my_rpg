/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** strpbrk
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Locate the first occurrence of any character in a set.
///
/// \param s        Pointer to the null-terminated string to search.
/// \param accept   Pointer to the null-terminated set of characters to match.
///
/// \return A pointer to the first matching character in the string or NULL.
///
///////////////////////////////////////////////////////////////////////////////
string my_strpbrk(cstring s, cstring accept)
{
    cstring a;

    for (; *s; s++) {
        a = accept;
        for (; *a; a++)
            RETURN(*a == *s, (string)s);
    }
    return (NULL);
}
