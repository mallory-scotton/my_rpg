/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-mallory.scotton
** File description:
** editor
*/

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
#include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
struct editor_s Editor = {
    EDITOR_LAYER_BACKGROUND,
    EDITOR_SCENE_ZONE_SELECTION,
    NULL, 0, true,
    NULL, 0, true,
    NULL, NULL, false, false,
    -1, NULL,
    {0.0f, 0.0f}, {0.0f, 0.0f}, 0.0f, false,
    NULL, NULL, 0,
    0.0f, false, {0, 0, 0, 0},
    false, POPUP_SAVE,
    {0, 0, 0, 0}, {0, 0, 0, 0}
};
