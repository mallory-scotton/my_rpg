/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** isbool
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a string represents a valid boolean value
///
/// \param str  The input string to check for boolean representation
///
/// \return    Returns true if 'str' represents a valid boolean value,
///            otherwise false
///
///////////////////////////////////////////////////////////////////////////////
bool my_isbool(cstring str)
{
    int len = my_strlen(str);

    if (len == 1 || (len == 2 && str[1] == ')')) {
        RETURN(str[0] == '0' || str[0] == '1', true);
        return (false);
    }
    if (my_strcmp(str, "FALSE") == 0 || my_strcmp(str, "TRUE") ||
        my_strcmp(str, "true") || my_strcmp(str, "false"))
        return (true);
    if (my_strcmp(str, "FALSE)") == 0 || my_strcmp(str, "TRUE)") ||
        my_strcmp(str, "true)") || my_strcmp(str, "false)"))
        return (true);
    return (false);
}
