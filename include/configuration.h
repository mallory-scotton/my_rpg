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

    #define VIEW_WIDTH 512
    #define VIEW_HEIGHT 288

    #define ACTOR_FRAME_PER_SEC 9
    #define PROP_FRAME_PER_SEC 5
    #define ACTOR_FRAME_PER_MS (1000 / ACTOR_FRAME_PER_SEC)
    #define PROP_FRAME_PER_MS (1000 / PROP_FRAME_PER_SEC)

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// ASSETS CONFIGURATION

    // DEFAULT ASSETS LOCATION
    #define ASSETS_PATH "assets/"

    // DEFAULT DATA LOCATION
    #define DATA_PATH (ASSETS_PATH "data")

    // ZONES LOCATION
    #define ZONE_PATH (ASSETS_PATH "zones")

    // FONT LOCATION
    #define FONT_PATH (ASSETS_PATH "font-atlas.png")
    #define FONT_LOWERED_CHAR "gjpqyJQ"

    // RESERVED KEYWORDS DIRECTORY
    #define TRAPS_DIR "traps"
    #define VFX_DIR "vfx"
    #define DESTRUCTIBLES_DIR "destructibles"

    #define MAX_ZONE 16
    #define MAX_CATEGORY 16
    #define MAX_ASSETS 128

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
// MEMORY CONFIGURATION
// /!\ CHANGING THE CONFIGURATION WILL CAUSE ISSUE WITH ALREADY SAVED MAP

    // BITS USED FOR ZONES (2^x) ==> [16]
    #define BITS_ZONES 4

    // BITS USED FOR CATEGORY (2^x) ==> [16]
    #define BITS_CATEGORY 4

    // BITS USED FOR ASSETS (2^x) ==> [128]
    #define BITS_ASSETS 7

    // BITS USED FOR PUTTING ASSETS BEHIND (2^x) ==> [1] == boolean
    #define BITS_IS_BACKGROUND 1

    // CHUNKS SIZE
    #define CHUNK_SIZE 8

    // BITS USED FOR CHUNKS (2^x) ==> [128]
    #define BITS_CHUNK 7

    // THE CHUNK USED FOR ASSETS NOT IN CHUNK
    #define RESTRICTED_CHUNK 127

    // BITS USED FOR POSITIONS (2^x) ==> [256]
    #define BITS_POSITION 8

    // BITS USED FOR DESCRIPTION THE AREA TYPE (2^x) ==> [8]
    #define BITS_AREA_TYPE 3

    // BITS USED FOR AREA SIZE (2^x) ==> [2048]
    #define BITS_AREA_SIZE 11

    // MACRO TO CONVERT BIT TO BYTE
    #define BITTOBYTE(value) ((int)((value) / 8 + 1))

///////////////////////////////////////////////////////////////////////////////

#endif /* !CONFIGURATION_H_ */
