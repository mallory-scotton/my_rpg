/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** animation
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
void use_competence(void)
{
    return;
}

///////////////////////////////////////////////////////////////////////////////
void player_movement(void)
{
    Player.velocity = (v2f_t){0.0f, 0.0f};
    if (UP && !DANCE)
        Player.velocity.y += -SPEED;
    if (DOWN && !DANCE)
        Player.velocity.y += SPEED;
    if (LEFT && !DANCE)
        Player.velocity.x += -SPEED;
    if (RIGHT && !DANCE)
        Player.velocity.x += SPEED;
    get_last_input();
    Player.velocity = normalize2f(Player.velocity);
    Player.velocity.x *= Time.deltaTime / 15;
    Player.velocity.y *= Time.deltaTime / 15;
    if (!DASH && !DANCE)
        actor_set_anim(Player.ref, (Player.velocity.x != 0.0f ||
            Player.velocity.y != 0.0f) ? "walk" : "idle");
    if (DANCE)
        actor_set_anim(Player.ref, "dance");
    dash_movement();
}

///////////////////////////////////////////////////////////////////////////////
static void dash_animation(void)
{
    v2f_t velocity = Player.velocity;

    actor_set_anim(Player.ref, "dash");
    if (!Player.ref->done) {
        if (UP || Player.last_velocity.y < 0.0f)
            velocity.y += -SPEED;
        if (DOWN || Player.last_velocity.y > 0.0f)
            velocity.y += SPEED;
        if (LEFT || Player.last_velocity.x < 0.0f)
            velocity.x += -SPEED;
        if (RIGHT || Player.last_velocity.x > 0.0f)
            velocity.x += SPEED;
        velocity = normalize2f(velocity);
        velocity.x *= Time.deltaTime / 10;
        velocity.y *= Time.deltaTime / 10;
        actor_move(Player.ref, velocity);
        camera_move();
    }
}

///////////////////////////////////////////////////////////////////////////////
void dash_movement(void)
{
    v2f_t cr = PX_TO_MAPF(sfMouse_getPositionRenderWindow(Win.self));

    if (DASH && !DANCE)
        dash_animation();
    if (Player.ref->done && !DANCE && DASH) {
        actor_set_anim(Player.ref, (Player.velocity.x != 0.0f ||
            Player.velocity.y != 0.0f) ? "walk" : "idle");
        Keys.dash.pressed = false;
    }
    actor_move(Player.ref, Player.velocity);
    camera_move();
    Player.ref->scale.x = Player.ref->position.x > cr.x ? -1.0f : 1.0f;
}
