/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** shots
*/

#ifndef SHOTS_H_
    #define SHOTS_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg/dependencies.h"
    #include "rpg/types.h"
    #include "rpg/libmy.h"

typedef struct shot_s {
    vec2f start;
    vec2f end;
    float lerp;
    float speed;
    u8 shooterId;
} shot_t;

#endif /* !SHOTS_H_ */
