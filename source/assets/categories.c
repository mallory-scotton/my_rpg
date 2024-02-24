/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** categories
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

static category_type_t category_get_type(string name)
{
    RETURN(CMP(name, TRAPS_DIR), category_traps);
    RETURN(CMP(name, DESTRUCTIBLES_DIR), category_destructibles);
    RETURN(CMP(name, VFX_DIR), category_vfx);
    return (category_default);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes a category with the specified name and path.
///
/// \param cat          Pointer to the category_t structure to be initialized.
/// \param parentPath   The path of the zones.
/// \param name         The name of the category.
///
/// \return The status of the initialization process (success or failure).
///
///////////////////////////////////////////////////////////////////////////////
status category_init(category_t *cat, cstring parentPath, string name)
{
    string path = my_strdcat(parentPath, "/", name);
    warray content = dircontent(path);

    cat->name = name;
    cat->propCount = 0;
    DOIF(content == NULL, FREE(path));
    RETURN(content == NULL, fail);
    cat->propCount = (u8)my_walen(content);
    cat->type = category_get_type(name);
    cat->props = malloc(sizeof(prop_t *) * cat->propCount);
    for (u8 i = 0; i < cat->propCount; i++) {
        cat->props[i] = malloc(sizeof(prop_t));
        prop_init(cat->props[i], path, content[i]);
    }
    FREE(path);
    FREE(content);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys a category and its associated props.
///
/// \param cat Pointer to the category_t structure to be destroyed.
///
/// \return The status of the destruction process (success or failure).
///
///////////////////////////////////////////////////////////////////////////////
status category_destroy(category_t *cat)
{
    RETURN(cat == NULL, success);
    if (cat->propCount > 0) {
        for (u8 i = 0; i < cat->propCount; i++)
            prop_destroy(cat->props[i]);
        FREE(cat->props);
    }
    FREE(cat->name);
    FREE(cat);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Unloads a category and its associated props.
///
/// \param cat Pointer to the category_t structure to be unloaded.
///
/// \return The status of the unloading process (success or failure).
///
/// This function unloads a category and its associated props.
///
///////////////////////////////////////////////////////////////////////////////
status category_unload(category_t *cat)
{
    status result = success;

    RETURN(cat == NULL, success);
    for (u8 i = 0; i < cat->propCount; i++)
        DOIF(!prop_unload(cat->props[i]), EQ2(result, fail));
    return (result);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Loads a category and its associated props.
///
/// \param cat Pointer to the category_t structure to be loaded.
///
/// \return The status of the loading process (success or failure).
///
/// This function loads a category and its associated props.
///
///////////////////////////////////////////////////////////////////////////////
status category_load(category_t *cat)
{
    status result = success;

    RETURN(cat == NULL, success);
    for (u8 i = 0; i < cat->propCount; i++)
        DOIF(!prop_load(cat->props[i]), EQ2(result, fail));
    return (result);
}
