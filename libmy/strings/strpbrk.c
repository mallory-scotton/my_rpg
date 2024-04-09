/*
** EPITECH PROJECT, 2024
** amazed
** File description:
** strpbrk
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "my.h"

///////////////////////////////////////////////////////////////////////////////
string my_strpbrk(cstring s, cstring accept)
{
    cstring a;

    for (; *s; s++) {
        a = accept;
        for (; *a; a++)
            RETURN(*a == *s, (string)s);
    }
    return (NULL);
}
