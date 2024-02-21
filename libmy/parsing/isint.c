/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** isint
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid integer
///
/// \param str  The input string to check for integer representation
///
/// \return Returns true if 'str' represents a valid integer, otherwise
/// false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isint(cstring str)
{
    if (*str == '-' || *str == '+')
        str++;
    for (; *str; str++)
        RETURN(!(*str >= '0' && *str <= '9'), false);
    return (true);
}
