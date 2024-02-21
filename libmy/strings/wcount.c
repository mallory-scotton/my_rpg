/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** wcount
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Count the number of words in the string
///
/// \param str  Pointer to the null-derminated string
///
/// \return Return the number of words
///
///////////////////////////////////////////////////////////////////////////////
ulong my_wcount(cstring str)
{
    ulong count = 0;
    bool found = false;

    for (; *str; ++str) {
        if (my_isspace(*str)) {
            found = false;
            continue;
        }
        if (found == false) {
            count++;
            found = true;
        }
    }
    return (count + 1);
}
