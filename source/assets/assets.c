/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** assets
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

global_assets_t *Assets;

static void assets_init_assets(void)
{
    Assets->assets->fontAtlas = sfTexture_createFromFile(FONT_PATH, NULL);
    Assets->assets->cover = sfTexture_createFromFile(COVER_PATH, NULL);
    Assets->assets->logo = sfTexture_createFromFile(LOGO_PATH, NULL);
    Assets->assets->selection = sfTexture_createFromFile(SELECTION_PATH, NULL);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the assets.
///
/// This function initializes the global assets structure. It counts the number
/// of zones in the assets directory and allocates memory for the zones.
///
/// \return The status of the initialization (success or fail).
///
///////////////////////////////////////////////////////////////////////////////
status assets_init(void)
{
    RETURN(!EQ2(Assets, malloc(sizeof(global_assets_t))), fail);
    Assets->zoneCount = dircount(ZONE_PATH);
    DOIF(Assets->zoneCount == 0 || Assets->zoneCount > MAX_ZONE, FREE(Assets));
    RETURN(Assets->zoneCount == 0 || Assets->zoneCount > MAX_ZONE, fail);
    Assets->zones = malloc(sizeof(zones_t *) * Assets->zoneCount);
    Assets->assets = malloc(sizeof(global_assets_assets_t));
    assets_init_assets();
    if (Assets->zones == NULL) {
        FREE(Assets);
        return (fail);
    }
    return (zones_init());
}

static void assets_destroy_assets(void)
{
    DOIF(Assets->assets->fontAtlas, sfTexture_destroy(
        Assets->assets->fontAtlas));
    DOIF(Assets->assets->cover, sfTexture_destroy(Assets->assets->cover));
    DOIF(Assets->assets->logo, sfTexture_destroy(Assets->assets->logo));
    DOIF(Assets->assets->selection,
        sfTexture_destroy(Assets->assets->selection));
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the assets.
///
/// This function destroys the global assets structure. It iterates through
/// each zone and calls the destroy function for zones.
///
/// \return The status of the destruction (success or fail).
///
///////////////////////////////////////////////////////////////////////////////
status assets_destroy(void)
{
    RETURN(Assets == NULL, success);
    if (Assets->zones != NULL) {
        for (uchar i = 0; i < Assets->zoneCount; i++)
            zone_destroy(Assets->zones[i]);
        FREE(Assets->zones);
    }
    assets_destroy_assets();
    FREE(Assets);
    return (success);
}
