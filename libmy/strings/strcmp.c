/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** strcmp
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Compare two strings.
///
/// \param s1    The first string to compare.
/// \param s2    The second string to compare.
///
/// \return An integer less than, equal to, or greater than zero if s1
/// is found, respectively, to be less than, to match, or be greater than s2.
///
///////////////////////////////////////////////////////////////////////////////
int my_strcmp(cstring s1, cstring s2)
{
    for (; *s1 == *s2; s2++) {
        if (*s1 == '\0')
            return (0);
        s1++;
    }
    return (*(const uchar *)s1 - *(const uchar *)s2);
}
