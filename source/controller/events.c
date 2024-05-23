/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** events
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
void parse_events(sfEvent evt)
{
    if (evt.type == sfEvtClosed)
        sfRenderWindow_close(Win.self);
    if (evt.type == sfEvtKeyPressed || evt.type == sfEvtKeyReleased)
        parse_key_input(evt.key);
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyNumpad1) {
        Player.num_shoot = 0;
        Player.weapon--;
    }
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyNumpad2) {
        Player.num_shoot = 0;
        Player.weapon++;
    }
    if (evt.type == sfEvtKeyPressed && evt.key.code == sfKeyJ)
        sign_tuto();
}
