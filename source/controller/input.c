/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** input
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
void get_last_input(void)
{
    v2f_t vel = Player.last_velocity;

    if ((UP || DOWN) && !RIGHT && !LEFT && !DASH)
        vel.x = 0.0f;
    if ((RIGHT || LEFT) && !UP && !DOWN && !DASH)
        vel.y = 0.0f;
    vel.x = Player.velocity.x != 0.0f ? Player.velocity.x : vel.x;
    vel.y = Player.velocity.y != 0.0f ? Player.velocity.y : vel.y;
    Player.last_velocity = vel;
}

///////////////////////////////////////////////////////////////////////////////
static void parse_key_dance(sfKeyEvent evt, bool_t pressed, bool_t released)
{
    if (evt.code == Setting.dance.code && !pressed && !DASH) {
        DANCE = released && !DANCE ? true : false;
        if (DANCE) {
            set_asset_music_status(sfPlaying);
            sfMusic_play(find_music("blingblangblang"));
            sfMusic_setLoop(find_music("blingblangblang"), sfTrue);
        } else {
            set_asset_music_status(sfPaused);
            sfMusic_pause(find_music("blingblangblang"));
        }
    }
}

///////////////////////////////////////////////////////////////////////////////
static void parse_movement_key_input(sfKeyEvent evt, bool_t pressed,
    bool_t released)
{
    if (evt.code == Setting.up.code || evt.code == ALT_UP)
        UP = pressed;
    if (evt.code == Setting.down.code || evt.code == ALT_DOWN)
        DOWN = pressed;
    if (evt.code == Setting.right.code || evt.code == ALT_RIGHT)
        RIGHT = pressed;
    if (evt.code == Setting.left.code || evt.code == ALT_LEFT)
        LEFT = pressed;
    if (evt.code == Setting.dash.code && pressed && !DANCE)
        DASH = pressed;
    if (evt.code == Setting.heal.code && Engine.level > 2)
        HEAL = pressed;
    parse_key_dance(evt, pressed, released);
}

///////////////////////////////////////////////////////////////////////////////
void parse_key_input(sfKeyEvent evt)
{
    bool_t pressed = (evt.type == sfEvtKeyPressed);
    bool_t released = (evt.type == sfEvtKeyReleased);

    if (Setting.talk != NO_TALK && released && evt.code ==
        Setting.dash.code) {
        Setting.talk = NO_TALK;
        Player.blocked = false;
    }
    if (Setting.talk == INVENTORY && released && evt.code == Setting.heal.code)
        Engine.scene = SCENE_INVENTORY;
    if (Player.blocked)
        return;
    parse_movement_key_input(evt, pressed, released);
}
