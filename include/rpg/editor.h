/*
** EPITECH PROJECT, 2024
** B-MUL-200-LYN-2-1-myrpg-mallory.scotton
** File description:
** editor
*/

#ifndef EDITOR_H_
    #define EDITOR_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "rpg.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Color palette
///
///////////////////////////////////////////////////////////////////////////////
    #define EDITOR_BACKGROUND RGB(37, 37, 37)
    #define EDITOR_WIDGET RGB(71, 71, 71)
    #define EDITOR_BUTTON RGB(53, 53, 53)
    #define EDITOR_HOVER EDITOR_BACKGROUND

///////////////////////////////////////////////////////////////////////////////
/// \brief Sizing
///
///////////////////////////////////////////////////////////////////////////////
    #define EDITOR_PANEL_W 250.0f
    #define EDITOR_PANEL_H 42.0f

///////////////////////////////////////////////////////////////////////////////
/// \brief Editor scene enumeration
///
///////////////////////////////////////////////////////////////////////////////
typedef enum editor_scene_e {
    EDITOR_SCENE_ZONE_SELECTION,
    EDITOR_SCENE_CREATION,
    EDITOR_SCENE_SAVING,
    EDITOR_SCENE_COUNT
} editor_scene_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Editor layers selection
///
///////////////////////////////////////////////////////////////////////////////
typedef enum editor_layer_e {
    EDITOR_LAYER_BACKGROUND,
    EDITOR_LAYER_FOREGROUND,
    EDITOR_LAYER_COUNT
} editor_layer_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Editor structure to keep every data needed for the level-editor
///
/// \param fProps       Props array of the foreground
/// \param fCount       The number of props in the foreground
/// \param fDisplay     Is the foreground displayed
/// \param bProps       Props array of the background
/// \param bcount       The number of props in the background
/// \param bDisplay     Is the background displayed
/// \param copy         The prop currently copied
/// \param focus        The prop currently focused
/// \param hover        Is the focused prop hovered
/// \param dragging     Is the user currently dragging the focused prop
/// \param zoneId       The current loaded zone id
/// \param zone         The current loaded zone pointer
/// \param oldMouse     The previous mouse position
/// \param crtMouse     The current mouse position
///
///////////////////////////////////////////////////////////////////////////////
extern struct editor_s {
    editor_layer_t layer;
    editor_scene_t scene;
    prop_t **fProps;
    uint_t fCount;
    bool_t fDisplay;
    prop_t **bProps;
    uint_t bCount;
    bool_t bDisplay;
    sheet_t *copy;
    prop_t *focus;
    bool_t hover;
    bool_t dragging;
    int zoneId;
    zone_t *zone;
    v2f_t oldMouse;
    v2f_t crtMouse;
    float scrollingOffset;
    bool_t released;
} Editor;

///////////////////////////////////////////////////////////////////////////////
/// \brief Main loop of the level editor
///
///////////////////////////////////////////////////////////////////////////////
void editor_loop(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handle all the events of the level editor windows
///
/// \param evt          The current event
///
///////////////////////////////////////////////////////////////////////////////
void handle_editor_events(sfEvent evt);

///////////////////////////////////////////////////////////////////////////////
/// \brief Create and add a new prop to the foreground or background layer
/// of the editor
///
/// \param sheet        The sheet reference to create the prop
/// \param array        The array of props (background/foreground)
/// \param count        The counter of props in the array
///
///////////////////////////////////////////////////////////////////////////////
void add_prop(sheet_t *sheet, prop_t ***array, uint_t *count);

///////////////////////////////////////////////////////////////////////////////
/// \brief Search in all the props to apply the focus
///
/// \param evt          The mouse button event
///
///////////////////////////////////////////////////////////////////////////////
void search_for_focus(sfMouseButtonEvent evt);

///////////////////////////////////////////////////////////////////////////////
/// \brief Search in a list of props if the mouse is on one of it
///
/// \param isDisplayed  Boolean is the layer displayed
/// \param propCount    The number of prop in the array of props
/// \param props        The array of props of one layer
///
/// \return True if the mouse is over a prop, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
bool_t search_in_props(bool_t isDisplayed, uint_t propCount, prop_t **props);

///////////////////////////////////////////////////////////////////////////////
/// \brief Get the prop boundary
///
/// \param prop         Pointer to the desired prop
///
/// \return The boundary of the prop
///
///////////////////////////////////////////////////////////////////////////////
recti_t get_prop_bound(prop_t *prop);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handle click on the level editor
///
/// \param evt          The mouse button event to parse
///
///////////////////////////////////////////////////////////////////////////////
void handle_editor_mouse_button(sfMouseButtonEvent evt);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handle mouse release on the level editor
///
/// \param evt          The mouse event to parse
///
///////////////////////////////////////////////////////////////////////////////
void handle_editor_mouse_released(sfMouseButtonEvent evt);

///////////////////////////////////////////////////////////////////////////////
/// \brief Parse and handle differents event when scrolling on the canvas.
/// Zoom or move on the canvas (ALT/CTRL)
///
/// \param evt          The mouse scroll event
///
///////////////////////////////////////////////////////////////////////////////
void handle_editor_mouse_scroll(sfMouseWheelScrollEvent evt);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handle the mouse movement on the windows
///
///////////////////////////////////////////////////////////////////////////////
void handle_mouse_move(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Handle the keyboard pressed/released event
///
/// \param evt          The key event to handle
///
///////////////////////////////////////////////////////////////////////////////
void handle_editor_key_pressed(sfKeyEvent evt);

///////////////////////////////////////////////////////////////////////////////
/// \brief Compile and save the current loaded level to the desired filepath
///
/// \param filepath     The file path to save the level
///
/// \return Ture if the level is saved, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
bool_t level_save(cstring_t filepath);

///////////////////////////////////////////////////////////////////////////////
/// \brief Load a level into the Editor values
///
/// \param filepath     The file path to load the level
///
/// \return True if the level is loaded, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
bool_t level_load(cstring_t filepath);

///////////////////////////////////////////////////////////////////////////////
/// \brief Remove a prop from an array
///
/// \param prop         The prop to remove
/// \param array        Pointer to the array of props
/// \param count        Pointer to the prop counter
///
///////////////////////////////////////////////////////////////////////////////
void remove_prop(prop_t *prop, prop_t ***array, uint_t *count);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the UI of the level Editor
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_ui(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the current focused prop hitbox
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_focus_hitbox(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the editor map borders
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_map_border(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw a rectangle based on the screen size and position and not
/// on the view sizing and coordinate system
///
/// \param size         The size of the rectangle
/// \param pos          The position of the rectangle
/// \param color        The color of the rectangle
///
///////////////////////////////////////////////////////////////////////////////
void draw_rect(v2f_t size, v2f_t pos, sfColor color);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the assets browser of the level editor
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_browser(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Check if a cursor is on a part of the screen
///
/// \param position     The position of the rectangle hitbox
/// \param size         The size of the hitbox
///
/// \return True if the cursor is in, False otherwise
///
///////////////////////////////////////////////////////////////////////////////
bool_t cursor_inbound(v2f_t position, v2f_t size);

#endif /* !EDITOR_H_ */
