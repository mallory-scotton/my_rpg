/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** countchar
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the occurrences of a specified character in a null-terminated
///        string.
///
/// \param str  Pointer to the null-terminated string.
/// \param ch   The character to count in the string.
///
/// \return     The number of occurrences of the specified character in the
///             string.
///
///////////////////////////////////////////////////////////////////////////////
ulong my_countchar(cstring str, char ch)
{
    ulong count = ch == '\0' ? 1 : 0;

    for (; *str; str++)
        if (*str == ch)
            count++;
    return (count);
}
