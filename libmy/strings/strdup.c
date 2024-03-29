/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** strdup
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Duplicate a string
///
/// \param str   The input string to duplicate
///
/// \return      A pointer to the duplicated string, or NULL if memory
///              allocation fails
///
///////////////////////////////////////////////////////////////////////////////
string my_strdup(cstring str)
{
    ulong len = my_strlen(str) + 1;
    string copy;

    copy = malloc(len);
    RETURN(!copy, NULL);
    my_memcpy(copy, str, len);
    return (copy);
}
