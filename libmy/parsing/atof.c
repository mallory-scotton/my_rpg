/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** atof
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a floating-point number
///
/// \param str  The input string to convert to a floating-point number
///
/// \return    Returns the floating-point value corresponding to 'str'
///
///////////////////////////////////////////////////////////////////////////////
double my_atof(string str)
{
    int pi = 0;
    int pf = 0;
    string s = NULL;

    RETURN(*str == '\0', 0.0f);
    pi = my_strtol(str, &str);
    if (*str == '.') {
        str++;
        s = str;
        pf = my_strtol(str, &str);
        return ((double)pi + ((double)pf) / pow(10, my_strlen(s)));
    }
    return ((double)pi);
}
