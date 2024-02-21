/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** stowa
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a word array
///
/// \param str  Pointer to the null-derminated string
///
/// \return Array of words
///
///////////////////////////////////////////////////////////////////////////////
warray my_stowa(string str)
{
    warray wa;
    int wi = 0;
    string lw = str;

    RETURN(str == NULL, NULL);
    wa = malloc(sizeof(string) * my_wcount(str));
    for (;; ++str) {
        for (; *str && my_isspace(*str); ++str);
        lw = str;
        for (; *str && !my_isspace(*str); ++str);
        if (*str == '\0') {
            wa[wi] = my_strdup(lw);
            break;
        }
        *str = '\0';
        wa[wi] = my_strdup(lw);
        wi++;
    }
    wa[wi + BOOL(wa[wi][0] != '\0')] = NULL;
    return (wa);
}
