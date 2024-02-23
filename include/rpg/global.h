/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** global
*/

#ifndef GLOBAL_H_
    #define GLOBAL_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg/dependencies.h"
    #include "rpg/types.h"
    #include "rpg/libmy.h"

///////////////////////////////////////////////////////////////////////////////
// CLASS: WINDOW

///////////////////////////////////////////////////////////////////////////////
/// \brief Window structure
///
/// \param self         References to the render window
/// \param size         2D vector representing the size of the window
/// \param isFullscreen Boolean, true if the window is in fullscreen, false
///                     otherwise.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct global_window_s {
    sfRenderWindow *self;
    sfView *view;
    vec2u size;
    bool isFullscreen;
} global_window_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Win global variable
///
/// \param self         References to the render window
/// \param size         2D vector representing the size of the window
/// \param isFullscreen Boolean, true if the window is in fullscreen, false
///                     otherwise.
///
///////////////////////////////////////////////////////////////////////////////
extern global_window_t *Win;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the window.
///
/// This function creates the main SFML window with the specified dimensions,
/// title, style, and context settings. It also initializes the window icon
/// if a valid path is provided. The window is then configured with the desired
/// framerate limit, and its position is set to the center of the screen if
/// the WIN_CENTERED flag is true.
///
/// \return    true if the window is successfully initialized, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
status window_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Update the main window dimensions.
///
/// This function retrieves the current size of the main window using
/// sfRenderWindow_getSize, and ensures that it falls within the specified
/// minimum and maximum dimensions. If the size is outside this range,
/// it is clamped to the valid range using the CLAMP macro. The updated size
/// is then applied to the window using sfRenderWindow_setSize.
///
/// \param size     The resized event value
///
///////////////////////////////////////////////////////////////////////////////
void window_update(sfSizeEvent size);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the main window.
///
/// This function checks if the main window exists (not NULL) and destroys it
/// using sfRenderWindow_destroy. After calling this function, the window
/// pointer in the Win structure should be set to NULL to avoid potential
/// issues with accessing a destroyed window.
///
///////////////////////////////////////////////////////////////////////////////
void window_destroy(void);

///////////////////////////////////////////////////////////////////////////////
// CLASS: VECTOR2

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a vec2f vector
///
/// \param x    The x value
/// \param y    The y value
///
/// \return A vec2f vector created with x and y
///
///////////////////////////////////////////////////////////////////////////////
    #define VEC2(x, y) ((vec2f){x, y})
    #define VEC2F VEC2

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a vec2i vector
///
/// \param x    The x value
/// \param y    The y value
///
/// \return A vec2i vector created with x and y
///
///////////////////////////////////////////////////////////////////////////////
    #define VEC2I(x, y) ((vec2i){x, y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a vec2u vector
///
/// \param x    The x value
/// \param y    The y value
///
/// \return A vec2u vector created with x and y
///
///////////////////////////////////////////////////////////////////////////////
    #define VEC2U(x, y) ((vec2u){x, y})

