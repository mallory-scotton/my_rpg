/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** strtol
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a long integer
///
/// \param s     The string to convert
/// \param ptr   A pointer to a pointer to char, which will be updated to point
///              to the first non-converted character
///
/// \return      The converted long integer value
///
///////////////////////////////////////////////////////////////////////////////
int my_strtol(char *s, char **ptr)
{
    ulong i = 0;
    int n = 0;
    bool sign = false;

    while (s[i] == ' ')
        i++;
    if (s[i] == '-') {
        i++;
        sign = true;
    }
    while (my_isdigit(s[i])) {
        n = (n * 10) + (s[i] - '0');
        i++;
    }
    (*ptr) = (*ptr + i);
    return (sign ? -n : n);
}
