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

    #define ASSETS_PATH "assets/"
    #define ZONES_DIR "zones"

///////////////////////////////////////////////////////////////////////////////

#endif /* !CONFIGURATION_H_ */