///////////////////////////////////////////////////////////////////////////////
/// \brief Vec2f operation structures
///
/// \param lerp         Linear interpolation between two vec2f
/// \param angle        Calculate the angle between two vec2f
/// \param subtract     Subtract two vec2f
/// \param multiply     Multiply two vec2f
/// \param add          Add two vec2f
/// \param divide       Divide two vec2f
/// \param distance     Calculate the distance between two vec2f
/// \param equal        Is two vec2f equal
/// \param dot          Dot product of two vec2f
/// \param min          The minimum of two vec2f
/// \param max          The maximum of two vec2f
/// \param end          Calculate the end point of a vector from an origin.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct global_vec2_s {
    vec2f (*lerp)(vec2f a, vec2f b, float t);
    float (*angle)(vec2f a, vec2f b);
    vec2f (*subtract)(vec2f a, vec2f b);
    vec2f (*multiply)(vec2f v, float s);
    vec2f (*add)(vec2f a, vec2f b);
    vec2f (*divide)(vec2f v, float s);
    float (*distance)(vec2f a, vec2f b);
    bool (*equal)(vec2f a, vec2f b);
    float (*dot)(vec2f a, vec2f b);
    vec2f (*min)(vec2f a, vec2f b);
    vec2f (*max)(vec2f a, vec2f b);
    vec2f (*end)(vec2f origin, vec2f direction, float distance);
} global_vec2_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Divides a vector by a scalar.
///
/// \param v    The vector to be divided.
/// \param s    The scalar value.
///
/// \return The result of dividing vector v by scalar s.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_divide(vec2f v, float s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Subtracts one vector from another.
///
/// \param a    The vector to subtract from.
/// \param b    The vector to subtract.
///
/// \return The result of subtracting vector b from vector a.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_subtract(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Multiplies a vector by a scalar.
///
/// \param v    The vector to be multiplied.
/// \param s    The scalar value.
///
/// \return The result of multiplying vector v by scalar s.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_multiply(vec2f v, float s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Adds two vectors component-wise.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The result of adding vectors a and b component-wise.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_add(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Returns the component-wise maximum of two vectors.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The vector with the maximum components from vectors a and b.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_max(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Returns the component-wise minimum of two vectors.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The vector with the minimum components from vectors a and b.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_min(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Checks if two vectors are equal component-wise.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return true if vectors a and b are equal, false otherwise.
///
///////////////////////////////////////////////////////////////////////////////
bool vec2f_equal(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the angle (in radians) between two vectors.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The angle between vectors a and b in radians.
///
///////////////////////////////////////////////////////////////////////////////
float vec2f_angle(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the distance between two points.
///
/// \param a    The first point.
/// \param b    The second point.
///
/// \return The distance between points a and b.
///
///////////////////////////////////////////////////////////////////////////////
float vec2f_distance(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculates the dot product of two vectors.
///
/// \param a    The first vector.
/// \param b    The second vector.
///
/// \return The dot product of vectors a and b.
///
///////////////////////////////////////////////////////////////////////////////
float vec2f_dot(vec2f a, vec2f b);

///////////////////////////////////////////////////////////////////////////////
/// \brief Linearly interpolates between two vectors.
///
/// \param a    The starting vector.
/// \param b    The ending vector.
/// \param t    Interpolation value [0, 1] for calculating the value.
///
/// \return The linear interpolation based on t for vectors a and b.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_lerp(vec2f a, vec2f b, float t);

///////////////////////////////////////////////////////////////////////////////
/// \brief Calculate the end point of a vector from an origin.
///
/// \param origin The starting point of the vector.
/// \param direction The direction vector of the vector.
/// \param distance The distance from the origin to the end point.
///
/// \return The end point of the vector.
///
///////////////////////////////////////////////////////////////////////////////
vec2f vec2f_end(vec2f origin, vec2f direction, float distance);

///////////////////////////////////////////////////////////////////////////////
/// \brief Vec2 operation structures
///
/// \param lerp         Linear interpolation between two vec2f
/// \param angle        Calculate the angle between two vec2f
/// \param subtract     Subtract two vec2f
/// \param multiply     Multiply two vec2f
/// \param add          Add two vec2f
/// \param divide       Divide two vec2f
/// \param distance     Calculate the distance between two vec2f
/// \param equal        Is two vec2f equal
/// \param dot          Dot product of two vec2f
/// \param min          The minimum of two vec2f
/// \param max          The maximum of two vec2f
/// \param end          Calculate the end point of a vector from an origin.
///
///////////////////////////////////////////////////////////////////////////////
extern global_vec2_t Vec2;

///////////////////////////////////////////////////////////////////////////////
// CLASS: TIME

///////////////////////////////////////////////////////////////////////////////
/// \brief Time macros redefinitions
///
///////////////////////////////////////////////////////////////////////////////
    #define TIME_US sfTime_asMicroseconds
    #define TIME_MS sfTime_asMilliseconds
    #define TIME_SE sfTime_asSeconds

///////////////////////////////////////////////////////////////////////////////
/// \brief Constants structure that used for timing
///
/// \param deltaTime    DeltaTime between two frames in milliseconds
/// \param currentTime  Current time of the frame
/// \param clock        Global engine clock
///
///////////////////////////////////////////////////////////////////////////////
typedef struct global_time_s {
    double deltaTime;
    sfTime currentTime;
    sfClock *clock;
} global_time_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Global Time variables
///
/// This variable contain the global engine clock, the delta time calculated
/// between each frames, and the current time of the engine. The delta time
/// is in milliseconds and the current time is a sfTime struct and can be
/// tansformed using TIME_US (microsecond), TIME_MS (millisecond) and
/// TIME_SE (second).
///
///////////////////////////////////////////////////////////////////////////////
extern global_time_t *Time;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the global Time variable, and all the components linked
///
/// \return The status of the operation, if the operation fail, stop the game
/// engine.
///
///////////////////////////////////////////////////////////////////////////////
status time_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Update the Time variable
///
/// This function need to be executed at the start of each frame for the
/// calculation of the deltaTime.
///
/// \return The status of the operation, if the operation fail, it means that
/// the initialization failed, and need to leave the engine.
///
///////////////////////////////////////////////////////////////////////////////
status time_update(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the variable and clean the used ressources
///
/// This function will free the memory and destroy the clock to clean
/// the used ressources.
///
/// \return This function could only return a success status.
///
///////////////////////////////////////////////////////////////////////////////
status time_destroy(void);

///////////////////////////////////////////////////////////////////////////////
// CLASS: SETTINGS

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to hold keybindings.
///
/// This structure defines keybindings using SFML key codes for arrow keys,
/// function keys, mouse buttons, etc.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct keybind_s {
    sfKeyCode up;
    sfKeyCode down;
    sfKeyCode right;
    sfKeyCode left;
    sfKeyCode reload;
    sfKeyCode heal;
    sfKeyCode dash;
    sfKeyCode interact;
    sfKeyCode pause;
    sfMouseButton shoot;
} keybind_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to hold global settings.
///
/// This structure holds global settings, including keybindings.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct global_settings_s {
    keybind_t *keybind;
} global_settings_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Pointer to global settings.
///
/// This extern variable is a pointer to the global settings structure.
///
///////////////////////////////////////////////////////////////////////////////
extern global_settings_t *Settings;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize global settings.
///
/// \return success on successful initialization, fail otherwise.
///
///////////////////////////////////////////////////////////////////////////////
status settings_init(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy global settings.
///
///////////////////////////////////////////////////////////////////////////////
void settings_destroy(void);

#endif /* !GLOBAL_H_ */
