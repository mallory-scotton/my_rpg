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
    Assets->fontAtlas = sfTexture_createFromFile(FONT_PATH, NULL);
    if (Assets->zones == NULL) {
        FREE(Assets);
        return (fail);
    }
    return (zones_init());
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
    DOIF(Assets->fontAtlas, sfTexture_destroy(Assets->fontAtlas));
    FREE(Assets);
    return (success);
}
