/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Workspace)
** File description:
** assets
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "moon.h"

///////////////////////////////////////////////////////////////////////////////
struct assets_s Assets = {
    NULL, 0,
    NULL, 0,
    NULL, 0,
    NULL, 0,
    NULL, 0,
    NULL, 0
};

///////////////////////////////////////////////////////////////////////////////
bool_t init_assets(void)
{
    if (!init_assets_creatures() ||
        !init_assets_musics() ||
        !init_assets_zones() ||
        !init_assets_vfx() ||
        !init_assets_weapons())
        return (false);
    sort_creatures();
    return (true);
}

///////////////////////////////////////////////////////////////////////////////
void destroy_assets(void)
{
    destroy_assets_musics();
    destroy_assets_zones();
    destroy_assets_vfx();
    destroy_assets_weapons();
}
