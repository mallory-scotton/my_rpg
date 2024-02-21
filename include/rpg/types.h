/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** types
*/

#ifndef TYPES_H_
    #define TYPES_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg/dependencies.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Undefine existing boolean macros to ensure consistent definitions.
///
///////////////////////////////////////////////////////////////////////////////
    #undef bool
    #undef true
    #undef false

///////////////////////////////////////////////////////////////////////////////
/// \brief Redefine boolean types and their values.
///
///////////////////////////////////////////////////////////////////////////////
typedef enum {
    false,
    true
} bool;

///////////////////////////////////////////////////////////////////////////////
/// \brief Typedefs for commonly used unsigned integer types.
///
/// These typedefs define commonly used unsigned integer types, providing more
/// meaningful names for variables of these types.
///
/// \typedef uchar   unsigned char
/// \typedef ushort  unsigned short
/// \typedef uint    unsigned int
/// \typedef ulong   unsigned long
///
///////////////////////////////////////////////////////////////////////////////
typedef unsigned char uchar;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef unsigned long ulong;

///////////////////////////////////////////////////////////////////////////////
/// \brief Typedefs for string types.
///
/// These typedefs define string types to provide clearer semantics when
/// working with character arrays and strings.
///
/// \typedef string   char*
/// \typedef ustring  unsigned char*
/// \typedef cstring  const char*
/// \typedef custring const unsigned char*
///
///////////////////////////////////////////////////////////////////////////////
typedef char *string;
typedef unsigned char *ustring;
typedef const char *cstring;
typedef const unsigned char *custring;

///////////////////////////////////////////////////////////////////////////////
/// \brief Typedef for an array of mutable strings.
///
/// This typedef defines a type 'warray' representing an array of mutable
/// strings (char pointers). The array is expected to be terminated by a
/// NULL pointer.
///
///////////////////////////////////////////////////////////////////////////////
typedef string *warray;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure for handling a buffer with content and size.
///
/// The buffer_t structure represents a buffer with a content string and its
/// size. It is typically used for storing data before writing it to a file or
/// performing other operations.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct buffer_s {
    string content;
    ulong size;
} buffer_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Vector structures
///
/// \param vec2f    Floating x, y
/// \param vec3f    Floating x, y, z
/// \param vec2u    Unsigned x, y
/// \param vec2i    Integer x, y
///
///////////////////////////////////////////////////////////////////////////////
typedef sfVector2f vec2f;
typedef sfVector3f vec3f;
typedef sfVector2u vec2u;
typedef sfVector2i vec2i;

#endif /* !TYPES_H_ */
