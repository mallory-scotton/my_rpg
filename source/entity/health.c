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

///////////////////////////////////////////////////////////////////////////////
/// \brief Once animation is done, stop drawing.
///
/// \param evil         taking damage.
///
///////////////////////////////////////////////////////////////////////////////
static void termination(entity_t *evil)
{
    if (!evil->actor->done || !evil->actor->draw)
        return;
    if (evil->is_dammaged){
        evil->is_dammaged = !evil->is_dammaged;
        evil->invincible = !evil->invincible;
    } else
        evil->actor->draw = !evil->actor->draw;
}

///////////////////////////////////////////////////////////////////////////////
void health_examination(entity_t *evil)
{
    if (evil->is_dammaged)
        actor_set_anim(evil->actor, "damage");
    if (evil->health <= 0 && !evil->dead && !evil->is_dammaged){
        evil->dead = !evil->dead;
        if (actor_set_sheet(evil->actor, "death"))
            evil->actor->position.x +=
            (evil->actor->self->sheets[evil->actor->sheetId]->image->mask.width
            / 4) * ((evil->actor->scale.x) < 0 ? 1 : -1);
        actor_set_anim(evil->actor, "death");
    }
    if (evil->dead || evil->is_dammaged)
        termination(evil);
}
