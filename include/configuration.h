/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** configuration
*/

#ifndef CONFIGURATION_H_
    #define CONFIGURATION_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg/types.h"
    #include "rpg/dependencies.h"

///////////////////////////////////////////////////////////////////////////////
// KEYBIND CONFIGURATION

    #define ALT_UP sfKeyUp
    #define ALT_DOWN sfKeyDown
    #define ALT_RIGHT sfKeyRight
    #define ALT_LEFT sfKeyLeft

    #define DEFAULT_KEY_UP sfKeyW
    #define DEFAULT_KEY_DOWN sfKeyS
    #define DEFAULT_KEY_RIGHT sfKeyD
    #define DEFAULT_KEY_LEFT sfKeyA
    #define DEFAULT_KEY_RELOAD sfKeyR
    #define DEFAULT_KEY_HEAL sfKeyQ
    #define DEFAULT_KEY_DASH sfKeySpace
    #define DEFAULT_KEY_INTERACT sfKeyE
    #define DEFAULT_KEY_PAUSE sfKeyEscape
    #define DEFAULT_MOUSE_SHOOT sfMouseLeft

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// WINDOW CONFIGURATION

    #define WIN_WIDTH 1920
    #define WIN_HEIGHT 1080
    #define WIN_BITS 32
    #define WIN_MODE ((sfVideoMode){WIN_WIDTH, WIN_HEIGHT, WIN_BITS})
    #define WIN_STYLE (sfResize | sfClose)
    #define WIN_TITLE "AK-XOLOTL"
    #define WIN_FPS 60
    #define WIN_CENTERED true
    #define WIN_ICON (ASSETS_PATH "icon.png")

    #define WIN_MIN_WIDTH 800
    #define WIN_MIN_HEIGHT 600
    #define WIN_MAX_WIDTH 1920
    #define WIN_MAX_HEIGHT 1080

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ASSETS CONFIGURATION

    // DEFAULT ASSETS LOCATION
    #define ASSETS_PATH "assets/"

    // ZONES LOCATION
    #define ZONES_DIR "zones"

    // RESERVED KEYWORDS DIRECTORY
    #define TRAPS_DIR "traps"
    #define VFX_DIR "vfx"
    #define DESTRUCTIBLES_DIR "destructibles"

///////////////////////////////////////////////////////////////////////////////

#endif /* !CONFIGURATION_H_ */
