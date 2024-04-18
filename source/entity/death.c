/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** death
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"


void termination(entity_t *evil)
{
    if (evil->actor->done && evil->actor->draw){
        evil->actor->draw = !evil->actor->draw;
    }
}

///////////////////////////////////////////////////////////////////////////////
void health_examination(entity_t *evil)
{
    if (evil->health <= 0 && !evil->dead){
        evil->dead = !evil->dead;
        actor_set_anim(evil->actor, "death");
    }
    if (evil->dead)
        termination(evil);
}
