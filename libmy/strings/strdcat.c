/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** strdcat
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Concatenate three null-terminated strings and return the result.
///
/// \param s1  Pointer to the first null-terminated string.
/// \param s2  Pointer to the second null-terminated string.
/// \param s3  Pointer to the third null-terminated string.
///
/// \return    A dynamically allocated string containing the concatenated
///            result, or NULL on allocation failure.
///
///////////////////////////////////////////////////////////////////////////////
string my_strdcat(cstring s1, cstring s2, cstring s3)
{
    string str = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) +
        my_strlen(s3) + 1));
    string save = str;

    for (; *s1; s1++) {
        *str = *s1;
        str++;
    }
    for (; *s2; s2++) {
        *str = *s2;
        str++;
    }
    for (; *s3; s3++) {
        *str = *s3;
        str++;
    }
    *str = '\0';
    return (save);
}
