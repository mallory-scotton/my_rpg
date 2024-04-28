/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** main_menu
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

static void text(cstring str, vec2f pos, float scale, sfColor color)
{
    sfSprite *txt = sfSprite_create();
    recti mask = {0, 0, 20, 20};
    uint index = 0;
    uint size = 16 * scale;

    sfSprite_setTexture(txt, Assets->assets->fontAtlas, sfFalse);
    sfSprite_setColor(txt, color);
    sfSprite_setScale(txt, VEC2(scale, scale));
    for (ulong i = 0; str[i]; i++) {
        if (!my_isalnum(str[i]) && str[i] != '.' && str[i] != '!')
            continue;
        DOIF(my_isdigit(str[i]), EQ2(index, 52 + (str[i] - '0')));
        DOIF(str[i] >= 'a' && str[i] <= 'z', EQ2(index, 26 + (str[i] - 'a')));
        DOIF(str[i] >= 'A' && str[i] <= 'Z', EQ2(index, (str[i] - 'A')));
        DOIF(str[i] == '.', EQ2(index, 62));
        DOIF(str[i] == '!', EQ2(index, 63));
        sfSprite_setPosition(txt, VEC2(pos.x + (size - 2 * scale) * i, pos.y +
            (my_strchr(FONT_LOWERED_CHAR, str[i]) ? 1 : 0)));
        mask.top = (index / 8) * 20;
        mask.left = (index % 8) * 20;
        sfSprite_setTextureRect(txt, mask);
        sfRenderWindow_drawSprite(Win->self, txt, NULL);
    }
    sfSprite_destroy(txt);
}

static void draw_background(void)
{
    sfSprite *back = sfSprite_create();
    vec2f vSize = sfView_getSize(Win->view);

    sfSprite_setPosition(back,
        sfRenderWindow_mapPixelToCoords(Win->self, VEC2I(0, 0), Win->view));
    sfSprite_setTexture(back, Assets->assets->cover, false);
    sfSprite_setScale(back, VEC2(vSize.x / 1920, vSize.y / 1080));
    sfRenderWindow_drawSprite(Win->self, back, NULL);
    sfSprite_destroy(back);
}

static sfColor get_color(vec2i mouse, int y)
{
    sfBool pressed = sfMouse_isButtonPressed(sfMouseLeft);
    sfSprite *select;
    int oy = y;

    y = sfRenderWindow_mapCoordsToPixel(Win->self, VEC2(0, y), Win->view).y;
    RETURN(mouse.x > 750 || mouse.x < 250, sfWhite);
    RETURN(!(mouse.y >= (y - 25) && mouse.y <= (y + 60)), sfWhite);
    select = sfSprite_create();
    sfSprite_setTexture(select, Assets->assets->selection, false);
    sfSprite_setPosition(select, VEC2(32, oy - 8));
    sfRenderWindow_drawSprite(Win->self, select, NULL);
    if (pressed && oy == 200)   sfRenderWindow_close(Win->self);
    return (sfColor_fromRGB(243, 199, 77));
}

static void draw_levitating_logo(void)
{
    sfSprite *logo = sfSprite_create();
    float offsetY = 5.0f * sin((float)(Time->currentTime) / 1000.0f);

    sfSprite_setTexture(logo, Assets->assets->logo, false);
    sfSprite_setScale(logo, VEC2(0.15f, 0.15f));
    sfSprite_setColor(logo, sfColor_fromRGBA(0, 0, 0, 128));
    sfSprite_setPosition(logo, VEC2(0, 30 + offsetY));
    sfRenderWindow_drawSprite(Win->self, logo, NULL);
    sfSprite_setColor(logo, sfColor_fromRGB(255, 255, 255));
    sfSprite_setPosition(logo, VEC2(0, 20 + offsetY));
    sfRenderWindow_drawSprite(Win->self, logo, NULL);
    sfSprite_destroy(logo);
}

void scene_main_menu_draw(void)
{
    vec2i mouse = sfMouse_getPositionRenderWindow(Win->self);

    draw_background();
    draw_levitating_logo();
    text("Play", VEC2(110, 125), 0.45f, get_color(mouse, 125));
    text("Settings", VEC2(97, 150), 0.45f, get_color(mouse, 150));
    text("Level Editor", VEC2(87, 175), 0.45f, get_color(mouse, 175));
    text("Quit", VEC2(110, 200), 0.45f, get_color(mouse, 200));
}
