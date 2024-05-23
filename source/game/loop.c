/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** loop
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
static void check_shoot(void)
{
    v2f_t cr = PX_TO_MAPF(sfMouse_getPositionRenderWindow(Win.self));
    weapon_t stat = WEAPON_STATS[Player.weapon];
    uint_t mag = Player.weapon == Player.inventor[0] ? 0 : 1;

    if (Time.currentTime - Player.shoot_time < stat.firerate * 1000 || DANCE ||
        DASH || (Time.currentTime - Player.shoot_time <
        stat.reload_time * 1000 && Player.mag[mag] == 0) || (Player.weapon ==
        Player.inventor[1] && Player.max_bullet == 0))
        return;
    if (!((Time.currentTime - Player.shoot_time) < stat.reload_time * 1000) &&
        Player.mag[mag] == 0)
        Player.mag[mag] = mag == 1 && Player.max_bullet < stat.ammoPerMag ?
            Player.max_bullet : stat.ammoPerMag;
    if (!MPRESSED(Setting.shoot))
        return;
    Player.mag[mag]--;
    Player.max_bullet -= Player.weapon == Player.inventor[1] ? 1 : 0;
    Player.shoot_time = Time.currentTime;
    create_bullet(Player.ref, cr, Player.weapon);
}

///////////////////////////////////////////////////////////////////////////////
static void update(void)
{
    if (!Player.ref->damaged && !Player.ref->dead)
        player_movement();
    check_player_health();
    update_entity();
    update_collisions();
    update_shaking();
    check_shoot();
    cursor_focus();
    check_level_end();
}

///////////////////////////////////////////////////////////////////////////////
void game_loop(void)
{
    sfEvent evt;

    Engine.debug.propDrawn = 0;
    while (sfRenderWindow_pollEvent(Win.self, &evt)) {
        parse_events(evt);
        if (evt.type == sfEvtKeyReleased &&
            evt.key.code == Setting.inventory.code)
            Engine.scene = SCENE_INVENTORY;
        if (evt.type == sfEvtKeyReleased &&
            evt.key.code == Setting.pause.code)
            Engine.scene = SCENE_PAUSE;
        CLICK_REL = click_rel(evt);
    }
    update();
    draw();
    update_all_bullets();
    clear_entity_remove_queue();
}
