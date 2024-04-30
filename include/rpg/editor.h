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
    #define WHITE sfWhite

///////////////////////////////////////////////////////////////////////////////
/// \brief Sizing
///
///////////////////////////////////////////////////////////////////////////////
    #define EDITOR_PANEL_W 250.0f
    #define EDITOR_PANEL_H 42.0f

///////////////////////////////////////////////////////////////////////////////
/// \brief Constants
///
///////////////////////////////////////////////////////////////////////////////
    #define MAX_CONTEXT_ITEMS 8
    #define CONTEXT_COUNT 6

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
/// \brief Structure to create context menu item
///
/// \param text         The text of the button item
/// \param onClick      The function to execute on click
/// \param disabled     Is the button disabled or not
/// \param subText      The subText of this button
///
///////////////////////////////////////////////////////////////////////////////
typedef struct context_item_s {
    cstring_t text;
    void (*onClick)(void);
    bool_t disabled;
    cstring_t subText;
} context_item_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure to create context menu
///
/// \param text         The text of the context button
/// \param expand       The status of the context menu
/// \param items        The list of item in the context
/// \param itemCount    The number of item in the context
///
///////////////////////////////////////////////////////////////////////////////
typedef struct context_s {
    cstring_t text;
    bool_t expand;
    context_item_t items[MAX_CONTEXT_ITEMS];
    uint_t itemCount;
} context_t;

///////////////////////////////////////////////////////////////////////////////
extern context_t CONTEXTS[CONTEXT_COUNT];

///////////////////////////////////////////////////////////////////////////////
/// \brief Hold the type of input
///
///////////////////////////////////////////////////////////////////////////////
typedef enum input_type_e {
    INPUT_TEXT,
    INPUT_INTEGER,
    INPUT_FLOAT,
    INPUT_CHECKBOX,
    INPUT_BUTTON,
    INPUT_TYPE_COUNT
} input_type_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief List of the editor inputs
///
///////////////////////////////////////////////////////////////////////////////
enum input_editor_e {
    EDITOR_INPUT_X,
    EDITOR_INPUT_Y,
    EDITOR_INPUT_COLLISION,
    EDITOR_INPUT_FLIP,
    EDITOR_INPUT_FORE,
    EDITOR_INPUT_BACK,
    EDITOR_INPUT_DOWN,
    EDITOR_INPUT_UP,
    EDITOR_INPUT_ADOWN,
    EDITOR_INPUT_AUP,
    EDITOR_INPUT_FRAME,
    EDITOR_INPUT_PREVIOUS,
    EDITOR_INPUT_NEXT,
    EDITOR_INPUT_COUNT
};

