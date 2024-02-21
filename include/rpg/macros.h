/*
** EPITECH PROJECT, 2024
** ak-axolotl
** File description:
** macros
*/

#ifndef MACROS_H_
    #define MACROS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg/dependencies.h"
    #include "rpg/types.h"
    #include "rpg/libmy.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Use my_free function by transforming the pointer to the correct type
///
/// \param ptr The pointer
///
///////////////////////////////////////////////////////////////////////////////
    #define FREE(p) my_free((void **)&(p))

///////////////////////////////////////////////////////////////////////////////
/// \brief Return a value if a condition is true
///
/// \param c   The condition to check
/// \param v   The value to return if the condition is true
///
///////////////////////////////////////////////////////////////////////////////
    #define RETURN(c, v) if ((c)) return (v)

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute one of two functions based on a condition
///
/// \param c   The condition to check
/// \param f1  The function to execute if the condition is true
/// \param f2  The function to execute if the condition is false
///
/// \return    The result of the executed function
///
///////////////////////////////////////////////////////////////////////////////
    #define SWITCH(c, f1, f2) ((c) ? (f1()) : (f2()))

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute one of two functions with an additional
/// parameter
///
/// \param c   The condition to check
/// \param f1  The function to execute if the condition is true
/// \param f2  The function to execute if the condition is false
/// \param x   The additional parameter to pass to the executed function
///
/// \return    The result of the executed function
///
///////////////////////////////////////////////////////////////////////////////
    #define SWITCHX(c, f1, f2, x) ((c) ? (f1(x)) : (f2(x)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute one of two functions with two additional
/// parameters
///
/// \param c   The condition to check
/// \param f1  The function to execute if the condition is true
/// \param f2  The function to execute if the condition is false
/// \param x   The first additional parameter to pass to the executed function
/// \param y   The second additional parameter to pass to the executed function
///
/// \return    The result of the executed function
///
///////////////////////////////////////////////////////////////////////////////
    #define SWITCHXY(c, f1, f2, x, y) ((c) ? (f1(x, y)) : (f2(x, y)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute one of two functions with three additional
/// parameters
///
/// \param c   The condition to check
/// \param f1  The function to execute if the condition is true
/// \param f2  The function to execute if the condition is false
/// \param x   The first additional parameter to pass to the executed function
/// \param y   The second additional parameter to pass to the executed function
/// \param z   The third additional parameter to pass to the executed function
///
/// \return    The result of the executed function
///
///////////////////////////////////////////////////////////////////////////////
    #define SWITCHXYZ(c, f1, f2, x, y, z) ((c) ? (f1(x, y, z)) : (f2(x, y, z)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Linearly interpolate between two values
///
/// \param a   The starting value
/// \param b   The ending value
/// \param t   The interpolation parameter (between 0 and 1)
///
/// \return    The interpolated value
///
///////////////////////////////////////////////////////////////////////////////
    #define LERP(a, b, t) ((a) * (1 - t) + (b) * (t))

///////////////////////////////////////////////////////////////////////////////
/// \brief Clamp a value between 0 and 1
///
/// \param x   The value to clamp
///
/// \return    The clamped value
///
///////////////////////////////////////////////////////////////////////////////
    #define CLAMP01(x) (((x) < 0) ? 0 : (((x) > 1) ? 1 : (x)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Return the minimum of two values
///
/// \param a   The first value
/// \param b   The second value
///
/// \return    The minimum value
///
///////////////////////////////////////////////////////////////////////////////
    #define MIN(a, b) ((a) < (b) ? (a) : (b))

///////////////////////////////////////////////////////////////////////////////
/// \brief Return the maximum of two values
///
/// \param a   The first value
/// \param b   The second value
///
/// \return    The maximum value
///
///////////////////////////////////////////////////////////////////////////////
    #define MAX(a, b) ((a) > (b) ? (a) : (b))

