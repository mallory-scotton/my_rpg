/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** memcpy
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Copy memory area
///
/// This function copies 'n' bytes from the memory area pointed to by 'src' to
/// the memory area pointed to by 'dst'. The copying stops when 'n' bytes are
/// copied or when a null terminator is encountered in the source string.
///
/// \param dst   Pointer to the destination memory area
/// \param src   Pointer to the source memory area
/// \param n     Number of bytes to copy
///
/// \return      Pointer to the destination memory area ('dst')
///////////////////////////////////////////////////////////////////////////////
void *my_memcpy(void *dst, const void *src, ulong n)
{
    ulong i = 0;
    string csrc = (string)src;
    string cdst = (string)dst;

    while ((i < n || n == (ulong) - 1) && csrc != NULL && csrc[i]) {
        cdst[i] = csrc[i];
        ++i;
    }
    cdst[i] = 0;
    return (dst);
}
