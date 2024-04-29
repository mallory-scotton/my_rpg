/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-mallory.scotton
** File description:
** interfaces
*/

#ifndef INTERFACES_H_
    #define INTERFACES_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Loop for playing fullscreened video
///
///////////////////////////////////////////////////////////////////////////////
void video_loop(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Loop for the main menu
///
///////////////////////////////////////////////////////////////////////////////
void menu_loop(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Loop for the settings
///
///////////////////////////////////////////////////////////////////////////////
void settings_loop(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Load and Play a video
///
/// \param path         The path of the video
/// \param soundName    The audio of the video
///
///////////////////////////////////////////////////////////////////////////////
void load_video(cstring_t path, cstring_t soundName);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the background for the menu and settings
///
///////////////////////////////////////////////////////////////////////////////
void draw_menu_background(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the cursor for the main menu and the settings
///
///////////////////////////////////////////////////////////////////////////////
void draw_cursor(void);

void draw_text_right(cstring_t str, v2f_t pos, float scale, sfColor color);
void draw_text_center(cstring_t str, v2f_t pos, float scale, sfColor color);

#endif /* !INTERFACES_H_ */
