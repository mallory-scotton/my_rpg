/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** main
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

ansprite_t *TEST_SPRITE(prop_t *prop)
{
    animation_t **a = malloc(sizeof(animation_t *) * 2);
    ansprite_t *s;

    a[0] = malloc(sizeof(animation_t));
    if (prop->animated)
    {
        a[0]->frameSize = prop->anim.frameSize;
        a[0]->gridSize = VEC2U(prop->anim.gridWidth, prop->anim.gridHeight);
        a[0]->maxFrame = prop->anim.gridWidth * prop->anim.gridHeight;
    }
    else
    {
        a[0]->frameSize = prop->textureSize;
        a[0]->gridSize = VEC2U(1, 1);
        a[0]->maxFrame = 1;
    }
    a[0]->name = my_strdup("default");
    a[0]->texture = prop->text;
    a[1] = NULL;

    s = Sprite.create(a);
    s->frameRate = PROP_FRAME_PER_MS;
    Sprite.set.currentAnimation(s, "default");
    return (s);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Entry of the program
///
/// \param argc     The number of arguments
/// \param argv     The list of arguments
///
/// \return The program exit status
///
///////////////////////////////////////////////////////////////////////////////
int main(int argc, warray argv)
{
    sfEvent evt;
    int i = 0;
    int cat = 0;
    float factor = 0.0f;
    sfMusic *music = sfMusic_createFromFile("assets/main-theme.ogg");

    if (!music)
        printf("Cannot play music");

    sfMusic_setVolume(music, 5);
    sfMusic_setLoop(music, true);
    sfMusic_play(music);

    window_init();
    time_init();
    settings_init();
    assets_init();
    zone_load("biome1");

    sfSprite *cursor = sfSprite_create();
    sfTexture *CursorTexture = sfTexture_createFromFile("assets/ui/cursor.png", NULL);
    recti cursorMask = {0, 0, 20, 20};
    sfSprite_setTexture(cursor, CursorTexture, false);
    sfSprite_setTextureRect(cursor, cursorMask);
    sfSprite_setPosition(cursor, VEC2(0, 0));
    sfSprite_setOrigin(cursor, VEC2(9, 6));
    sfSprite_rotate(cursor, -35);
    sfSprite_scale(cursor, VEC2(0.6f, 0.6f));
    sfRenderWindow_setMouseCursorVisible(Win->self, false);
    sfRenderWindow_setMouseCursorGrabbed(Win->self, true);

    ansprite_t *s = TEST_SPRITE(Assets->zones[0]->cats[cat]->props[CLAMP(i, 0, Assets->zones[0]->cats[cat]->propCount - 1)]);
    while (sfRenderWindow_isOpen(Win->self))
    {
        while (sfRenderWindow_pollEvent(Win->self, &evt))
        {
            if (evt.type == sfEvtClosed)
                sfRenderWindow_close(Win->self);
            if (evt.type == sfEvtKeyPressed)
            {
                switch (evt.key.code)
                {
                case ALT_UP:
                    sfView_move(Win->view, VEC2(0, -2));
                    break;
                case ALT_DOWN:
                    sfView_move(Win->view, VEC2(0, 2));
                    break;
                case ALT_LEFT:
                    sfView_move(Win->view, VEC2(-2, 0));
                    break;
                case ALT_RIGHT:
                    sfView_move(Win->view, VEC2(2, 0));
                    break;
                case sfKeyA:
                    factor -= 0.1f;
                    break;
                case sfKeyZ:
                    factor += 0.1f;
                    break;
                case sfKeyAdd:
                    Sprite.destroy(s);
                    i++;
                    s = TEST_SPRITE(Assets->zones[0]->cats[cat]->props[CLAMP(i, 0, Assets->zones[0]->cats[cat]->propCount - 1)]);
                    break;
                case sfKeySubtract:
                    Sprite.destroy(s);
                    i--;
                    s = TEST_SPRITE(Assets->zones[0]->cats[cat]->props[CLAMP(i, 0, Assets->zones[0]->cats[cat]->propCount - 1)]);
                    break;
                default:
                    break;
                }
                sfRenderWindow_setView(Win->self, Win->view);
            }
            if (evt.type == sfEvtMouseButtonPressed)
            {
                cursorMask.top = 20;
                sfSprite_setTextureRect(cursor, cursorMask);
            }
            if (evt.type == sfEvtMouseButtonReleased)
            {
                cursorMask.top = 0;
                sfSprite_setTextureRect(cursor, cursorMask);
            }
            if (evt.type == sfEvtResized)
                window_update(evt.size);
        }
        sfVector2i mousePos = sfMouse_getPositionRenderWindow(Win->self);
        sfVector2f viewMousePos = sfRenderWindow_mapPixelToCoords(Win->self, mousePos, Win->view);
        sfSprite_setPosition(cursor, viewMousePos);

        sfRenderWindow_clear(Win->self, sfWhite);
        time_update();

        scene_main_menu_draw();

        //Sprite.draw(s);

        sfRenderWindow_drawSprite(Win->self, cursor, NULL);

        sfRenderWindow_display(Win->self);
    }
    zone_unload("biome1");
    window_destroy();
    time_destroy();
    settings_destroy();
    assets_destroy();
    return (0);
}
