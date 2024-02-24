/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** props
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Validates the format of a prop name based on its fragments.
///
/// \param frag An array containing fragments of the prop name.
///
/// \return True if the prop name format is valid, false otherwise.
///
/// This function checks whether the fragments of a prop name follow the
/// expected format. It validates the category and prop type, ensures the
/// correct number of fragments, checks file extension, and verifies the
/// correctness of numerical values.
///
///////////////////////////////////////////////////////////////////////////////
static bool is_prop_name_valid(warray frag)
{
    ulong len = my_walen(frag);
    warray tmp = my_strsplit(frag[len - 1], '.');
    ulong extlen = my_walen(tmp);
    bool valid = true;

    DOIF(extlen != 2 || (!CMP(tmp[1], "png") && !CMP(tmp[1], "jpg")),
        EQ2(valid, 0));
    my_watroy(tmp);
    RETURN(valid == false, false);
    RETURN((frag[0][0] != 'A' && frag[0][0] != 'S') || frag[0][1], false);
    RETURN((frag[0][0] == 'S' && len != 2) || (frag[0][0] == 'A' && len != 6),
        false);
    RETURN(len == 2, true);
    RETURN(!my_isint(frag[3]) || !my_isint(frag[4]) || !my_isbool(frag[5]), 0);
    tmp = my_strsplit(frag[2], 'x');
    extlen = my_walen(tmp);
    DOIF(extlen == 1 || !my_isint(tmp[0]) || !my_isint(tmp[1]), EQ2(valid, 0));
    my_watroy(tmp);
    return (valid);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Parses the metadata of a prop from its fragments.
///
/// \param prop Pointer to the prop_t structure to store metadata.
/// \param frag An array containing fragments of the prop name.
/// \param len The number of fragments in the array.
///
/// This function parses the metadata of a prop based on its fragments. It sets
/// the prop type, name, and other properties such as animation details if
/// applicable.
///
///////////////////////////////////////////////////////////////////////////////
static void parse_prop_metadata(prop_t *prop, warray frag, ulong len)
{
    warray ext = my_strsplit(frag[len - 1], '.');
    warray tmp;

    prop->type = frag[0][0] == 'S' ? props_animated : props_static;
    prop->name = my_strdup(len == 2 ? ext[0] : frag[1]);
    if (len != 2) {
        prop->animated = true;
        tmp = my_strsplit(frag[2], 'x');
        prop->anim.autoplay = my_atob(ext[0]);
        prop->anim.frameSize = VEC2U(my_atoi(tmp[0]), my_atoi(tmp[1]));
        prop->anim.gridWidth = my_atoi(frag[3]);
        prop->anim.gridHeight = my_atob(frag[4]);
        my_watroy(tmp);
        prop->mask = (recti){0, 0, prop->anim.gridWidth,
            prop->anim.gridHeight};
    }
    my_watroy(ext);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initializes a prop with the specified parent path and name.
///
/// \param prop         Pointer to the prop_t structure to be initialized.
/// \param parentPath   The parent path of the prop.
/// \param name         The name of the prop.
///
/// \return The status of the initialization process (success or failure).
///
///////////////////////////////////////////////////////////////////////////////
status prop_init(prop_t *prop, cstring parentPath, string name)
{
    warray frag;

    RETURN(prop == NULL, fail);
    frag = my_strsplit(name, '-');
    RETURN(frag == NULL, fail);
    prop->valid = is_prop_name_valid(frag);
    prop->filepath = my_strdcat(parentPath, "/", name);
    prop->animated = false;
    prop->textureSize = VEC2U(0, 0);
    FREE(name);
    prop->text = NULL;
    DOIF(!prop->valid, my_watroy(frag));
    RETURN(!prop->valid, fail);
    parse_prop_metadata(prop, frag, my_walen(frag));
    my_watroy(frag);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroys a prop and releases associated resources.
///
/// \param prop Pointer to the prop_t structure to be destroyed.
///
/// \return The status of the destruction process (success or failure).
///
///////////////////////////////////////////////////////////////////////////////
status prop_destroy(prop_t *prop)
{
    RETURN(prop == NULL, success);
    FREE(prop->filepath);
    FREE(prop->name);
    FREE(prop);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Unloads a prop.
///
/// \param prop Pointer to the prop_t structure to be unloaded.
///
/// \return The status of the unloading process (success or failure).
///
/// This function unloads a prop.
///
///////////////////////////////////////////////////////////////////////////////
status prop_unload(prop_t *prop)
{
    RETURN(prop == NULL || !prop->valid, success);
    RETURN(prop->text == NULL, success);
    sfTexture_destroy(prop->text);
    prop->textureSize = VEC2U(0, 0);
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Loads a prop.
///
/// \param prop Pointer to the prop_t structure to be loaded.
///
/// \return The status of the loading process (success or failure).
///
/// This function loads a prop.
///
///////////////////////////////////////////////////////////////////////////////
status prop_load(prop_t *prop)
{
    RETURN(prop == NULL || !prop->valid, success);
    prop->text = sfTexture_createFromFile(prop->filepath, NULL);
    RETURN(prop->text == NULL, fail);
    prop->textureSize = sfTexture_getSize(prop->text);
    return (success);
}
