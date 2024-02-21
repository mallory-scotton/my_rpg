/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** strspn
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the length of the initial segment of a string consisting
///        of only characters from another string.
///
/// \param s1  Pointer to the null-terminated string to check.
/// \param s2  Pointer to the null-terminated string containing characters to
///            match against.
///
/// \return The length of the initial segment of s1 consisting of only
///         characters from s2.
///
///////////////////////////////////////////////////////////////////////////////
ulong my_strspn(cstring s1, cstring s2)
{
    cstring s = s1;
    cstring c;

    while (*s1) {
        for (c = s2; *c && !(*s1 == *c); c++);
        if (*c == '\0')
            break;
        s1++;
    }
    return (s1 - s);
}
