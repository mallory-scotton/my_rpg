/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** entity
*/

#ifndef ENTITY_H_
    #define ENTITY_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
typedef struct entity_s {
    actor_t *actor;
    uint_t *health;
    uint_t *behavior;
    ulong_t *last_action;
    bool_t has_spawn;
} entity_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief
///
///////////////////////////////////////////////////////////////////////////////
extern struct entity_list_s {
    entity_t **array;
    uint_t count;
} Entities;

entity_t *entity_creation(creature_t *creature);

#endif /* !ENTITY_H_ */
