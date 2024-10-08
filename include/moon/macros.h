/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "moon.h"
    #include "my.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Shortener for sfColor_fromRGB
///
///////////////////////////////////////////////////////////////////////////////
    #define RGB sfColor_fromRGB

///////////////////////////////////////////////////////////////////////////////
/// \brief Shortener for sfColor_fromRGBA
///
///////////////////////////////////////////////////////////////////////////////
    #define RGBA sfColor_fromRGBA

///////////////////////////////////////////////////////////////////////////////
/// \brief Keyboard function shortener. Give the pressed status of a certain
/// key
///
/// \param key          The key to check for pressed status
///
/// \return The pressed status of the key
///
///////////////////////////////////////////////////////////////////////////////
    #define PRESSED(key) sfKeyboard_isKeyPressed(key)

///////////////////////////////////////////////////////////////////////////////
/// \brief Mouse function shortener. Give the pressed status of a certain mouse
/// button
///
/// \param btn          The button to check the status
///
/// \return The pressed status
///
///////////////////////////////////////////////////////////////////////////////
    #define MPRESSED(btn) sfMouse_isButtonPressed(btn)

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert any vector to a sfVector2i
///
/// \param v            The vector to convert
///
/// \return The converted vector
///
///////////////////////////////////////////////////////////////////////////////
    #define CV2I(v) ((v2i_t){(int)v.x, (int)v.y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Convert any vector to a sfVector2f
///
/// \param v            The vector to convert
///
/// \return The converted vector
///
///////////////////////////////////////////////////////////////////////////////
    #define CV2F(v) ((v2f_t){(float)v.x, (float)v.y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the scaling factor based on the desired size, total size,
/// and screen size.
///
/// \param x            The desired size to scale
/// \param total        The total size of the view (width or height)
/// \param screen       The size of the screen (width or height)
///
/// \return The calculated scaling factor
///
///////////////////////////////////////////////////////////////////////////////
    #define SCALE_FACTOR(x, total, screen) ((x) * (total) / (screen))

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the horizontal scaling factor difference between the
/// screen and the view
///
/// \param x            The value to calculate the scaling factor
///
/// \return The scaling factor
///
///////////////////////////////////////////////////////////////////////////////
    #define FACTORX(x) SCALE_FACTOR(x, Win.viewWidth, Win.width)

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the vertical scaling factor difference between the screen
/// and the view
///
/// \param y            The value to calculate the scaling factor
///
/// \return The scaling factor
///
///////////////////////////////////////////////////////////////////////////////
    #define FACTORY(y) SCALE_FACTOR(y, Win.viewHeight, Win.height)

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the factor for a fixed size on the screen
///
/// \param v            The size to scale
///
/// \return The scaling factors to achieve this size
///
///////////////////////////////////////////////////////////////////////////////
    #define FACTORS(v) ((v2f_t){FACTORX(v.x) / v.x, FACTORY(v.y) / v.y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Shortener for 'mapCoordsToPixel', convert the map coordinate system
/// to the screen coordinate
///
/// \param v            The point to convert
///
/// \return The converted point on the screen
///
///////////////////////////////////////////////////////////////////////////////
    #define MAP_TO_PX(v) sfRenderWindow_mapCoordsToPixel(Win.self, v, Win.view)

///////////////////////////////////////////////////////////////////////////////
/// \brief Shortener for 'mapPixelToCoords', convert screen system to world
/// coordinate system
///
/// \param v            The point to convert
///
/// \return The converted point on the world
///
///////////////////////////////////////////////////////////////////////////////
    #define PX_TO_MAP(v) sfRenderWindow_mapPixelToCoords(Win.self, v, Win.view)

///////////////////////////////////////////////////////////////////////////////
/// \brief Shortener for 'mapCoordsToPixel', convert the map coordinate system
/// to the screen coordinate and return an sfVector2f
///
/// \param v            The point to convert
///
/// \return The converted point on the screen and return an sfVector2f
///
///////////////////////////////////////////////////////////////////////////////
    #define MAP_TO_PXF(v) CV2F(MAP_TO_PX(CV2F(v)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Shortener for 'mapPixelToCoords', convert screen system to world
