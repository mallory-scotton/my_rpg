/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** engine
*/

#ifndef ENGINE_H_
    #define ENGINE_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "moon.h"

///////////////////////////////////////////////////////////////////////////////
// Constants
///////////////////////////////////////////////////////////////////////////////
    #define ASSETS "assets/"
    #undef EXIT_FAILURE
    #define EXIT_FAILURE 84

///////////////////////////////////////////////////////////////////////////////
/// \brief Scenes enumeration
///
///////////////////////////////////////////////////////////////////////////////
typedef enum scene_e {
    SCENE_MAIN_MENU,
    SCENE_LEVEL_EDITOR,
    SCENE_GAME,
    SCENE_SETTINGS,
    SCENE_VIDEO,
    SCENE_SAVES,
    SCENE_PAUSE,
    SCENE_INVENTORY,
    SCENE_MINIGAME,
    SCENE_COUNT
} scene_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to hold all the debug information
///
///////////////////////////////////////////////////////////////////////////////
typedef struct engine_debug_s {
    uint_t propDrawn;
    uint_t frameRate;
} engine_debug_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Engine main structures, store engine related parameters
///
/// \param debugMode    Should the game be debugging everything
///
///////////////////////////////////////////////////////////////////////////////
extern struct engine_s {
    bool_t debugMode;
    scene_t scene;
    sfTexture **frames;
    uint_t videoFrame;
    uint_t videoFrameCount;
    ulong_t time;
    sfSprite *sprite;
    warray_t content;
    uint_t frameLoaded;
    sfMusic *music;
    int colum;
    uint_t level;
    engine_debug_t debug;
    ulong_t fadeStart;
    uint_t saveId;
    ulong_t delta;
    ulong_t spent;
    uint_t axo_minigame;
    uint_t roll;
    int click;
} Engine;

#endif /* !ENGINE_H_ */
