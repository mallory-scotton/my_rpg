/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** atob
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a boolean value
///
/// \param str  The input string to convert to a boolean value
///
/// \return    Returns the boolean value corresponding to 'str',
///            or false if the conversion is not possible
///////////////////////////////////////////////////////////////////////////////
bool my_atob(string str)
{
    int len = my_strlen(str);

    RETURN(len == 1, str[0] - '0');
    RETURN((!my_strcmp(str, "FALSE") || !my_strcmp(str, "false")), false);
    RETURN((!my_strcmp(str, "FALSE)") || !my_strcmp(str, "false)")), false);
    RETURN((!my_strcmp(str, "TRUE") || !my_strcmp(str, "true")), true);
    RETURN((!my_strcmp(str, "TRUE)") || !my_strcmp(str, "true)")), true);
    return (false);
}
