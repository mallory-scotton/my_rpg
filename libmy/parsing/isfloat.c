/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** isfloat
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid floating-point number
///
/// \param str  The input string to check for floating-point representation
///
/// \return    Returns true if 'str' represents a valid floating-point number,
///            otherwise false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isfloat(cstring str)
{
    bool pts = false;

    if (*str == '-' || *str == '+')
        str++;
    for (; *str; str++) {
        if (*str == '.' && pts == false) {
            pts = true;
            str++;
        }
        RETURN(!(*str >= '0' && *str <= '9'), false);
    }
    return (true);
}
