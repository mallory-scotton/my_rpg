/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** create
*/

#include "rpg.h"

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
ansprite_t *ansprite_create(animation_t **animations)
{
    ansprite_t *s = malloc(sizeof(ansprite_t));

    RETURN(s == NULL, NULL);
    s->animations = animations;
    s->currentFrame = 0;
    s->currentAnimation = 0;
    s->start = 0;
    s->sprite = sfSprite_create();
    if (s->sprite == NULL) {
        FREE(s);
        return (NULL);
    }
    for (s->animationCount = 0; animations[s->animationCount];
        s->animationCount++);
    return (s);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys an `ansprite_t` structure.
///
/// \param s Pointer to the `ansprite_t` structure to be destroyed.
///
/// This function destroys an `ansprite_t` structure, freeing associated
/// resources.
///
///////////////////////////////////////////////////////////////////////////////
void ansprite_destroy(ansprite_t *s)
{
    RETURN(s == NULL, (void)0);
    DOIF(s->sprite != NULL, sfSprite_destroy(s->sprite));
    for (uint i = 0; i < s->animationCount; i++) {
        FREE(s->animations[i]->name);
        FREE(s->animations[i]);
    }
    FREE(s->animations);
    FREE(s);
}
