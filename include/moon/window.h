/*
** EPITECH PROJECT, 2024
** csfml-engine
** File description:
** window
*/

#ifndef WINDOW_H_
    #define WINDOW_H_

///////////////////////////////////////////////////////////////////////////////
// Headers
///////////////////////////////////////////////////////////////////////////////
    #include "moon.h"

///////////////////////////////////////////////////////////////////////////////
//
// PARAMETERS
//
///////////////////////////////////////////////////////////////////////////////

    /** Mode for the window: 'fullscreen', 'borderless', 'windowed'.         */
    #define WIN_FULLSCREEN (sfFullscreen | sfResize)
    #define WIN_BORDERLESS (sfNone)
    #define WIN_WINDOWED (sfTitlebar | sfClose)

///////////////////////////////////////////////////////////////////////////////
//
// CONFIGURATION
//
///////////////////////////////////////////////////////////////////////////////

    /** Default window size                                                  */
    #define DEFAULT_WIDTH 1920
    #define DEFAULT_HEIGHT 1080
    /** View settings                                                        */
    #define DEFAULT_VIEW_WIDTH 480.0f
    #define DEFAULT_VIEW_HEIGHT 270.0f
    /** Window color bits                                                    */
    #define DEFAULT_BITS 32
    /** Framerate limit                                                      */
    #define DEFAULT_FPS 60
    /** Window default mode: 'fullscreen'                                    */
    #define DEFAULT_MODE WIN_FULLSCREEN
    /** Window configuration                                                 */
    #define DEFAULT_TITLE "AK-XOLOTL"
    #define DEFAULT_ICON "game-icon.png"
    /** Default keybinds                                                     */
    #define DEFAULT_KEY_UP sfKeyZ
    #define DEFAULT_KEY_DOWN sfKeyS
    #define DEFAULT_KEY_RIGHT sfKeyQ
    #define DEFAULT_KEY_LEFT sfKeyD
    #define DEFAULT_KEY_RELOAD sfKeyR
    #define DEFAULT_KEY_HEAL sfKeyA
    #define DEFAULT_KEY_DASH sfKeySpace
    #define DEFAULT_KEY_INTERACT sfKeyE
    #define DEFAULT_KEY_PAUSE sfKeyEscape
    #define DEFAULT_KEY_SHOOT sfMouseLeft
    #define DEFAULT_KEY_DANCE sfKeyC
    #define DEFAULT_KEY_INVENTORY sfKeyI
    /** Alternative keybinds                                                 */
    #define ALT_UP sfKeyUp
    #define ALT_DOWN sfKeyDown
    #define ALT_RIGHT sfKeyRight
    #define ALT_LEFT sfKeyLeft

///////////////////////////////////////////////////////////////////////////////
///
/// SHORTENERS
///
///////////////////////////////////////////////////////////////////////////////

    #define UP Setting.up.pressed
    #define DOWN Setting.down.pressed
    #define RIGHT Setting.right.pressed
    #define LEFT Setting.left.pressed
    #define DASH Setting.dash.pressed
    #define DANCE Setting.dance.pressed
    #define HEAL Setting.heal.pressed
    #define MOVE (UP || DOWN || RIGHT || LEFT)
    #define SPEED 16.5f
    #define HOVER Setting.hover

    #define SHAKE Setting.shake
    #define BLOOD Setting.blood
    #define INVERT Setting.invert
    #define CLICK_REL Setting.release
    #define KEY_REL Setting.keylease
    #define WIN_MODES Setting.winMode
    #define FRAMERATE Setting.framerate
    #define AIMING Setting.aiming

///////////////////////////////////////////////////////////////////////////////
//
// STRUCTURES
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \brief Time instance for the game
///
/// \param deltaTime    Delta time spend between the render of two frames
/// \param currentTime  The current time of the process, start at 0
/// \param clock        The clock element to keep track of the time
///
///////////////////////////////////////////////////////////////////////////////
extern struct window_time_s {
    double deltaTime;
    u32_t currentTime;
    sfClock *clock;
} Time;

