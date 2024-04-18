/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** bullet_animation
*/

#include "rpg.h"

static sfCircleShape *create_circle(void)
{
    sfCircleShape *circle = sfCircleShape_create();
    sfVector2f origin;

    sfCircleShape_setRadius(circle, 200);
    origin = (sfVector2f){sfCircleShape_getRadius(circle),
        sfCircleShape_getRadius(circle)};
    sfCircleShape_setOutlineThickness(circle, 2.0f);
    sfCircleShape_setOutlineColor(circle, sfRed);
    sfCircleShape_setFillColor(circle, sfTransparent);
    sfCircleShape_setPosition(circle,
        (sfVector2f){Player.ref->position.x, Player.ref->position.y});
    sfCircleShape_setOrigin(circle, origin);
    return circle;
}

static float rotation(bullet_t *bullet)
{
    float_t my_x = bullet->destination.x - bullet->origin.x;
    float_t my_y = bullet->destination.y - bullet->origin.y;
    float_t rotationDegrees = atan2(my_y, my_x) * (180.f / M_PI);

    return rotationDegrees;
}

static sfSprite *init_bullet_sprite(bullet_t *bullet)
{
    sfSprite *bullet_sprite = sfSprite_create();
    recti_t rect = (sfIntRect){0, 0, 26, 26};
    sfTexture *texture =
        sfTexture_createFromFile("assets/bullets/BulletShotgun.png", NULL);

    sfSprite_setTexture(bullet_sprite, texture, sfTrue);
    sfSprite_setTextureRect(bullet_sprite, rect);
    sfSprite_setPosition(bullet_sprite, (v2f_t){bullet->position.x,
        bullet->position.y});
    sfSprite_setOrigin(bullet_sprite, (v2f_t){rect.width / 2,
        rect.height / 2});
    sfSprite_setRotation(bullet_sprite, rotation(bullet));
    return bullet_sprite;
}

static void init_bullet(bullet_t *new, uint_t sender)
{
    v2f_t cr = PX_TO_MAPF(sfMouse_getPositionRenderWindow(Win.self));

    new->sender = sender;
    new->origin = (v2f_t){Player.ref->position.x, Player.ref->position.y};
    new->position = (v2f_t){Player.ref->position.x, Player.ref->position.y};
    new->destination = endpoint2f(new->origin, cr, 100.0f);
    new->sprite = init_bullet_sprite(new);
    new->destroyed = 0;
    new->area = create_circle();
}

bullet_t *bullet_creation(uint_t sender)
{
    bullet_t *new = (bullet_t *)malloc(sizeof(bullet_t));

    init_bullet(new, sender);
    Bullet_List.count++;
    Bullet_List.array = REALLOC(Bullet_List.array, sizeof(bullet_t *),
        Bullet_List.count);
    Bullet_List.array[Bullet_List.count - 1] = new;
    return (new);
}
