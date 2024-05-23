/*
** EPITECH PROJECT, 2024
** myrpg
** File description:
** sign_tuto
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
void healing_tuto(void)
{
    sfSprite *sign = sfSprite_create();
    v2f_t scale = {Win.width / Win.viewWidth, Win.height / Win.viewHeight};

    draw_shadow();
    sfSprite_setTexture(sign, Assets.ui[UI_PNJ_SIGN]->self, false);
    sfSprite_setScale(sign, V2F1(0.75f));
    sfSprite_setOrigin(sign, V2F(64.5f, 115.0f));
    sfSprite_setPosition(sign, PX_TO_MAPF(V2F(Win.width / 4 - scale.x * 16.0f,
        Win.height)));
    sfRenderWindow_drawSprite(Win.self, sign, false);
    sfSprite_destroy(sign);
    draw_text("Sus Sign", PX_TO_MAPF(V2F(Win.width / 3 + scale.x * 16,
        Win.height / 5 * 3.5f)), 0.45f, sfWhite);
    draw_text(HEAL_LINE1, PX_TO_MAPF(V2F(Win.width / 3 + scale.x * 8,
        Win.height / 5 * 3.5f + 16.0f * scale.y)), 0.35f, sfWhite);
    draw_text(HEAL_LINE2, PX_TO_MAPF(V2F(Win.width / 3 + scale.x * 8,
        Win.height / 5 * 3.5f + 24.0f * scale.y)), 0.35f, sfWhite);
}

void dash_tuto(void)
{
    sfSprite *sign = sfSprite_create();
    v2f_t scale = {Win.width / Win.viewWidth, Win.height / Win.viewHeight};

    draw_shadow();
    sfSprite_setTexture(sign, Assets.ui[UI_PNJ_SIGN]->self, false);
    sfSprite_setScale(sign, V2F1(0.75f));
    sfSprite_setOrigin(sign, V2F(64.5f, 115.0f));
    sfSprite_setPosition(sign, PX_TO_MAPF(V2F(Win.width / 4 - scale.x * 16.0f,
        Win.height)));
    sfRenderWindow_drawSprite(Win.self, sign, false);
    sfSprite_destroy(sign);
    draw_text("Sus Sign", PX_TO_MAPF(V2F(Win.width / 3 + scale.x * 16,
        Win.height / 5 * 3.5f)), 0.45f, sfWhite);
    draw_text(DASH_LINE1, PX_TO_MAPF(V2F(Win.width / 3 + scale.x * 8,
        Win.height / 5 * 3.5f + 16.0f * scale.y)), 0.35f, sfWhite);
    draw_text(DASH_LINE2, PX_TO_MAPF(V2F(Win.width / 3 + scale.x * 8,
        Win.height / 5 * 3.5f + 24.0f * scale.y)), 0.35f, sfWhite);
}

///////////////////////////////////////////////////////////////////////////////
void sign_tuto(void)
{
    if (Engine.level == 3 && !Setting.healtuto)
        Setting.healtuto = true;
    else
        Setting.healtuto = false;
    if (Engine.level == 4 && !Setting.dashtuto)
        Setting.dashtuto = true;
    else
        Setting.dashtuto = false;
}
