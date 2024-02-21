/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** strsplit
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert a string to a word array using a separator
///
/// \param str  Pointer to the null-derminated string
/// \param str  The separator used
///
/// \return Array of words
///
///////////////////////////////////////////////////////////////////////////////
warray my_strsplit(string str, char separator)
{
    string cpy = my_strdup(str);
    warray wa = malloc(sizeof(string) * (my_countchar(str, separator) + 2));
    string tok = my_strtok(cpy, &separator);
    ulong wi = 0;

    if (tok == NULL) {
        FREE(wa);
        FREE(cpy);
        return (NULL);
    }
    while (tok != NULL) {
        wa[wi] = my_strdup(tok);
        wi++;
        tok = my_strtok(NULL, &separator);
    }
    wa[wi] = 0;
    FREE(cpy);
    return (wa);
}