///////////////////////////////////////////////////////////////////////////////
/// \brief The structure to hold inputs
///
/// \param type         The type of input
/// \param focused      The focused status of the input
/// \param maxLength    The maximum length of the input
/// \param length       The current length of the input
/// \param content      The content of the input
/// \param position     The position of the input
/// \param size         The size of the input
/// \param placeholder  The placeholder text of the input
/// \param onInput      This function is fired at every input
/// \param range        The range of the input (type float/int)
/// \param checked      The check status (type checkbox)
/// \param disabled     Allows to disable an input
/// \param cActive      The color of the input when active
/// \param cHover       The color of the input when hovered
/// \param cDisabled    The color of the input when disabled;
///
///////////////////////////////////////////////////////////////////////////////
typedef struct input_s {
    input_type_t type;
    bool_t focused;
    uint_t maxLength;
    uint_t length;
    string_t content;
    v2f_t position;
    v2f_t size;
    cstring_t placeholder;
    void (*onInput)(struct input_s *input);
    int range[2];
    bool_t checked;
    bool_t disabled;
    sfColor cActive;
    sfColor cHover;
    sfColor cDisabled;
    bool_t draw;
} input_t;

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
/// \param hover        Is the focused p    draw_context_buttons("Quit")
/// \param dragging     Is the user currently dragging
/// \param zoneId       The id of the zone
/// \param zone         The zone pointer
/// \param oldMouse     The old mouse position
/// \param crtMouse     The current mouse position
/// \param scollingOffset The scrolling offset for the browser
/// \param released     Is the mouse button released
/// \param inputFocused The current focused input
/// \param inputs       The list of inputs
/// \param inputCount   The number of input
/// \param copyScale    The copy holder for the scale
/// \param copyCollide  The copy holder for collision
/// \param copyData     The copy holder for data
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
    input_t *inputFocused;
    input_t **inputs;
    uint_t inputCount;
    float copyScale;
    bool_t copyCollide;
    int copyData[4];
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
///////////////////////////////////////////////////////////////////////////////
void search_for_focus(void);

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
///////////////////////////////////////////////////////////////////////////////
void handle_editor_mouse_released(void);

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
/// \brief Handle the keyboard pressed event on input
///
/// \param evt          The key event to handle
///
///////////////////////////////////////////////////////////////////////////////
void handle_editor_key_input(sfKeyEvent evt);

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

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw a text at a specific point
///
/// \param str          The string to draw
/// \param pos          The position of the string
/// \param scale        The scale of the string
/// \param color        The color to add
///
///////////////////////////////////////////////////////////////////////////////
void draw_text(cstring_t str, v2f_t pos, float scale, sfColor color);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the editor bottom bar with every information
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_bottom_bar(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the editor context menu
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_context_menu(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Copy the current focused prop to the clipboard
///
///////////////////////////////////////////////////////////////////////////////
void editor_copy(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Paste the current copied prop
///
///////////////////////////////////////////////////////////////////////////////
void editor_paste(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Copy and delete the current focused prop to the clipboard
///
///////////////////////////////////////////////////////////////////////////////
void editor_cut(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Duplicate the current focused prop
///
///////////////////////////////////////////////////////////////////////////////
void editor_duplicate(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Delete the current focused prop
///
///////////////////////////////////////////////////////////////////////////////
void editor_delete(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Switch the viewing of the background
///
///////////////////////////////////////////////////////////////////////////////
void editor_switch_background(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Switch the viewing of the foreground
///
///////////////////////////////////////////////////////////////////////////////
void editor_switch_foreground(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Hide the context menu of the editor
///
///////////////////////////////////////////////////////////////////////////////
void editor_hide_context(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Clear all the props of the editor
///
///////////////////////////////////////////////////////////////////////////////
void editor_clear(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Reset all the value of the editor
///
///////////////////////////////////////////////////////////////////////////////
void editor_reset(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Set the editor to the canvas origin
///
///////////////////////////////////////////////////////////////////////////////
void editor_to_origin(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Leave the editor and return to the main menu
///
///////////////////////////////////////////////////////////////////////////////
void editor_return_menu(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Zoom out the canvas
///
///////////////////////////////////////////////////////////////////////////////
void editor_zoom_out(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Zoom in the canvas
///
///////////////////////////////////////////////////////////////////////////////
void editor_zoom_in(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw an input on the wanted pos and size
///
/// \param input        The input to draw
///
///////////////////////////////////////////////////////////////////////////////
void editor_draw_input(input_t *input);

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a new input at a position on the screen
///
/// \param type         The type of input
/// \param position     The position of the input
/// \param size         The size of the input
/// \param text         The placeholder of the input
///
/// \return The newly created input
///
///////////////////////////////////////////////////////////////////////////////
input_t *create_input(input_type_t type, v2f_t position, v2f_t size,
    cstring_t text);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy an input
///
/// \param input        The input to destroy
///
///////////////////////////////////////////////////////////////////////////////
void destroy_input(input_t *input);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the settings part of the editor
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_settings(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Clear the content of an input
///
///////////////////////////////////////////////////////////////////////////////
void input_clear(input_t *input);

///////////////////////////////////////////////////////////////////////////////
/// \brief Update the float value of an input
///
///////////////////////////////////////////////////////////////////////////////
void input_updatef(input_t *input, float value);

///////////////////////////////////////////////////////////////////////////////
/// \brief Init the input of the editor
///
///////////////////////////////////////////////////////////////////////////////
void editor_settings_init_input(v2f_t pos);

///////////////////////////////////////////////////////////////////////////////
/// \brief Update the value of the inputs based on the current focused prop
///
///////////////////////////////////////////////////////////////////////////////
void input_focus_update(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw the toolbar of the editor
///
///////////////////////////////////////////////////////////////////////////////
void draw_editor_toolbar(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Move the current focused prop to the foreground
///
///////////////////////////////////////////////////////////////////////////////
void editor_to_foreground(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Move the current focused prop to the background
///
///////////////////////////////////////////////////////////////////////////////
void editor_to_background(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Move the current focused prop all the way under
///
///////////////////////////////////////////////////////////////////////////////
void editor_all_down(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Move the current focused prop all the way up
///
///////////////////////////////////////////////////////////////////////////////
void editor_all_up(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Move the current focused prop one up
///
///////////////////////////////////////////////////////////////////////////////
void editor_move_up(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Move the current focused prop one down
///
///////////////////////////////////////////////////////////////////////////////
void editor_move_down(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Find the stack and the index of the props
///
/// \param prop         Pointer to the wanted prop
/// \param idx          Pointer to a variable holding the index
///
/// \return The stack containing the prop, or NULL
///
///////////////////////////////////////////////////////////////////////////////
prop_t **find_prop_stack(prop_t *prop, uint_t *idx);

#endif /* !EDITOR_H_ */
