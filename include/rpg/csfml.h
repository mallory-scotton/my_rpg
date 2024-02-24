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

ansprite_t *ansprite_create(animation_t **animations);
void ansprite_destroy(ansprite_t *s);

void ansprite_set_position(ansprite_t *s, vec2f pos);
void ansprite_set_rotation(ansprite_t *s, float rot);
void ansprite_set_scale(ansprite_t *s, vec2f scale);
void ansprite_set_origin(ansprite_t *s, vec2f origin);

vec2f ansprite_get_position(const ansprite_t *s);
float ansprite_get_rotation(const ansprite_t *s);
vec2f ansprite_get_scale(const ansprite_t *s);
vec2f ansprite_get_origin(const ansprite_t *s);

void ansprite_move(ansprite_t *s, vec2f offset);
void ansprite_rotate(ansprite_t *s, float angle);
void ansprite_scale(ansprite_t *s, vec2f factors);

void ansprite_set_current_animation(ansprite_t *s, cstring name);
animation_t **ansprite_get_animations(const ansprite_t *s);
animation_t *ansprite_get_current_animation(const ansprite_t *s);

void ansprite_draw(ansprite_t *s);

typedef struct global_ansprite_get_s {
    vec2f (*position)(const ansprite_t *ansprite);
    float (*rotation)(const ansprite_t *ansprite);
    vec2f (*scale)(const ansprite_t *ansprite);
    vec2f (*origin)(const ansprite_t *ansprite);
    animation_t **(*animations)(const ansprite_t *ansprite);
    animation_t *(*currentAnimation)(const ansprite_t *ansprite);
} global_ansprite_get_t;

typedef struct global_ansprite_set_s {
    void (*position)(ansprite_t *ansprite, vec2f pos);
    void (*rotation)(ansprite_t *ansprite, float rot);
    void (*scale)(ansprite_t *ansprite, vec2f scale);
    void (*origin)(ansprite_t *ansprite, vec2f origin);
    void (*currentAnimation)(ansprite_t *ansprite, cstring name);
} global_ansprite_set_t;

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

extern global_ansprite_t Sprite;

#endif /* !CSFML_H_ */
