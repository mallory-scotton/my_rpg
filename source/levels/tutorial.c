/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-mallory.scotton
** File description:
** tutorial
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
static const cstring_t LEVELS[7] = {
    "tutorial/01",
    "tutorial/02",
    "tutorial/03",
    "tutorial/04",
    "tutorial/05",
    "tutorial/06",
    "tutorial/07"
};

///////////////////////////////////////////////////////////////////////////////
void level_tutorial_actors(uint_t level)
{
    if (level == 2)
        entity_create(Assets.creatures[CREATURE_ELITE_FOX],
            V2F(0.0f, -225.0f));
    if (level == 3)
        spawn_interactable(INTERACTABLE_PNJ, V2F(50.0f, -150.0f), 8, &switalk);
    if (level == 4)
        entity_create(Assets.creatures[CREATURE_DUCK],
            V2F(0.0f, -225.0f));
    if (level == 4)
        spawn_interactable(INTERACTABLE_PNJ, V2F(-50.0f, -100.0f), 8,
            &switalk);
    if (level == 5 || level == 6)
        use_spawner(3U);
    if (level == 7)
        entity_create(Assets.creatures[CREATURE_SIGN_BOSS],
            V2F(0.0f, -200.0f));
}

///////////////////////////////////////////////////////////////////////////////
static void prepare_tutorial_level(sfMusic *music)
{
    end_music();
    sfMusic_setVolume(music, clampf(Setting.master *
        (Setting.music / 100.0f) * 0.1f, 0.0f, 100.0f));
    sfMusic_play(music);
    Player.ref->health -= 1;
    Player.ref->charges = 4;
}

///////////////////////////////////////////////////////////////////////////////
bool_t level_tutorial(void)
{
    uint_t level = Engine.level;
    sfMusic *music = find_music("i-m-hungry");

    if (level == 8) {
        Engine.level = 0;
        save_save(Engine.saveId);
    }
    if (level < 1 || level > 7 || !level_load(LEVELS[level - 1]))
        return (false);
    if (level == 1)
        prepare_tutorial_level(music);
    if (level != 1)
        level_tutorial_actors(level);
    return (true);
}