/// coordinate system and return an sfVector2f
///
/// \param v            The point to convert
///
/// \return The converted point on the world
///
///////////////////////////////////////////////////////////////////////////////
    #define PX_TO_MAPF(v) CV2F(PX_TO_MAP(CV2I(v)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the cube of a number.
///
/// \param x            The input value.
///
/// \return The cube of x.
///
///////////////////////////////////////////////////////////////////////////////
    #define CUBE(x) ((x) * (x) * (x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the square of a number.
///
/// \param x            The input value.
///
/// \return The square of x.
///
///////////////////////////////////////////////////////////////////////////////
    #define SQUARE(x) ((x) * (x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro to calculate the midpoint between two values.
///
/// \param x            The first value
/// \param y            The second value
///
/// \return The midpoint between the two input values
///
///////////////////////////////////////////////////////////////////////////////
    #define MID(x, y) ((x - y) / 2)

///////////////////////////////////////////////////////////////////////////////
/// \brief Transform an integer into a boolean
///
/// \param x            The value to transfrom
///
/// \return The booleanify value
///
///////////////////////////////////////////////////////////////////////////////
    #define BOOL(x) ((x) ? true : false)

///////////////////////////////////////////////////////////////////////////////
/// \brief Compare two strings together
///
/// \param str1         The first string
/// \param str2         The second string
///
/// \return True if the two string are equal, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
    #define CMP(str1, str2) (!my_strcmp(str1, str2))

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a value exists in a null-terminated array of strings.
///
/// \param wa           The null-terminated array of strings to be checked.
/// \param search       The value to be searched for in the array.
///
/// \return True if the value is found, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
    #define WCMP(wa, str) (my_wacmp(wa, str))

///////////////////////////////////////////////////////////////////////////////
/// \brief Orealloc shortener
///
/// \param ptr          The pointer to realloc
/// \param size         Size of one object
/// \param n            New number of object
///
/// \return The newly alloced ptr
///
///////////////////////////////////////////////////////////////////////////////
    #define REALLOC(ptr, size, n) (my_orealloc(ptr, size * (n - 1), size * n))

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector2f from 2 value
///
/// \param x            The x value
/// \param y            The y value
///
/// \return The newly created sfVector2f
///
///////////////////////////////////////////////////////////////////////////////
    #define V2F(x, y) ((v2f_t){x, y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector2f from 1 value
///
/// \param x            The value
///
/// \return The newly created sfVector2f
///
///////////////////////////////////////////////////////////////////////////////
    #define V2F1(x) ((v2f_t){x, x})

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector2i from 2 value
///
/// \param x            The x value
/// \param y            The y value
///
/// \return The newly created sfVector2i
///
///////////////////////////////////////////////////////////////////////////////
    #define V2I(x, y) ((v2i_t){x, y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector2i from 1 value
///
/// \param x            The value
///
/// \return The newly created sfVector2i
///
///////////////////////////////////////////////////////////////////////////////
    #define V2I1(x) ((v2i_t){x, x})

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector2u from 2 value
///
/// \param x            The x value
/// \param y            The y value
///
/// \return The newly created sfVector2u
///
///////////////////////////////////////////////////////////////////////////////
    #define V2U(x, y) ((v2u_t){x, y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector2u from 1 value
///
/// \param x            The value
///
/// \return The newly created sfVector2u
///
///////////////////////////////////////////////////////////////////////////////
    #define V2U1(x) ((v2u_t){x, x})

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector3f from 3 value
///
/// \param x            The x value
/// \param y            The y value
/// \param z            The z value
///
/// \return The newly created sfVector3f
///
///////////////////////////////////////////////////////////////////////////////
    #define V3F(x, y, z) ((v3f_t){(x), (y), (z)})

///////////////////////////////////////////////////////////////////////////////
/// \brief Generate a Vector3f from 1 value
///
/// \param x            The value
///
/// \return The newly created sfVector3f
///
///////////////////////////////////////////////////////////////////////////////
    #define V3F1(x) ((v3f_t){(x), (x), (x)})

#endif /* !MACROS_H_ */
