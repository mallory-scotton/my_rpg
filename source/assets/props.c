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
    prop->name = name;
    prop->filepath = my_strdcat(parentPath, "/", name);
    prop->text = NULL;
    DOIF(!prop->valid, my_watroy(frag));
    RETURN(!prop->valid, fail);
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
    DOIF(prop->text != NULL, sfTexture_destroy(prop->text));
    FREE(prop);
    return (success);
}
