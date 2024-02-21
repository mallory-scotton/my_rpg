/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** strtok_r
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Extract tokens from a string.
///
/// \param s          String to tokenize (NULL for subsequent calls).
/// \param delim      Delimiter characters.
/// \param save_ptr   Pointer to a string to maintain state across calls.
///
/// \return A pointer to the next token in the string, or NULL if no more
///         tokens are found.
///
///////////////////////////////////////////////////////////////////////////////
string my_strtok_r(string s, cstring delim, string *save_ptr)
{
    string token;

    if (s == NULL)
        s = *save_ptr;
    s += my_strspn(s, delim);
    if (*s == '\0') {
        *save_ptr = s;
        return (NULL);
    }
    token = s;
    s = my_strpbrk(token, delim);
    if (s == NULL)
        *save_ptr = my_strchr(token, '\0');
    else {
        *s = '\0';
        *save_ptr = s + 1;
    }
    return (token);
}
