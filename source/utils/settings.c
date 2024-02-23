/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** settings
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Pointer to global settings.
///
/// This extern variable is a pointer to the global settings structure.
///
///////////////////////////////////////////////////////////////////////////////
global_settings_t *Settings;

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize keybindings with default values.
///
/// This function allocates memory for the keybind structure in the settings,
/// sets the keybindings to their default values, and returns the status of the
/// initialization.
///
/// \return Success if initialization is successful, fail otherwise.
///
///////////////////////////////////////////////////////////////////////////////
static status keybind_init(void)
{
    Settings->keybind = malloc(sizeof(keybind_t));
    RETURN(Settings->keybind == NULL, fail);
    Settings->keybind->up = DEFAULT_KEY_UP;
    Settings->keybind->down = DEFAULT_KEY_DOWN;
    Settings->keybind->right = DEFAULT_KEY_RIGHT;
    Settings->keybind->left = DEFAULT_KEY_LEFT;
    Settings->keybind->reload = DEFAULT_KEY_RELOAD;
    Settings->keybind->heal = DEFAULT_KEY_HEAL;
    Settings->keybind->dash = DEFAULT_KEY_DASH;
    Settings->keybind->interact = DEFAULT_KEY_INTERACT;
    Settings->keybind->pause = DEFAULT_KEY_PAUSE;
    Settings->keybind->shoot = DEFAULT_MOUSE_SHOOT;
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize global settings.
///
/// \return success on successful initialization, fail otherwise.
///
///////////////////////////////////////////////////////////////////////////////
status settings_init(void)
{
    Settings = malloc(sizeof(global_settings_t));
    RETURN(Settings == NULL, fail);
    if (keybind_init() == fail) {
        FREE(Settings);
        return (fail);
    }
    return (success);
}

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy global settings.
///
///////////////////////////////////////////////////////////////////////////////
void settings_destroy(void)
{
    RETURN(Settings == NULL, (void)0);
    DOIF(Settings->keybind != NULL, FREE(Settings->keybind));
    FREE(Settings);
}
