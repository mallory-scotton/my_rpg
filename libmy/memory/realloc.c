/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** realloc
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Reallocate memory for a block with a new size and copy the
/// existing data.
///
/// \param ptr   Pointer to the current memory block to be reallocated.
/// \param size  New size of the memory block in bytes.
///
/// \return      Pointer to the reallocated and copied memory block.
///
///////////////////////////////////////////////////////////////////////////////
void *my_realloc(void *ptr, ulong size)
{
    void *dest = malloc(size);

    memset(dest, 0, size);
    if (dest)
        my_memcpy(dest, ptr, size);
    free(ptr);
    return (dest);
}