///////////////////////////////////////////////////////////////////////////////
/// \brief Window references structure, handle mode/parameters and view
///
/// \param view         The 'camera' of the game
/// \param self         Reference to the window element
/// \param width        The width of the window 'DEFAULT_WIDTH' by default
/// \param height       The height of the window 'DEFAULT_HEIGHT' by default
/// \param mode         The window mode's: 'fullscreen', 'borderless',
///                     'windowed'
///
///////////////////////////////////////////////////////////////////////////////
extern struct window_reference_s {
    sfView *view;
    sfRenderWindow *self;
    uint_t width;
    uint_t height;
    float viewWidth;
    float viewHeight;
    int mode;
} Win;

///////////////////////////////////////////////////////////////////////////////
/// \brief Structure of a key to keep track of his statet
///
/// \param code         The key code to keep track of
/// \param pressed      The state of the key
///
///////////////////////////////////////////////////////////////////////////////
typedef struct key_track_s {
    sfKeyCode code;
    bool_t pressed;
} key_track_t;

///////////////////////////////////////////////////////////////////////////////
/// \brief setting structure to keep settings
///
/// \param up           Key for deplacement to direction: Up
/// \param down         Key for deplacement to direction: Down
/// \param right        Key for deplacement to direction: Rigth
/// \param left         Key for deplacement to direction: Left
/// \param reload       Key for reloading the weapon
/// \param heal         Key for healing
/// \param dash         Key for dashing
/// \param interact     Key for interacting with objects
/// \param pause        Key for pausing the game
/// \param shoot        Mouse key for shooting the weapon
///
///////////////////////////////////////////////////////////////////////////////
extern struct keybind_s {
    key_track_t up;
    key_track_t down;
    key_track_t right;
    key_track_t left;
    key_track_t reload;
    key_track_t heal;
    key_track_t dash;
    key_track_t interact;
    key_track_t pause;
    key_track_t dance;
    sfMouseButton shoot;
    bool_t hover;
    float master;
    float music;
    float sound;
    const sfVideoMode *modes;
    ulong_t modesCunt;
    uint_t winMode;
    uint_t framerate;
    bool_t shake;
    bool_t blood;
    uint_t aiming;
    bool_t invert;
    float sensibilit;
    bool_t release;
    int last_scene;
    int wasHover;
    key_track_t inventory;
    bool_t keylease;
    bool_t healtuto;
    bool_t dashtuto;
} Setting;

///////////////////////////////////////////////////////////////////////////////
//
// FUNCTIONS
//
///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
/// \brief Create a new window width the wanted parameters
///
/// \param width        The width of the window (if 0, default value)
/// \param height       The height of the window (if 0, default value)
/// \param mode         Window mode: 'fullscreen', 'borderless', 'windowed'
///
/// \return Boolean, true if the creation was successful, false otherwise
///
///////////////////////////////////////////////////////////////////////////////
bool_t create_window(uint_t width, uint_t height, int mode);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the window and view from the Win structure
///
///////////////////////////////////////////////////////////////////////////////
void destroy_window(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Initialize the global Time variable, and all the components linked
///
/// \return The status of the operation, if the operation fail, stop the game
/// engine.
///
///////////////////////////////////////////////////////////////////////////////
bool_t init_time(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Update the Time variable
///
/// This function need to be executed at the start of each frame for the
/// calculation of the deltaTime.
///
/// \return The status of the operation, if the operation fail, it means that
/// the initialization failed, and need to leave the engine.
///
///////////////////////////////////////////////////////////////////////////////
bool_t update_time(void);

///////////////////////////////////////////////////////////////////////////////
/// \brief Destroy the variable and clean the used ressources
///
/// This function will free the memory and destroy the clock to clean
/// the used ressources.
///
///////////////////////////////////////////////////////////////////////////////
void destroy_time(void);

#endif /* !WINDOW_H_ */
