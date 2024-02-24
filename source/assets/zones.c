/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** zones
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes a zone with the specified name.
///
/// \param zone Pointer to the zones_t structure to be initialized.
/// \param name The name of the zone.
///
/// \return The status of the initialization process (success or failure).
///
///////////////////////////////////////////////////////////////////////////////
static status zone_init(zones_t *zone, string name)
{
    string path = my_strdcat(ZONE_PATH, "/", name);
    warray content = dircontent(path);

    DOIF(content == NULL, FREE(path));
    RETURN(content == NULL, fail);
    zone->name = name;
    zone->loaded = false;
    zone->catCount = my_walen(content);
    zone->cats = malloc(sizeof(category_t *) * zone->catCount);
    for (uchar i = 0; i < zone->catCount; i++) {
        zone->cats[i] = malloc(sizeof(category_t));
        category_init(zone->cats[i], path, content[i]);
    }
    FREE(path);
    FREE(content);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes the zones module.
///
/// \return Status of the operation (success/fail).
///
///////////////////////////////////////////////////////////////////////////////
status zones_init(void)
{
    warray content = dircontent(ZONE_PATH);

    for (uchar i = 0; i < Assets->zoneCount; i++) {
        Assets->zones[i] = malloc(sizeof(zones_t));
        zone_init(Assets->zones[i], content[i]);
    }
    FREE(content);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys a zone structure.
///
/// \param zone Pointer to the zone structure to be destroyed.
///
/// \return Status of the operation (success/fail).
///
///////////////////////////////////////////////////////////////////////////////
status zone_destroy(zones_t *zone)
{
    RETURN(zone == NULL, success);
    if (zone->cats != NULL) {
        for (u8 i = 0; i < zone->catCount; i++)
            category_destroy(zone->cats[i]);
        FREE(zone->cats);
    }
    FREE(zone->name);
    FREE(zone);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Unloads a zone and its categories.
///
/// \param name The name of the zone to be unloaded.
///
/// \return The status of the unloading process (success or failure).
///
/// This function unloads a zone and its associated categories. It iterates
/// through the zones in the global assets and unloads the specified zone.
///
///////////////////////////////////////////////////////////////////////////////
status zone_unload(cstring name)
{
    status result = success;

    for (u8 i = 0; i < Assets->zoneCount; i++) {
        if (!CMP(Assets->zones[i]->name, name))
            continue;
        for (u8 y = 0; y < Assets->zones[i]->catCount; y++)
            DOIF(!category_unload(Assets->zones[i]->cats[y]), EQ2(result, 0));
        DOIF(result, EQ2(Assets->zones[i]->loaded, false));
        break;
    }
    return (result);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Loads a zone and its categories.
///
/// \param name The name of the zone to be loaded.
///
/// \return The status of the loading process (success or failure).
///
/// This function loads a zone and its associated categories. It iterates
/// through the zones in the global assets and loads the specified zone.
///
///////////////////////////////////////////////////////////////////////////////
status zone_load(cstring name)
{
    status result = success;

    for (u8 i = 0; i < Assets->zoneCount; i++) {
        if (!CMP(Assets->zones[i]->name, name) && Assets->zones[i]->loaded) {
            zone_unload(Assets->zones[i]->name);
            continue;
        }
        for (u8 y = 0; y < Assets->zones[i]->catCount; y++)
            DOIF(!category_load(Assets->zones[i]->cats[y]), EQ2(result, 0));
        DOIF(result, EQ2(Assets->zones[i]->loaded, true));
        break;
    }
    return (result);
}