///////////////////////////////////////////////////////////////////////////////
/// \brief Return the absolute value of a number
///
/// \param x   The number
///
/// \return    The absolute value of the number
///
///////////////////////////////////////////////////////////////////////////////
    #define ABS(x) ((x) < 0 ? -(x) : (x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Clamp a value between a specified minimum and maximum
///
/// \param x   The value to clamp
/// \param mi  The minimum value
/// \param ma  The maximum value
///
/// \return    The clamped value
///
///////////////////////////////////////////////////////////////////////////////
    #define CLAMP(x, mi, ma) ((x) < (mi) ? (mi) : ((x) > (ma) ? (ma) : (x)))

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the cube of a number
///
/// \param x   The number
///
/// \return    The cube of the number
///
///////////////////////////////////////////////////////////////////////////////
    #define CUBE(x) ((x) * (x) * (x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the square of a number
///
/// \param x   The number
///
/// \return    The square of the number
///
///////////////////////////////////////////////////////////////////////////////
    #define SQUARE(x) ((x) * (x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute a function if a specified condition is true
///
/// \param c   The condition to check
/// \param f   The function to execute if the condition is true
///
///////////////////////////////////////////////////////////////////////////////
    #define DOIF(c, f) if ((c)) (f())

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute a function with an additional parameter if a
/// specified condition is true
///
/// \param c   The condition to check
/// \param f   The function to execute if the condition is true
/// \param x   The additional parameter to pass to the executed function
///
///////////////////////////////////////////////////////////////////////////////
    #define DOIFX(c, f, x) if ((c)) (f(x))

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute a function with two additional parameters if
/// a specified condition is true
///
/// \param c   The condition to check
/// \param f   The function to execute if the condition is true
/// \param x   The first additional parameter to pass to the executed function
/// \param y   The second additional parameter to pass to the executed function
///
///////////////////////////////////////////////////////////////////////////////
    #define DOIFXY(c, f, x, y) if ((c)) (f(x, y))

///////////////////////////////////////////////////////////////////////////////
/// \brief Conditionally execute a function with three additional parameters
/// if a specified condition is true
///
/// \param c   The condition to check
/// \param f   The function to execute if the condition is true
/// \param x   The first additional parameter to pass to the executed function
/// \param y   The second additional parameter to pass to the executed function
/// \param z   The third additional parameter to pass to the executed function
///
///////////////////////////////////////////////////////////////////////////////
    #define DOIFXYZ(c, f, x, y, z) if ((c)) (f(x, y, z))

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro to compute the minimum of three values.
///
/// \param a   The first value
/// \param b   The second value
/// \param c   The third value
///
/// \return    The minimum value among the three inputs
///
///////////////////////////////////////////////////////////////////////////////
    #define MIN3(a, b, c) MIN(MIN(a, b), c)

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro to compute the maximum of three values.
///
/// \param a   The first value
/// \param b   The second value
/// \param c   The third value
///
/// \return    The maximum value among the three inputs
///
///////////////////////////////////////////////////////////////////////////////
    #define MAX3(a, b, c) MAX(MAX(a, b), c)

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro to calculate the midpoint between two values.
///
/// \param x   The first value
/// \param y   The second value
///
/// \return    The midpoint between the two input values
///
///////////////////////////////////////////////////////////////////////////////
    #define MID(x, y) ((x - y) / 2)

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro to transform condition into boolean
///
/// \param c    The condition to check
///
/// \return The boolean translated condition
///
///////////////////////////////////////////////////////////////////////////////
    #define BOOL(c) ((c) ? true : false)

///////////////////////////////////////////////////////////////////////////////
/// \brief Macro to iterate over each element in a null-terminated sequence.
///
/// The FORALL macro iterates over each element in the null-terminated sequence
/// (x) and applies the specified function (f) to each element. It increments
/// the sequence after each iteration.
///
/// \param x  The null-terminated sequence to iterate over.
/// \param f  The function to apply to each element in the sequence.
///
///////////////////////////////////////////////////////////////////////////////
    #define FORALL(x, f) while (*(x)) f, x++

#endif /* !MACROS_H_ */
