/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** csfml
*/

#ifndef CSFML_H_
    #define CSFML_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include <stdlib.h>
    #include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Utility class for manipulating animation
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    string name;
    sfTexture *texture;
    uint maxFrame;
    vec2u frameSize;
    vec2u gridSize;
} animation_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Utility class for manipulating animated sprites
///
///////////////////////////////////////////////////////////////////////////////
typedef struct {
    sfSprite *sprite;
    animation_t **animations;
    uint currentAnimation;
    uint currentFrame;
    uint animationCount;
    ulong start;
} ansprite_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Creates an `ansprite_t` structure.
///
/// \param animations Array of animations to be associated with the ansprite.
///
/// \return A pointer to the created `ansprite_t` structure, or NULL on failure.
///
/// This function creates an `ansprite_t` structure and associates the provided
/// animations with it.
///
///////////////////////////////////////////////////////////////////////////////
ansprite_t *ansprite_create(animation_t **animations);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys an `ansprite_t` structure.
///
/// \param s Pointer to the `ansprite_t` structure to be destroyed.
///
/// This function destroys an `ansprite_t` structure, freeing associated
/// resources.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_destroy(ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the position of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param pos New position of the `ansprite_t`.
///
/// This function sets the position of the `ansprite_t` to the specified
/// coordinates.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_position(ansprite_t *s, vec2f pos);

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the rotation of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param rot New rotation angle in degrees.
///
/// This function sets the rotation angle of the `ansprite_t` to the specified
/// angle in degrees.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_rotation(ansprite_t *s, float rot);

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the scale of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param scale New scale factors for the `ansprite_t`.
///
/// This function sets the scale factors of the `ansprite_t` to the specified
/// values.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_scale(ansprite_t *s, vec2f scale);

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the origin of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param origin New origin point of the `ansprite_t`.
///
/// This function sets the origin point of the `ansprite_t` to the specified
/// coordinates.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_origin(ansprite_t *s, vec2f origin);

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the position of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Position of the `ansprite_t`.
///
///////////////////////////////////////////////////////////////////////////////
vec2f ansprite_get_position(const ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the rotation of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Rotation angle of the `ansprite_t` in degrees.
///
///////////////////////////////////////////////////////////////////////////////
float ansprite_get_rotation(const ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the scale of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Scale factors of the `ansprite_t`.
///
///////////////////////////////////////////////////////////////////////////////
vec2f ansprite_get_scale(const ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the origin of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Origin point of the `ansprite_t`.
///
///////////////////////////////////////////////////////////////////////////////
vec2f ansprite_get_origin(const ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Moves an `ansprite_t` by a specified offset.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param offset Offset by which to move the `ansprite_t`.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_move(ansprite_t *s, vec2f offset);

///////////////////////////////////////////////////////////////////////////////
/// \brief Rotates an `ansprite_t` by a specified angle.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param angle Angle by which to rotate the `ansprite_t` in degrees.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_rotate(ansprite_t *s, float angle);

///////////////////////////////////////////////////////////////////////////////
/// \brief Scales an `ansprite_t` by specified factors.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param factors Scale factors to apply to the `ansprite_t`.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_scale(ansprite_t *s, vec2f factors);

///////////////////////////////////////////////////////////////////////////////
/// \brief Sets the current animation of an `ansprite_t` by name.
///
/// \param s Pointer to the `ansprite_t` structure.
/// \param name Name of the animation to set as the current animation.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_set_current_animation(ansprite_t *s, cstring name);

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the array of animations associated with an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Pointer to the array of animations.
///
///////////////////////////////////////////////////////////////////////////////
animation_t **ansprite_get_animations(const ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Gets the currently playing animation of an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
/// \return Pointer to the currently playing animation.
///
///////////////////////////////////////////////////////////////////////////////
animation_t *ansprite_get_current_animation(const ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draws an `ansprite_t`.
///
/// \param s Pointer to the `ansprite_t` structure.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_draw(ansprite_t *s);

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure defining a set of functions to get various properties of
/// an `ansprite_t`.
///
/// This structure includes function pointers to retrieve information such as
/// position, rotation, scale, origin, animations, and the current animation
/// of an `ansprite_t`.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct global_ansprite_get_s {
    vec2f (*position)(const ansprite_t *ansprite);
    float (*rotation)(const ansprite_t *ansprite);
    vec2f (*scale)(const ansprite_t *ansprite);
    vec2f (*origin)(const ansprite_t *ansprite);
    animation_t **(*animations)(const ansprite_t *ansprite);
    animation_t *(*currentAnimation)(const ansprite_t *ansprite);
} global_ansprite_get_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure defining a set of functions to set various properties of
/// an `ansprite_t`.
///
/// This structure includes function pointers to modify properties such as
/// position, rotation, scale, origin, and the current animation of an
/// `ansprite_t`.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct global_ansprite_set_s {
    void (*position)(ansprite_t *ansprite, vec2f pos);
    void (*rotation)(ansprite_t *ansprite, float rot);
    void (*scale)(ansprite_t *ansprite, vec2f scale);
    void (*origin)(ansprite_t *ansprite, vec2f origin);
    void (*currentAnimation)(ansprite_t *ansprite, cstring name);
} global_ansprite_set_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure defining a set of functions to create, destroy, and
/// manipulate an `ansprite_t`.
///
/// This structure includes function pointers for creating an `ansprite_t`,
/// destroying it, moving, rotating, and scaling it, as well as getting and
/// setting various properties. It also contains a sub-structure (`get`) for
/// retrieving information and a sub-structure (`set`) for modifying
/// properties.
///
///////////////////////////////////////////////////////////////////////////////
typedef struct global_ansprite_s {
    ansprite_t *(*create)(animation_t **animations);
    void (*destroy)(ansprite_t *ansprite);
    void (*move)(ansprite_t *ansprite, vec2f offset);
    void (*rotate)(ansprite_t *ansprite, float angle);
    void (*scale)(ansprite_t *ansprite, vec2f factors);
    global_ansprite_get_t get;
    global_ansprite_set_t set;
    void (*draw)(ansprite_t *ansprite);
} global_ansprite_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Global instance of the `global_ansprite_t` structure.
///
/// This variable is an instance of the `global_ansprite_t` structure and is
/// intended to be used as a global accessor to `ansprite_t` functionality.
///
///////////////////////////////////////////////////////////////////////////////
extern global_ansprite_t Sprite;

#endif /* !CSFML_H_ */
