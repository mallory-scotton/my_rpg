/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-mallory.scotton
** File description:
** weapons
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
bool_t init_assets_weapons(void)
{
    Assets.weapons = add_image(DIR_WEAPONS"/weapons.png", true, V2U(8 * 5, 3),
        "WEAPONS");
    if (Assets.weapons == NULL)
        return (false);
    return (true);
}
