/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** create
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"


///////////////////////////////////////////////////////////////////////////////
static void init_entity_stat_block(entity_t *new, creature_t *creature)
{
    new->actor->health = CREATURE_COUNT < creature->id ? 100 :
        Stats[creature->id].health;
    new->speed = CREATURE_COUNT < creature->id ? 0.6 :
        Stats[creature->id].speed;
    new->attack_radius = CREATURE_COUNT < creature->id ? 50 :
        Stats[creature->id].attack_radius;
    new->insight = CREATURE_COUNT < creature->id ? 100 :
        Stats[creature->id].insight;
    new->attack_types = CREATURE_COUNT < creature->id ? 1 :
        Stats[creature->id].attack_types;
    new->dizzy = CREATURE_COUNT < creature->id ? 0 :
        Stats[creature->id].dizzy;
    new->firerate = CREATURE_COUNT < creature->id ? 1000 :
        Stats[creature->id].firerate;
    new->ball_count = CREATURE_COUNT < creature->id ? 1 :
        Stats[creature->id].ball_count;
    new->collision = (float)(creature->sheets[new->actor->sheetId]->
        image->mask.height) / 2;
}

///////////////////////////////////////////////////////////////////////////////
static void init_entity(entity_t *new, creature_t *creature, v2f_t position)
{
    new->actor = actor_create(creature, position);
    init_entity_stat_block(new, creature);
    new->weapon = Stats[creature->id].weapon;
    new->last_action = Time.currentTime;
    new->has_spawn = 0;
    new->is_attack = 0;
    new->status = Patrol;
    new->can_attack = false;
    new->attack_started = false;
    new->cooldown = Time.currentTime;
    new->movement = Time.currentTime;
    new->timebomb = Time.currentTime;
    new->wanted_position = position;
    new->curr_phase = 0;
    new->bounce = 0;
    new->vector = V2F(5.0f, 0.0f);
    new->c4_pos = V2F1(0.0f);
}

///////////////////////////////////////////////////////////////////////////////
entity_t *entity_create(creature_t *creature, v2f_t position)
{
    entity_t *new = (entity_t *)malloc(sizeof(entity_t));

    Entities.count++;
    Entities.array = REALLOC(Entities.array, sizeof(entity_t *),
        Entities.count);
    Entities.array[Entities.count - 1] = new;
    init_entity(new, creature, position);
    return (new);
}

///////////////////////////////////////////////////////////////////////////////
void remove_entity(entity_t *ent)
{
    entity_t **tmp = NULL;
    uint_t j = 0;

    if (ent == NULL)
        return;
    if (ent->actor != NULL)
        actor_destroy(ent->actor);
    tmp = malloc(sizeof(entity_t *) * (Entities.count - 1));
    for (int i = 0; i < Entities.count; i++) {
        if (Entities.array[i] == ent)
            continue;
        tmp[j] = Entities.array[i];
        j++;
    }
    Entities.count--;
    FREE(Entities.array);
    Entities.array = tmp;
    FREE(ent);
}
