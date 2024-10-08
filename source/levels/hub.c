/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-mallory.scotton
** File description:
** hub
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
static void spawn_map_actors(void)
{
    sfMusic *music = find_music("by-the-campfire");

    end_music();
    for (uint_t i = 0; i < Pool.propCount; i++)
        if (CMP(Pool.props[i]->self->name, "torch"))
            effect("firethrower", add2f(Pool.props[i]->position, V2F(0.0f,
                -11.0f)), false);
    sfMusic_setVolume(music, clampf(Setting.master *
        (Setting.music / 100.0f) * 0.75f, 0.0f, 100.0f));
    sfMusic_play(music);
    spawn_interactable(INTERACTABLE_PNJ, V2F(155.0f, -160.0f), 4, &switalk);
    spawn_interactable(INTERACTABLE_PNJ, V2F(475.0f, -15.0f), 3, &switalk);
    spawn_interactable(INTERACTABLE_PNJ, V2F(-210.0f, -150.0f), 2, &switalk);
    spawn_interactable(INTERACTABLE_PNJ, V2F(-215.0f, 100.0f), 1, &switalk);
    Player.ref->health = Assets.axolotl[Player.ref->variantId]->maxHealth;
    Player.ref->shield = Assets.axolotl[Player.ref->variantId]->shields;
}

///////////////////////////////////////////////////////////////////////////////
static void spawn_axolotl(void)
{
    interactable_t *in;

    for (uint_t i = 0; i < AXO_COUNT; i++) {
        if (Assets.axolotl[i]->grown == AXO_NO ||
            Assets.axolotl[i]->grown == AXO_ADULT)
            continue;
        in = spawn_interactable(INTERACTABLE_EGG, rand_pos(V2F(460.0f, -190.0f)
            , 0, 50), i - 1, &get_baby);
        if (Assets.axolotl[i]->grown == AXO_BABY)
            actor_set_sheet(in->actor, "babies");
        if (Assets.axolotl[i]->grown == AXO_TEEN)
            actor_set_sheet(in->actor, "teenagers");
        actor_set_variant(in->actor, NULL, i);
        actor_set_anim(in->actor, "idle");
    }
}

///////////////////////////////////////////////////////////////////////////////
bool_t level_hub(void)
{
    if (Engine.level != 0 || !level_load("shared/hub"))
        return (false);
    save_save(Engine.saveId);
    spawn_map_actors();
    Player.weapon = Player.inventor[0];
    Player.inventor[1] = WEAPON_NO;
    Player.max_bullet = 0;
    Player.mag[1] = 0;
    Player.mag[0] = WEAPON_STATS[Player.weapon].ammoPerMag;
    Player.shaking = false;
    Player.ref->charges = 0;
    Player.blocked = false;
    spawn_axolotl();
    return (true);
}
