/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** free
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Safe free avoiding freeing NULL
///
/// \param ptr The pointer
///
///////////////////////////////////////////////////////////////////////////////
void my_free(void **ptr)
{
    if (ptr != NULL && *ptr != NULL) {
        free(*ptr);
        *ptr = NULL;
    }
}
